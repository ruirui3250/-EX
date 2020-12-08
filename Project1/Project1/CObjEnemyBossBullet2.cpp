//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "CObjEnemyBossBullet2.h"
#include"UtilityModule.h"

//�g�p����l�[��
using namespace GameL;

CObjEnemyBossBullet2::CObjEnemyBossBullet2(float x, float y, float r, float speed)
{
	m_x = x;
	m_y = y;
	m_r = r;
	m_speed = speed;
}

//�C�j�V�����C�Y
void CObjEnemyBossBullet2::Init()
{
	m_eff.m_top = 0;
	m_eff.m_left = 0;
	m_eff.m_right = 10;
	m_eff.m_bottom = 10;
	m_ani = 0;
	m_ani_time = 0;
	m_del = false;

	m_vx = cos(3.14f / 180.0f * m_r);
	m_vy = sin(3.14f / 180.0f * m_r);

	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//�����蔻��pHitBox���쐬�B
	Hits::SetHitBox(this, m_x, m_y, 10, 10, ELEMENT_ENEMY, OBJ_BOSS_BULLET_ENEMY2, 50);

}

//�A�N�V����
void CObjEnemyBossBullet2::Action()
{
	//Resources�̕`�敨RECT
	m_eff = GetBulletEffect(&m_ani, &m_ani_time, m_del, 4);

	//�e�ۏ��ŏ���
	if (m_del == true)
	{
		//���e�A�j���[�V�����I���Ŗ{���ɃI�u�W�F�N�g�̔j���B
		if (m_ani == 4)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
		return; //���ŏ����́A�����ŃA�N�V�������\�b�h���I�������B
	}
	//�ړ�
	m_x += m_vx * m_speed;
	m_y -= m_vy * m_speed;

	//�G�@�e�ۂ̍X�V�p�|�C���^�[���l���B
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);	//HitBox�̈ʒu��G�@�e�ۂ̈ʒu���X�V�B
	//�̈�O�ɏo����e�ۂ�j���B
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false); //���g�ɍ폜���߂��o���B
		Hits::DeleteHitBox(this);//�G�@�e�ۂ����L����HitBox���폜
		return;
	}
	//��l���@object�ƐڐG������G�@�e�ۍ폜�B
	if (hit->CheckObjNameHit(OBJ_SITA_HERO) != nullptr)
	{
		m_del = true; //���Ŏ��s
		hit->SetInvincibility(true);//�����蔻�薳��
	}
	//�e�ۂ̐ڐG�𒲂ׂ�B
	if (hit->CheckObjNameHit(OBJ_SITA_BULLET) != nullptr)
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
	if (hit->CheckObjNameHit(OBJ_SITA_LASER_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//�h���[
void CObjEnemyBossBullet2::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F dst;//�`���\��

	//�؂���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 25.0f + m_x;
	dst.m_bottom = 25.0f + m_y;

	//0�Ԗڂɓo�^�����O���t�B�b�N��`��B
	Draw::Draw(4, &m_eff, &dst, c, m_r);
}