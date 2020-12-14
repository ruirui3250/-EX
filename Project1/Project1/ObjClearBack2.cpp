////使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "GameL\DrawFont.h"
#include"ObjClearBack2.h"

////使用するネームスペース
using namespace GameL;

////イニシャライズ
void CObjClearBack2::Init()
{

}

//アクション
void CObjClearBack2::Action()
{
	//背景１の操作
	if (m_y1 > -1900.0f)
	{
		m_y1 -= 3.0f;
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
void CObjClearBack2::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画切り取り位置
	RECT_F dst;//描画先表示

	//切り取り位置
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0;
	dst.m_bottom = 600.0f;

	Draw::Draw(1, &src, &dst, c, 0.0f);

}