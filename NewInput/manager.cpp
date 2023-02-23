//=============================================================================
//
// manager.cpp
// Author : koduna hirohito
//
//=============================================================================

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "manager.h"
#include "renderer.h"
#include "game.h"
#include "input.h"
#include "texture.h"


//*****************************************************************************
// コンストラクタ
//*****************************************************************************
CManager::CManager()
{
	m_pGame = nullptr;
	m_pInput = nullptr;
	m_pRenderer = nullptr;
}

//*****************************************************************************
// デストラクタ
//*****************************************************************************
CManager::~CManager()
{
}

//*****************************************************************************
// 初期化
//*****************************************************************************
HRESULT CManager::Init(HINSTANCE hInstance,HWND hWnd, bool bWindow)
{
	CTexture::Create();

	m_pInput = CInput::Create();
	//入力処理の初期化処理
	if (FAILED(m_pInput->Init(hInstance, hWnd)))
	{
		return E_FAIL;
	}

	m_pRenderer = new CRenderer;

	// 初期化処理
	if (FAILED(m_pRenderer->Init(hWnd, bWindow)))
	{
		return -1;
	}

	m_pGame = new CGame;
	if (FAILED(m_pGame->Init()))
	{
		return -1;
	}

	return S_OK;
}

//*****************************************************************************
// 終了処理
//*****************************************************************************
void CManager::Uninit()
{
	//入力処理の終了処理
	m_pInput->Uninit();

	CTexture::Uninit();

	if (m_pGame != nullptr)
	{
		// 終了処理
		m_pGame->Uninit();
		delete m_pGame;
		m_pGame = nullptr;
	}

	if (m_pRenderer != nullptr)
	{
		// 終了処理
		m_pRenderer->Uninit();
		delete m_pRenderer;
		m_pRenderer = nullptr;
	}
}

//*****************************************************************************
// 更新処理
//*****************************************************************************
void CManager::Update()
{
	//入力処理の更新処理
	m_pInput->Update();
	
	if (m_pGame != nullptr)
	{
		m_pGame->Update();
	}

	if (m_pRenderer != nullptr)
	{
		m_pRenderer->Update();
	}
}

//*****************************************************************************
// 描画処理
//*****************************************************************************
void CManager::Draw(int nFPS)
{
	m_pRenderer->Draw(nFPS);
}

LPDIRECT3DDEVICE9 CManager::GetDeviceManager()
{
	return m_pRenderer->GetDeviceRenderer();
}