//使用ヘッダー
#include "GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include "ObjLifeItem.h"
#include"UtilityModule.h"
//使用するネームスペース
using namespace GameL;
//コンストラクタ
CObjLifeItem::CObjLifeItem(float x, float y)
{
	m_x = x;
	m_y = y;
}
//イニシャライズ
void CObjLifeItem::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_LIFE_ITEM, OBJ_LIFE_ITEM, 1);
}
//アクション
void CObjLifeItem::Action()
{

	//移動方向
	m_vx = +1.0f;
	m_vy = 0.0f;

	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//速度を求める
	m_vx *= 1.5f;
	m_vy *= 1.5f;
	//移動ベクトルを座標に加算する。
	m_x += m_vx;
	m_y += m_vy;
	//HitBoxの内容更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
	//領域外に出たらアイテムを破棄。
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false); //自身に削除命令を出す。
		Hits::DeleteHitBox(this);//敵機弾丸が所有するHitBoxを削除
		return;
	}
	/*-----------------------触れたらこのオブジェクト削除------------*/
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		this->SetStatus(false); //自身に削除命令
		Hits::DeleteHitBox(this);//弾丸が所有するHITBOX削除
	}
}

//ドロー
void CObjLifeItem::Draw()
{
	//描画カラー情報　R-RED G=GREEN B=BLUE A=ALPHA(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画切り取り位置
	RECT_F dst;//描画先表示

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 32.0f;
	src.m_bottom = 32.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//0番目に登録したグラフィックをsrc.dst.cの情報をもとに描画。
	Draw::Draw(31, &src, &dst, c, 0.0f);

}