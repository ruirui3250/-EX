//�g�p�w�b�_�[
#include "GameHead.h"
#include "GameL\DrawTexture.h"
#include "Item.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y �錾
CObjItem::CObjItem(float x, float y)
{
	m_x = x;
	m_y = y;

	//�����蔻��phitbox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_ITEM, 100);
}
//�C�j�V�����C�Y
void CObjItem::Init()
{

}

//�A�N�V����
void CObjItem::Action()
{

}

//�h���[
void CObjItem::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F dst;//�`���\��

	//�؂���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//0�Ԗڂɓo�^�����O���t�B�b�N��`��B
	//Draw::Draw(3, &dst, c, 180.0f);
}