#include "stdafx.h"
#include "DxOpenNIDll.h"
#include <string>

const float DxOpenNIDllBase::invalidY = -999.0f;

HMODULE DxOpenNIDllBase::LoadDll(const WCHAR* path, float *ver) {
	typedef void (__stdcall *fnGetVersion)(float*);
	fnGetVersion	pfnGetVersion;
	std::wstring filename(path);
	HMODULE hModule;

	filename.insert(0, L"Data/DxOpenNIProxy/");
	hModule = LoadLibrary(filename.c_str());
	if (hModule == NULL) return NULL;

	pfnGetVersion = (fnGetVersion)GetProcAddress(hModule, (LPCSTR)5);
	if (pfnGetVersion == NULL) {
		FreeLibrary(hModule);
		return NULL;
	}
	pfnGetVersion(ver);

	return hModule;
}

DxOpenNIDllBase::~DxOpenNIDllBase() {
	if (hModule_ != NULL) FreeLibrary(hModule_);
}

//=============== version 1.30 =======================
DxOpenNIDll130::DxOpenNIDll130(HMODULE module) {
	hModule_ = module;
}

void DxOpenNIDll130::Clean(void) {
	if (hModule_ != NULL) {
		pfnClean();
		FreeLibrary(hModule_);
		hModule_ = NULL;
	}
}

void DxOpenNIDll130::DrawDepthMap(bool waitflag) {
	pfnDrawDepthMap(waitflag);
}

void DxOpenNIDll130::DepthTexture(IDirect3DTexture9** lpTex) {
	pfnDepthTexture(lpTex);
}

void DxOpenNIDll130::GetSkeltonJointPosition(int num, D3DXVECTOR3* vec) {
  pfnGetSkeltonJointPosition(num, vec);
}

bool DxOpenNIDll130::Init(HWND hWnd, bool EngFlag, LPDIRECT3DDEVICE9 lpDevice, WCHAR* f_path, CHAR* onifilename) {
	return pfnInit(hWnd, EngFlag, lpDevice, f_path, onifilename);
}

void DxOpenNIDll130::IsTracking(bool* lpb) {
	pfnIsTracking(lpb);
}

int DxOpenNIDll130::LoadFunc(void) {
	if (hModule_ == NULL) return ERR_MODULE_NULL;
	pfnClean = (fnClean)GetProcAddress(hModule_, (LPCSTR)1);
	pfnDepthTexture = (fnDepthTexture)GetProcAddress(hModule_, (LPCSTR)2);
	pfnDrawDepthMap = (fnDrawDepthMap)GetProcAddress(hModule_, (LPCSTR)3);
	pfnGetSkeltonJointPosition = (fnGetSkeltonJointPosition)GetProcAddress(hModule_, (LPCSTR)4);
	pfnInit = (fnInit)GetProcAddress(hModule_, (LPCSTR)6);
	pfnIsTracking = (fnIsTracking)GetProcAddress(hModule_, (LPCSTR)7);

	if (pfnClean == NULL) return DxOpenNIDllBase::ERR_LOAD_CLEAN;
	if (pfnDepthTexture == NULL) return DxOpenNIDllBase::ERR_LOAD_DEPTH;
	if (pfnDrawDepthMap == NULL) return DxOpenNIDllBase::ERR_LOAD_DRAW;
	if (pfnGetSkeltonJointPosition == NULL) return DxOpenNIDllBase::ERR_LOAD_GETSKELTON;
	if (pfnInit == NULL) return DxOpenNIDllBase::ERR_LOAD_INIT;
	if (pfnIsTracking == NULL) return DxOpenNIDllBase::ERR_LOAD_ISTRACKING;

	return DxOpenNIDllBase::NO_ERR;
}

//=============== version 1.20 =======================
DxOpenNIDll120::DxOpenNIDll120(HMODULE module) {
	hModule_ = module;
}

void DxOpenNIDll120::Clean(void) {
	if (hModule_ != NULL) {
		pfnClean();
		FreeLibrary(hModule_);
		hModule_ = NULL;
	}
}

void DxOpenNIDll120::DrawDepthMap(bool waitflag) {
	pfnDrawDepthMap(waitflag);
}

void DxOpenNIDll120::DepthTexture(IDirect3DTexture9** lpTex) {
	pfnDepthTexture(lpTex);
}

void DxOpenNIDll120::GetSkeltonJointPosition(int num, D3DXVECTOR3* vec) {
  switch(num) {
  case 16:
	  pfnGetSkeltonJointPosition(5, vec);  // 16@1.30 and 5@1.20 is XN_SKEL_LEFT_HAND 
    break;
  case 17:
	  pfnGetSkeltonJointPosition(8, vec);  // 17@1.30 and 8@1.20 is XN_SKEL_RIGHT_HAND 
    break;
  default:
	  pfnGetSkeltonJointPosition(num, vec);
  }
}

bool DxOpenNIDll120::Init(HWND hWnd, bool EngFlag, LPDIRECT3DDEVICE9 lpDevice, WCHAR* f_path, CHAR* onifilename) {
	return pfnInit(hWnd, EngFlag, lpDevice, f_path, onifilename);
}

void DxOpenNIDll120::IsTracking(bool* lpb) {
	pfnIsTracking(lpb);
}

int DxOpenNIDll120::LoadFunc(void) {
	if (hModule_ == NULL) return ERR_MODULE_NULL;
	pfnClean = (fnClean)GetProcAddress(hModule_, (LPCSTR)1);
	pfnDepthTexture = (fnDepthTexture)GetProcAddress(hModule_, (LPCSTR)2);
	pfnDrawDepthMap = (fnDrawDepthMap)GetProcAddress(hModule_, (LPCSTR)3);
	pfnGetSkeltonJointPosition = (fnGetSkeltonJointPosition)GetProcAddress(hModule_, (LPCSTR)4);
	pfnInit = (fnInit)GetProcAddress(hModule_, (LPCSTR)6);
	pfnIsTracking = (fnIsTracking)GetProcAddress(hModule_, (LPCSTR)7);

	if (pfnClean == NULL) return DxOpenNIDllBase::ERR_LOAD_CLEAN;
	if (pfnDepthTexture == NULL) return DxOpenNIDllBase::ERR_LOAD_DEPTH;
	if (pfnDrawDepthMap == NULL) return DxOpenNIDllBase::ERR_LOAD_DRAW;
	if (pfnGetSkeltonJointPosition == NULL) return DxOpenNIDllBase::ERR_LOAD_GETSKELTON;
	if (pfnInit == NULL) return DxOpenNIDllBase::ERR_LOAD_INIT;
	if (pfnIsTracking == NULL) return DxOpenNIDllBase::ERR_LOAD_ISTRACKING;

	return DxOpenNIDllBase::NO_ERR;
}

//=============== version 1.10 =======================
DxOpenNIDll110::DxOpenNIDll110(HMODULE module) {
	hModule_ = module;
}

void DxOpenNIDll110::Clean(void) {
	if (hModule_ != NULL) {
		pfnClean();
		FreeLibrary(hModule_);
		hModule_ = NULL;
	}
}

void DxOpenNIDll110::DrawDepthMap(bool waitflag) {
	pfnDrawDepthMap(waitflag);
}

void DxOpenNIDll110::DepthTexture(IDirect3DTexture9** lpTex) {
	pfnDepthTexture(lpTex);
}

void DxOpenNIDll110::GetSkeltonJointPosition(int num, D3DXVECTOR3* vec) {
  switch(num) {
  case 15:
	  pfnGetSkeltonJointPosition(0, vec);  // torso = center
    break;
  case 16:
	  pfnGetSkeltonJointPosition(5, vec);  // 16@1.30 and 5@1.20 is XN_SKEL_LEFT_HAND 
    break;
  case 17:
	  pfnGetSkeltonJointPosition(8, vec);  // 17@1.30 and 8@1.20 is XN_SKEL_RIGHT_HAND 
    break;
  default:
	  pfnGetSkeltonJointPosition(num, vec);
  }
}

bool DxOpenNIDll110::Init(HWND hWnd, bool EngFlag, LPDIRECT3DDEVICE9 lpDevice, WCHAR* f_path, CHAR* onifilename) {
	if (onifilename != NULL) return false;
	return pfnInit(hWnd, EngFlag, lpDevice, f_path);
}

void DxOpenNIDll110::IsTracking(bool* lpb) {
	pfnIsTracking(lpb);
}

int DxOpenNIDll110::LoadFunc(void) {
	pfnClean = (fnClean)GetProcAddress(hModule_, (LPCSTR)1);
	pfnDepthTexture = (fnDepthTexture)GetProcAddress(hModule_, (LPCSTR)2);
	pfnDrawDepthMap = (fnDrawDepthMap)GetProcAddress(hModule_, (LPCSTR)3);
	pfnGetSkeltonJointPosition = (fnGetSkeltonJointPosition)GetProcAddress(hModule_, (LPCSTR)4);
	pfnInit = (fnInit)GetProcAddress(hModule_, (LPCSTR)6);
	pfnIsTracking = (fnIsTracking)GetProcAddress(hModule_, (LPCSTR)7);

	if (pfnClean == NULL) return DxOpenNIDllBase::ERR_LOAD_CLEAN;
	if (pfnDepthTexture == NULL) return DxOpenNIDllBase::ERR_LOAD_DEPTH;
	if (pfnDrawDepthMap == NULL) return DxOpenNIDllBase::ERR_LOAD_DRAW;
	if (pfnGetSkeltonJointPosition == NULL) return DxOpenNIDllBase::ERR_LOAD_GETSKELTON;
	if (pfnInit == NULL) return DxOpenNIDllBase::ERR_LOAD_INIT;
	if (pfnIsTracking == NULL) return DxOpenNIDllBase::ERR_LOAD_ISTRACKING;

	return DxOpenNIDllBase::NO_ERR;
}
