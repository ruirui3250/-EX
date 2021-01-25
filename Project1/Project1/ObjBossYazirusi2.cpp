//使用ヘッダー
#include "GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include "ObjBossYazirusi2.h"
#include"UtilityModule.h"
#include "GameL/DrawFont.h"

//使用するネームスペース
using namespace GameL;
//コンストラクタ
//ObjBossYazirusi::ObjBossYazirusi(float x, float y)
//{
//	m_x = x;
//	m_y = y;
//
//
//}
//イニシャライズ
void ObjBossYazirusi2::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	second = 0;
	m_time = 0;
}
//アクション
void ObjBossYazirusi2::Action()
{
	m_time++;
	if (m_time % 30 == 0)
	{
		second++;
	}
	////移動方向
	//m_vx = 0.0f;
	//m_vy = 0.0f;

	////移動ベクトルの正規化
	//UnitVec(&m_vy, &m_vx);


	////領域外に出たら破棄。
	//bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	//if (check == false)
	//{
	//	this->SetStatus(false); //自身に削除命令を出す。
	//	Hits::DeleteHitBox(this);//敵機弾丸が所有するHitBoxを削除
	//	return;
	//}
	//if (m_time == 1450)

	//{
	//	this->SetStatus(false); //自身に削除命令を出す。
	//	Hits::DeleteHitBox(this);//敵機弾丸が所有するHitBoxを削除
	//	return;
	//}
	//if (m_time==1550)

	//{
	//	this->SetStatus(false); //自身に削除命令を出す。
	//	Hits::DeleteHitBox(this);//敵機弾丸が所有するHitBoxを削除
	//	return;
	//}
	//if (m_time == 1650)
	//
	//{
	//	this->SetStatus(false); //自身に削除命令を出す。
	//	Hits::DeleteHitBox(this);//敵機弾丸が所有するHitBoxを削除
	//	return;
	//}
	//if (m_time == 1750)

	//{
	//	this->SetStatus(false); //自身に削除命令を出す。
	//	Hits::DeleteHitBox(this);//敵機弾丸が所有するHitBoxを削除
	//	return;
	//}
	//if (m_time == 1850)

	//{
	//	this->SetStatus(false); //自身に削除命令を出す。
	//	Hits::DeleteHitBox(this);//敵機弾丸が所有するHitBoxを削除
	//	return;
	//}
}

//ドロー
void ObjBossYazirusi2::Draw()
{
	//描画カラー情報　R-RED G=GREEN B=BLUE A=ALPHA(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画切り取り位置
	RECT_F dst;//描画先表示

	wchar_t str[256];

	swprintf_s(str, L"%d", m_time);
	Font::StrDraw(str, 500, 0, 40, c);

	swprintf_s(str, L"%d", second);
	Font::StrDraw(str, 550, 50, 40, c);

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 250.0f;



	if (second % 2 == 0)
	{
		//表示位置の設定
		dst.m_top = 100.0f + m_y;
		dst.m_left = 500.0f + m_x;
		dst.m_right = 700.0f + m_x;
		dst.m_bottom = 400.0f + m_y;

		//0番目に登録したグラフィックをsrc.dst.cの情報をもとに描画。
		Draw::Draw(33, &src, &dst, c, 0.0f);

	}


}