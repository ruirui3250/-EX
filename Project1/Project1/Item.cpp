//使用ヘッダー
#include "GameHead.h"
#include "GameL\DrawTexture.h"
#include "Item.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ 宣言
CObjItem::CObjItem(float x,float y)
{
	m_x = x;
	m_y = y;

	//当たり判定用hitboxを作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_ITEM, 100);
}