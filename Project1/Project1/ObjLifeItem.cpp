//�g�p�w�b�_�[
#include "GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include "ObjLifeItem.h"
#include"UtilityModule.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
//�R���X�g���N�^
CObjLifeItem::CObjLifeItem(float x, float y)
{
	m_x = x;
	m_y = y;
}
//�C�j�V�����C�Y
void CObjLifeItem::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_LIFE_ITEM, OBJ_LIFE_ITEM, 1);
}
//�A�N�V����
void CObjLifeItem::Action()
{

	//�ړ�����
	m_vx = +1.0f;
	m_vy = 0.0f;

	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//���x�����߂�
	m_vx *= 1.5f;
	m_vy *= 1.5f;
	//�ړ��x�N�g�������W�ɉ��Z����B
	m_x += m_vx;
	m_y += m_vy;
	//HitBox�̓��e�X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
	//�̈�O�ɏo����A�C�e����j���B
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false); //���g�ɍ폜���߂��o���B
		Hits::DeleteHitBox(this);//�G�@�e�ۂ����L����HitBox���폜
		return;
	}
	/*-----------------------�G�ꂽ�炱�̃I�u�W�F�N�g�폜------------*/
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		this->SetStatus(false); //���g�ɍ폜����
		Hits::DeleteHitBox(this);//�e�ۂ����L����HITBOX�폜
	}
}

//�h���[
void CObjLifeItem::Draw()
{
	//�`��J���[���@R-RED G=GREEN B=BLUE A=ALPHA(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`��؂���ʒu
	RECT_F dst;//�`���\��

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 32.0f;
	src.m_bottom = 32.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//0�Ԗڂɓo�^�����O���t�B�b�N��src.dst.c�̏������Ƃɕ`��B
	Draw::Draw(31, &src, &dst, c, 0.0f);

}