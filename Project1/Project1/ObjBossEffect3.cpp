//使用ヘッダー
#include "GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include "ObjBossEffect3.h"
#include"UtilityModule.h"
//使用するネームスペース
using namespace GameL;
//コンストラクタ
ObjBossEffect3::ObjBossEffect3(float x, float y)
{
	m_x = x;
	m_y = y;
}
//イニシャライズ
void ObjBossEffect3::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
}
//アクション
void ObjBossEffect3::Action()
{
	//移動方向
	m_vx = 0.0f;
	m_vy = -2.0f;

	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//速度を求める
	m_vx *= 1.5f;
	m_vy *= 1.5f;
	//移動ベクトルを座標に加算する。
	m_x += m_vx;
	m_y += m_vy;
	//領域外に出たら敵機を破棄。
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false); //自身に削除命令を出す。
		Hits::DeleteHitBox(this);//敵機弾丸が所有するHitBoxを削除
		return;
	}

}

//ドロー
void ObjBossEffect3::Draw()
{
	//描画カラー情報　R-RED G=GREEN B=BLUE A=ALPHA(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画切り取り位置
	RECT_F dst;//描画先表示

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 512.0f + m_x;
	dst.m_bottom = 128.0f + m_y;

	//0番目に登録したグラフィックをsrc.dst.cの情報をもとに描画。
	Draw::Draw(8, &src, &dst, c, 0.0f);

}