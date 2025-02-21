//使用ヘッダー
#include "GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include "ObjBossYazirusi.h"
#include"UtilityModule.h"
#include "GameL/DrawFont.h"
//使用するネームスペース
using namespace GameL;
//コンストラクタ
ObjBossYazirusi::ObjBossYazirusi(float x, float y)
{
	m_x = x;
	m_y = y;
}
//イニシャライズ
void ObjBossYazirusi::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 0;
	m_r = 0.0f;
	second = 0;
}

//アクション
void ObjBossYazirusi::Action()
{
	m_time++;
	if (m_time % 30 == 0)
	{
		second++;
	}



	//角度加算
	m_r += 2.0f;

	//360で初期値に戻す
	if (m_r > 360.0f)
		m_r = 0.0f;

	//移動方向
	m_vx = 0.0f;
	m_vy = sin(3.14 / 180 * m_r);

	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//移動ベクトルを座標に加算する
	m_x += m_vx;
	m_y += m_vy;







	if (m_time == 400)
	{
		this->SetStatus(false); //自身に削除命令を出す。
		return;
	}

}

//ドロー
void ObjBossYazirusi::Draw()
{
	//描画カラー情報　R-RED G=GREEN B=BLUE A=ALPHA(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画切り取り位置
	RECT_F dst;//描画先表示

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 60.0f;
	src.m_bottom = 250.0f;

	//表示位置の設定
	dst.m_top = 100.0f + m_y;
	dst.m_left = 300.0f + m_x;
	dst.m_right = 400.0f + m_x;
	dst.m_bottom = 400.0f + m_y;

	//0番目に登録したグラフィックをsrc.dst.cの情報をもとに描画。
	Draw::Draw(33, &src, &dst, c, 0.0f);


	


}