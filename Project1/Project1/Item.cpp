//�g�p�w�b�_�[
#include "GameHead.h"
#include "GameL\DrawTexture.h"
#include "Item.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y �錾
CObjItem::CObjItem(float x,float y)
{
	m_x = x;
	m_y = y;

	//�����蔻��phitbox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_ITEM, 100);
}