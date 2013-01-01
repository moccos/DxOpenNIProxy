// DxOpenNIProxy.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。

#include "stdafx.h"
#include <d3d9.h>
#include <d3dx9.h>
#include <string>
#include <fstream>
#include <map>
#include <locale.h>
#include "DxOpenNIDll.h"

// export functions 1.20
__declspec(dllexport) bool __stdcall OpenNIInit(HWND,bool,LPDIRECT3DDEVICE9,WCHAR*,CHAR*);
// __declspec(dllexport) bool __stdcall OpenNIInit(HWND,bool,LPDIRECT3DDEVICE9,WCHAR*);  // 1.10
__declspec(dllexport) void __stdcall OpenNIClean();
__declspec(dllexport) void __stdcall OpenNIDrawDepthMap(bool);
__declspec(dllexport) void __stdcall OpenNIDepthTexture(IDirect3DTexture9**);
__declspec(dllexport) void __stdcall OpenNIGetSkeltonJointPosition(int,D3DXVECTOR3*);
__declspec(dllexport) void __stdcall OpenNIIsTracking(bool*);
__declspec(dllexport) void __stdcall OpenNIGetVersion(float*);

// function pointer
DxOpenNIDllBase	*Dll;

// typedef for STL
typedef std::pair<std::string, std::string> strPair;

// global
HINSTANCE hInstanceDll;
HMODULE hModule;
std::map<std::string, std::string> dllMap;
std::wstring filename;

// Dialog Item
enum {
	DLG_OK = 1,
	DLG_CANCEL = 2,
	DLG_COMBOBOX = 51,
	DLG_ADD = 61,
	DLG_DELETE = 62,
};

// const
static const int bufsize = 128;

// internal function
BOOL CALLBACK Dlg1Proc(HWND hDlg, UINT msg, WPARAM wp, LPARAM lp);

// DllMain
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch( fdwReason )
	{
	case DLL_PROCESS_ATTACH:
		hInstanceDll = hinstDLL;
		break;

	case DLL_PROCESS_DETACH:
		OpenNIClean();
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;
	}

	return TRUE;
}

// internal function
BOOL CALLBACK Dlg1Proc(HWND hDlg, UINT msg, WPARAM wp, LPARAM lp)
{
	static HWND hCombo;
	std::string str;
	std::map<std::string, std::string>::iterator it;
	WCHAR wbuf[bufsize];
	int index;

	switch (msg){
	case WM_INITDIALOG:
		hCombo = GetDlgItem(hDlg, DLG_COMBOBOX);
		EnableWindow(GetDlgItem(hDlg, DLG_ADD), false);
		EnableWindow(GetDlgItem(hDlg, DLG_DELETE), false);
		it = dllMap.begin();
		while(it != dllMap.end()) {
			str = it->first.c_str();
			mbstowcs_s(NULL, wbuf, str.c_str(), bufsize);
			SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)wbuf);
			it++;
		}
		SendMessage(hCombo, CB_SETCURSEL, (WPARAM)0, 0);
		break;
	case WM_COMMAND:
		switch (LOWORD(wp)){
		case DLG_OK:
			index = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
			SendMessage(hCombo, CB_GETLBTEXT, (WPARAM)index, (LPARAM)wbuf);
			filename = wbuf;
			EndDialog(hDlg, DLG_OK);
			break;
		case DLG_CANCEL:
			EndDialog(hDlg, DLG_CANCEL);
			break;
		case DLG_COMBOBOX:
			break;
		case DLG_ADD:
		case DLG_DELETE:
			break;
		}
		break;
	}
	return FALSE;
}

// EXPORT FUNCTION:Init()
__declspec(dllexport) bool __stdcall OpenNIInit(HWND hWnd,bool EngFlag,LPDIRECT3DDEVICE9 lpDevice,WCHAR* f_path, CHAR* onifilename)
{
	std::string	 line;
	std::fstream inifile;

	SetCurrentDirectory(f_path);

	// .ini file
	inifile.open("Data/DxOpenNIProxy.ini", std::ios::in | std::ios::out);
	if (inifile.fail()) {
		// XXX file not found
		MessageBox(hWnd, L"DxOpenNIProxy.ini not found.", L"File open error", MB_OK);
		return false;
	} else {
		int pos_split;
		std::string name, flag;
		while (std::getline(inifile, line)) {
			pos_split = line.find_first_of("\t");
			if (pos_split == std::string::npos) continue;
			name = line.substr(0, pos_split);
			flag = line.substr(pos_split + 1);
			if (name.length() > 1) {
				dllMap.insert(strPair(name, flag));
				if (flag.find("*", 0) != std::string::npos) {
					WCHAR wbuf[bufsize];
					mbstowcs_s(NULL, wbuf, name.c_str(), bufsize);
					filename = wbuf;
				}
			}
		}
	}
	inifile.close();

	// create dialog
	if (filename.empty() || GetKeyState(VK_SHIFT) < 0) {
		int ret;
		ret = DialogBox(hInstanceDll, (LPCWSTR)1, hWnd, Dlg1Proc);
		switch (ret) {
		case DLG_CANCEL:
			return false;
		case -1:  // failed?
			MessageBox(hWnd, L"Dialog Error.", L"Dialog error", MB_OK);
			return false;
		default:
			break;
		}
	}

	// load DLL
	float ver = NULL;
	HMODULE hModule;

	if ((hModule = DxOpenNIDllBase::LoadDll(filename.c_str(), &ver)) == NULL) return false;
	if (ver == 1.30f) {
		Dll = new DxOpenNIDll130(hModule);
  }else if (ver == 1.20f) {
		Dll = new DxOpenNIDll120(hModule);
	} else if (ver == 1.10f) {
		Dll = new DxOpenNIDll110(hModule);
	} else {  // !?
		MessageBox(hWnd, L"unknown version", L"Dll Load", MB_OK);
		goto error_return;
	}

	if (Dll->LoadFunc() != DxOpenNIDllBase::NO_ERR) {
		MessageBox(hWnd, L"Function Load Error", L"Dll Load", MB_OK);
		Dll->Clean();
		return false;
	}

	return Dll->Init(hWnd, EngFlag, lpDevice, f_path, onifilename);

error_return:
	FreeLibrary(hModule);
	return false;
}

// EXPORT FUNCTION:Clean()
__declspec(dllexport) void __stdcall OpenNIClean()
{
	if (Dll!= NULL) {
		Dll->Clean();
		delete(Dll);
		Dll = NULL;
	}
}

// EXPORT FUNCTION:DrawDepthMap()
__declspec(dllexport) void __stdcall OpenNIDrawDepthMap(bool waitflag)
{
	Dll->DrawDepthMap(waitflag);
}

// DepthTexture()
__declspec(dllexport) void __stdcall OpenNIDepthTexture(IDirect3DTexture9** lpTex)
{
	Dll->DepthTexture(lpTex);
}

// GetSkeltonJointPosition()
__declspec(dllexport) void __stdcall OpenNIGetSkeltonJointPosition(int num,D3DXVECTOR3* vec)
{
	Dll->GetSkeltonJointPosition(num, vec);
}

// IsTracking()
__declspec(dllexport) void __stdcall OpenNIIsTracking(bool* lpb)
{
	Dll->IsTracking(lpb);
}

// GetVersion()
__declspec(dllexport) void __stdcall OpenNIGetVersion(float* ver)
{
	//pfnGetVersion(ver);  // XXX Init before here?
	*ver = 1.30f;
}
