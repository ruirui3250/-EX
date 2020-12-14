//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"


#include"GameHead.h"
#include"Objwin6.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjWin6::Init()
{
	m_key_flag = false;
	m_y1 = 0;
}
//アクション
void CObjWin6::Action()
{
		//エンターキーを押してシーンタイトルを移行する
		if (Input::GetVKey(VK_RETURN) == true)
		{
			if (m_key_flag == true)
			{
				Scene::SetScene(new CSceneWin());
				m_key_flag = false;
			}
		}
		else
		{
			m_key_flag = true;
		}

	//背景１の操作
	if (m_y1 > -900.0f)
	{
		m_y1 -= 1.0f;
	}
	////背景2の操作
	//m_y2 -= 10.0f;
	//if (m_y2 < -800.0f)
	//	m_y2 = 800;
	////画面を回転させる
	//float ar = 170.0f;

	////現在の方向の角度を獲得
	//float br = 180.0f;

	//float r = 3.14 / 180.0f;//角度1
	//if (ar < br)
	//{
	//	//移動方向に+1を加える
	//	m_vx = m_vy * cos(r) - m_vx * sin(r);
	//	m_vy = m_vx * cos(-r) + m_vy * sin(-r);
	//}
	//タイム初期化
	m_time = 0;
}

//ドロー
void CObjWin6::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	////フォントの表示
	Font::StrDraw(L"ウイルスは駆逐され。",0, 200+m_y1, 60, c);
	Font::StrDraw(L"体内に平和が訪れた。", 0, 250+m_y1, 60, c);
	Font::StrDraw(L"しかし", 0, 400+m_y1, 60, c);
	Font::StrDraw(L"ウイルスは全て", 0,450+m_y1, 60, c);
	Font::StrDraw(L"駆逐されたわけではない。", 0, 500 + m_y1, 60, c);
	Font::StrDraw(L"新しいウイルスが", 0, 750 + m_y1, 60, c);
	Font::StrDraw(L"体内に侵入して来たのだ", 0, 800 + m_y1, 60, c);
	Font::StrDraw(L"戦え！", 0, 1050 + m_y1, 60, c);
	Font::StrDraw(L"ウイルスがいなくなる", 0, 1100 + m_y1, 60, c);
	Font::StrDraw(L"その日まで!!", 0, 1150 + m_y1, 60, c);
	Font::StrDraw(L"エンターでスタッフロール", 0, 1300 + m_y1, 60, c);
	




}