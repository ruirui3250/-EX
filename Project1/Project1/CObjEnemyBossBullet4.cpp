//�g�p�w�b�_�[
#include "GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include "CObjEnemyBossBullet4.h"
#include"UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;
//�R���X�g���N�^
CObjEnemyBossBullet4::CObjEnemyBossBullet4(float x, float y)
{
	m_x = x;
	m_y = y;
}
//�C�j�V�����C�Y
void CObjEnemyBossBullet4::Init()
{
	m_time = 0;
	m_vx = 0.0f;
	m_vy = 0.0f;


	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_x, m_y, 10, 10, ELEMENT_ENEMY, OBJ_BOSS_BULLET_ENEMY, 4);
}
//�A�N�V����
void CObjEnemyBossBullet4::Action()
{
	//20���Ԋu�Œe�۔���
	m_time++;
	if (m_time > 50)
	{
		m_time = 0;

		//19����������
		CObjEnemyBossBullet2* obj_b;
		for (int i = 0; i < 360; i += 20)
		{
			//�p�xi�Ŋp�x�e�۔���
			obj_b = new CObjEnemyBossBullet2(m_x, m_y, i, 5.0f);
			Objs::InsertObj(obj_b, OBJ_BOSS_BULLET_ENEMY2, 100);
		}
	}
	//�ړ�����
	m_vx = 0.0f;
	m_vy = -1.0f;

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
	//�G�@�����S�ɗ̈�ɂł���j���B
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);//���g�ɍ폜����
		Hits::DeleteHitBox(this);//�G�@�����L����B
		return;

	}
	//�e�ۂ̐ڐG�𒲂ׂ�B
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
	//�e�ۂ̐ڐG�𒲂ׂ�B
	if (hit->CheckObjNameHit(OBJ_SITA_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
	//�e�ۂ̐ڐG�𒲂ׂ�B
	if (hit->CheckObjNameHit(OBJ_ANGLE_BULLET_HERO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
	//�e�ۂ̐ڐG�𒲂ׂ�B
	if (hit->CheckObjNameHit(OBJ_SITA_LASER_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
}

//�h���[
void CObjEnemyBossBullet4::Draw()
{
	//�`��J���[���@R-RED G=GREEN B=BLUE A=ALPHA(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`��؂���ʒu
	RECT_F dst;//�`���\��

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 25.0f;
	src.m_bottom = 25.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 25.0f + m_x;
	dst.m_bottom = 25.0f + m_y;

	//0�Ԗڂɓo�^�����O���t�B�b�N��src.dst.c�̏������Ƃɕ`��B
	Draw::Draw(4, &src, &dst, c, 0.0f);

}