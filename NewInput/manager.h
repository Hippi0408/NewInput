//=============================================================================
//
// manager.h
// Author : koduna hirohito
//
//=============================================================================
#ifndef _MANAGER_H_			//���̃}�N����`������Ȃ�������
#define _MANAGER_H_			//2�d�C���N���[�h�h�~�̃}�N����`
//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "main.h"

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CInput;
class CObject;
class CRenderer;

//*****************************************************************************
// �N���X��`
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

