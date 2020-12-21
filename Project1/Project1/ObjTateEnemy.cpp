//�g�p�w�b�_�[
#include "GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include "ObjTateEnemy.h"
#include"UtilityModule.h"
#include"GameL/Audio.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
//�R���X�g���N�^
CObjTateEnemy::CObjTateEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
	
}
//�C�j�V�����C�Y
void CObjTateEnemy::Init()
{
	m_r = 0;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_del = 0.0f;

	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_ENEMY, 1);
}
//�A�N�V����
void CObjTateEnemy::Action()
{
	//�p�x�v�Z
	m_r += 2.0f;
	//360���Ō��ɖ߂�
	if (m_r > 360.0f)
		m_r = 6.0f;
	//�ړ�����
	m_vx = sin(3.14 / 180 * m_r);
	m_vy = +1.0f;
	
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
	//�̈�O�ɏo����G�@��j���B
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false); //���g�ɍ폜���߂��o���B
		Hits::DeleteHitBox(this);//�G�@�e�ۂ����L����HitBox���폜
		return;
	}
	//��l���@object�ƐڐG������G�@�폜�B
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//��l���@object�ƐڐG������G�@�e�ۍ폜�B
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_del = true; //���Ŏ��s
		hit->SetInvincibility(true);//�����蔻�薳��
	}
	//�e�ۂ̐ڐG�𒲂ׂ�B
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//�e�ۂ̐ڐG�𒲂ׂ�B
	if (hit->CheckObjNameHit(OBJ_ANGLE_BULLET_HERO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//�e�ۂ̐ڐG�𒲂ׂ�B
	if (hit->CheckObjNameHit(OBJ_TATE_LASER_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//�h���[
void CObjTateEnemy::Draw()
{
	//�`��J���[���@R-RED G=GREEN B=BLUE A=ALPHA(���ߏ��)
	float c[4] = { 1.0f,6.0f,9.0f,1.0f };

	RECT_F src; //�`��؂���ʒu
	RECT_F dst;//�`���\��

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 32.0f;
	src.m_right = 64.0f;
	src.m_bottom = 32.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 32.0f + m_x;
	dst.m_right = 0.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//0�Ԗڂɓo�^�����O���t�B�b�N��src.dst.c�̏������Ƃɕ`��B
	Draw::Draw(7, &src, &dst, c, 0.0f);

}
