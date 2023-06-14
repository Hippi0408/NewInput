//=============================================================================
//
// game.cpp
// Author : koduna hirohito
//
//=============================================================================

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "manager.h"
#include "game.h"
#include "input.h"
#include "texture.h"
#include <assert.h>
#include "2dpolygon.h"

//*****************************************************************************
// コンストラクタ
//*****************************************************************************
CGame::CGame()
{
}

//*****************************************************************************
// デストラクタ
//*****************************************************************************
CGame::~CGame()
{
}

//*****************************************************************************
// 初期化
//*****************************************************************************
HRESULT CGame::Init()
{
	for (int nCnt = 0; nCnt < 4; nCnt++)
	{
		m_p2DPolygon[nCnt] = new C2DPolygon;
		if (FAILED(m_p2DPolygon[nCnt]->Init()))
		{
			return -1;
		}

		m_p2DPolygon[nCnt]->SetTextIndex(0);
		m_p2DPolygon[nCnt]->SetPos(D3DXVECTOR3(200.0f + 400.0f * nCnt, SCREEN_HEIGHT * 0.5f, 0.0f));
		m_p2DPolygon[nCnt]->SetDiagonalLine(200.0f, 200.0f);
		
	}

	m_p2DPolygon[0]->SetColor(D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f));
	m_p2DPolygon[1]->SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
	m_p2DPolygon[2]->SetColor(D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f));
	m_p2DPolygon[3]->SetColor(D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
	
	for (int nCnt = 0; nCnt < 4; nCnt++)
	{
		m_p2DPolygon[nCnt]->SetPolygon();
	}
	return S_OK;
}

//*****************************************************************************
// 終了処理
//*****************************************************************************
void CGame::Uninit()
{
	for (int nCnt = 0; nCnt < 4; nCnt++)
	{
		if (m_p2DPolygon[nCnt] != nullptr)
		{
			m_p2DPolygon[nCnt]->Uninit();
			delete m_p2DPolygon[nCnt];
			m_p2DPolygon[nCnt] = nullptr;
		}
	}
}

//*****************************************************************************
// 更新処理
//*****************************************************************************
void CGame::Update()
{
	
}

//*****************************************************************************
// 描画処理
//*****************************************************************************
void CGame::Draw()
{
	CInput* pInput = CInput::GetKey();


	if (pInput->Trigger(DIK_0))
	{
		pInput->SetJoypadKeyConfig(0, JOYPAD_X, JOYPAD_A);
	}

	for (int nCnt = 0; nCnt < 4; nCnt++)
	{
		if (pInput->IsConnected(nCnt) && !pInput->Press(JOYPAD_X, nCnt))
		{
			m_p2DPolygon[nCnt]->Draw();
		}
	}

}
