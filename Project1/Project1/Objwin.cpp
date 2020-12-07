//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"


#include"GameHead.h"
#include"Objwin.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjWin::Init()
{
	m_key_flag = false;
	m_y1 = 0;
}
//アクション
void CObjWin::Action()
{
	//エンターキーを押してシーンタイトルを移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
	//背景１の操作
	if (m_y1 > -1900.0f)
	{
		m_y1 -= 2.0f;
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
void CObjWin::Draw()
{
	float c[4]{ 1.0f, 1.0f, 1.0f, 1.0f };
		Font::StrDraw(L"STAFF CREDIT", 150, 300 + m_y1, 100, c);
		Font::StrDraw(L"総合ディレクター　瀬口 琉", 0, 450 + m_y1, 50, c);
		Font::StrDraw(L"プランナー 桶谷　光城", 0, 600 + m_y1, 50, c);
		Font::StrDraw(L"チーフプランナー 上田　茂樹", 0, 750 + m_y1, 50, c);
		Font::StrDraw(L"グラフィックデザイナー　鞍野　一哉", 0, 900 + m_y1, 45, c);
		Font::StrDraw(L"サウンドディレクター　蛭間　瑠唯", 0, 1050 + m_y1, 50, c);
		Font::StrDraw(L"お借りした楽曲 魔王魂様", 0, 1300 + m_y1, 50, c);
		Font::StrDraw(L"Congratulation!!", 0, 300, 2000 + m_y1, c);
		Font::StrDraw(L"エンターでタイトルに戻る", 0, 2400 + m_y1, 65, c);
}