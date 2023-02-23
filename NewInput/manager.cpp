//=============================================================================
//
// manager.cpp
// Author : koduna hirohito
//
//=============================================================================

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "manager.h"
#include "renderer.h"
#include "game.h"
#include "input.h"
#include "texture.h"


//*****************************************************************************
// �R���X�g���N�^
//*****************************************************************************
CManager::CManager()
{
	m_pGame = nullptr;
	m_pInput = nullptr;
	m_pRenderer = nullptr;
}

//*****************************************************************************
// �f�X�g���N�^
//*****************************************************************************
CManager::~CManager()
{
}

//*****************************************************************************
// ������
//*****************************************************************************
HRESULT CManager::Init(HINSTANCE hInstance,HWND hWnd, bool bWindow)
{
	CTexture::Create();

	m_pInput = CInput::Create();
	//���͏����̏���������
	if (FAILED(m_pInput->Init(hInstance, hWnd)))
	{
		return E_FAIL;
	}

	m_pRenderer = new CRenderer;

	// ����������
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
// �I������
//*****************************************************************************
void CManager::Uninit()
{
	//���͏����̏I������
	m_pInput->Uninit();

	CTexture::Uninit();

	if (m_pGame != nullptr)
	{
		// �I������
		m_pGame->Uninit();
		delete m_pGame;
		m_pGame = nullptr;
	}

	if (m_pRenderer != nullptr)
	{
		// �I������
		m_pRenderer->Uninit();
		delete m_pRenderer;
		m_pRenderer = nullptr;
	}
}

//*****************************************************************************
// �X�V����
//*****************************************************************************
void CManager::Update()
{
	//���͏����̍X�V����
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
// �`�揈��
//*****************************************************************************
void CManager::Draw(int nFPS)
{
	m_pRenderer->Draw(nFPS);
}

LPDIRECT3DDEVICE9 CManager::GetDeviceManager()
{
	return m_pRenderer->GetDeviceRenderer();
}