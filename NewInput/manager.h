//=============================================================================
//
// manager.h
// Author : koduna hirohito
//
//=============================================================================
#ifndef _MANAGER_H_			//このマクロ定義がされなかったら
#define _MANAGER_H_			//2重インクルード防止のマクロ定義
//*****************************************************************************
// インクルード
//*****************************************************************************
#include "main.h"

//*****************************************************************************
// 前方宣言
//*****************************************************************************
class CInput;
class CObject;
class CRenderer;

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CManager
{

public:
	
	CManager();
	~CManager();

	HRESULT Init(HINSTANCE hInstance,HWND hWnd, bool bWindow);
	void Uninit();
	void Update();
	void Draw(int nFPS);
	LPDIRECT3DDEVICE9 GetDeviceManager();
	CObject *GetGameObject() { return m_pGame; }
	void SetGemeObject(CObject *Object) {m_pGame = Object;}
private:
	
	CRenderer *m_pRenderer;
	CObject *m_pGame;
	CInput *m_pInput;
};
#endif

