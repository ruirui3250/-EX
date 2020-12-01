//使用ヘッダー
#include "GameHead.h"
#include "GameL\DrawTexture.h"
#include "Item.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ 宣言
CObjItem::CObjItem(float x, float y)
{
	m_x = x;
	m_y = y;

	//当たり判定用hitboxを作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_ITEM, 100);
}
//イニシャライズ
void CObjItem::Init()
{

}

//アクション
void CObjItem::Action()
{

}

//ドロー
void CObjItem::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F dst;//描画先表示

	//切り取り位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//0番目に登録したグラフィックを描画。
	//Draw::Draw(3, &dst, c, 180.0f);
}