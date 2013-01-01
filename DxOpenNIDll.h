#ifndef DXOPENNIDLL_H
#define DXOPENNIDLL_H

#include <d3d9.h>
#include <d3dx9.h>

// version 1.20 interface
class DxOpenNIDllBase {
public:
	enum {
		NO_ERR,
		ERR_LOAD_CLEAN,
		ERR_LOAD_DRAW,
		ERR_LOAD_DEPTH,
		ERR_LOAD_GETSKELTON,
		ERR_LOAD_INIT,
		ERR_LOAD_ISTRACKING,
		ERR_MODULE_NULL,
		ERR_UNSUPPORTED,
		ERR_OTHER,
	};
	virtual ~DxOpenNIDllBase();
	virtual void Clean(void) = 0;
	virtual void DrawDepthMap(bool waitflag) = 0;
	virtual void DepthTexture(IDirect3DTexture9** lpTex) = 0;
	virtual void GetSkeltonJointPosition(int num, D3DXVECTOR3* vec) = 0;
	virtual bool Init(HWND hWnd, bool EngFlag, LPDIRECT3DDEVICE9 lpDevice, WCHAR* f_path, CHAR* onifilename) = 0;
	virtual void IsTracking(bool* lpb) = 0;
	virtual int LoadFunc(void) = 0;
	static HMODULE LoadDll(const WCHAR* path, float *ver);
protected:
//	typedef void (__stdcall *fnGetVersion)(float*);
//	fnGetVersion pfnGetVersion;
  static const float invalidY;
	HMODULE hModule_;
};

class DxOpenNIDll110 : public DxOpenNIDllBase {
public:
	explicit DxOpenNIDll110(HMODULE module);
	~DxOpenNIDll110() {}
	void Clean(void);
	void DrawDepthMap(bool waitflag);
	void DepthTexture(IDirect3DTexture9** lpTex);
	void GetSkeltonJointPosition(int num, D3DXVECTOR3* vec);
	bool Init(HWND hWnd, bool EngFlag, LPDIRECT3DDEVICE9 lpDevice, WCHAR* f_path, CHAR* onifilename);
	void IsTracking(bool* lpb);
	int LoadFunc(void);
	//void GetVersion(float* ver) { *ver = 1.10f; }
private:
	DxOpenNIDll110() {}
	typedef void (__stdcall *fnClean)(void);
	typedef void (__stdcall *fnDrawDepthMap)(bool);
	typedef void (__stdcall *fnDepthTexture)(IDirect3DTexture9**);
	typedef void (__stdcall *fnGetSkeltonJointPosition)(int, D3DXVECTOR3*);
	typedef bool (__stdcall *fnInit)(HWND, bool, LPDIRECT3DDEVICE9, WCHAR*);
	typedef void (__stdcall *fnIsTracking)(bool*);
	fnClean			pfnClean;
	fnDrawDepthMap	pfnDrawDepthMap;
	fnDepthTexture	pfnDepthTexture;
	fnGetSkeltonJointPosition pfnGetSkeltonJointPosition;
	fnInit			pfnInit;
	fnIsTracking	pfnIsTracking;
};

class DxOpenNIDll120 : public DxOpenNIDllBase {
public:
	explicit DxOpenNIDll120(HMODULE module);
	~DxOpenNIDll120() {}
	void Clean(void);
	void DrawDepthMap(bool waitflag);
	void DepthTexture(IDirect3DTexture9** lpTex);
	void GetSkeltonJointPosition(int num, D3DXVECTOR3* vec);
	bool Init(HWND hWnd, bool EngFlag, LPDIRECT3DDEVICE9 lpDevice, WCHAR* f_path, CHAR* onifilename);
	void IsTracking(bool* lpb);
	int LoadFunc(void);
private:
	typedef void (__stdcall *fnClean)(void);
	typedef void (__stdcall *fnDrawDepthMap)(bool);
	typedef void (__stdcall *fnDepthTexture)(IDirect3DTexture9**);
	typedef void (__stdcall *fnGetSkeltonJointPosition)(int, D3DXVECTOR3*);
	typedef bool (__stdcall *fnInit)(HWND, bool, LPDIRECT3DDEVICE9, WCHAR*, CHAR*);
	typedef void (__stdcall *fnIsTracking)(bool*);
	fnClean			pfnClean;
	fnDrawDepthMap	pfnDrawDepthMap;
	fnDepthTexture	pfnDepthTexture;
	fnGetSkeltonJointPosition pfnGetSkeltonJointPosition;
	fnInit			pfnInit;
	fnIsTracking	pfnIsTracking;
};

class DxOpenNIDll130 : public DxOpenNIDllBase {
public:
	explicit DxOpenNIDll130(HMODULE module);
	~DxOpenNIDll130() {}
	void Clean(void);
	void DrawDepthMap(bool waitflag);
	void DepthTexture(IDirect3DTexture9** lpTex);
	void GetSkeltonJointPosition(int num, D3DXVECTOR3* vec);
	bool Init(HWND hWnd, bool EngFlag, LPDIRECT3DDEVICE9 lpDevice, WCHAR* f_path, CHAR* onifilename);
	void IsTracking(bool* lpb);
	int LoadFunc(void);
private:
	typedef void (__stdcall *fnClean)(void);
	typedef void (__stdcall *fnDrawDepthMap)(bool);
	typedef void (__stdcall *fnDepthTexture)(IDirect3DTexture9**);
	typedef void (__stdcall *fnGetSkeltonJointPosition)(int, D3DXVECTOR3*);
	typedef bool (__stdcall *fnInit)(HWND, bool, LPDIRECT3DDEVICE9, WCHAR*, CHAR*);
	typedef void (__stdcall *fnIsTracking)(bool*);
	fnClean			pfnClean;
	fnDrawDepthMap	pfnDrawDepthMap;
	fnDepthTexture	pfnDepthTexture;
	fnGetSkeltonJointPosition pfnGetSkeltonJointPosition;
	fnInit			pfnInit;
	fnIsTracking	pfnIsTracking;
};


#endif