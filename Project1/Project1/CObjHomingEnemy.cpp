//�g�p����w�b�_�[�t�@�C��
#include "GameL/\DrawTexture.h"
#include "GameL/\HitBoxManager.h"

#include"GameL\SceneObjManager.h"
#include "GameHead.h"
#include "CObjHomingEnemy.h"
#include "UtilityModule.h"
#include"GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�^���X�^
CObjHomingEnemy::CObjHomingEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjHomingEnemy::Init()
{
	m_eff.m_top = 32;
	m_eff.m_left = 0;
	m_eff.m_right = 32;
	m_eff.m_bottom = 64;
	m_ani = 0;
	m_ani_time = 0;
	m_del = false;

	m_vx = 0.0f;
	m_vy = 1.0f;
	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_HOMING_ENEMY, 50);
}

//�A�N�V����
void CObjHomingEnemy::Action()
{
	//Resources�̕`�ʕ���RECT
	m_eff = GetBulletEffect(&m_ani, &m_ani_time, m_del, 3);

	//�e�ۏ��ŏ���
	if (m_del == true)
	{


		//���e�A�j���[�V�����I���Ŗ{���ɃI�u�W�F�N�g�j��
		if (m_ani == 4)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}

		return;//���ŏ����́A�����ŃA�N�V�������\�b�h���I��������
	}

	//��l���@�ƗU���e�ۂŊp�x�����
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//��l���@�ƗU���e�ۂŊp�x�����
	CObjHero5* obj2 = (CObjHero5*)Objs::GetObj(OBJ_HERO5);

	//��l���@�����݂���ꍇ�A�U���p�x�̌v�Z����
	if (obj != nullptr)
	{
		float x = obj->GetX() - m_x;
		float y = obj->GetY() - m_y;
		float ar = GetAtan2Angle(x, -y);


		//�e�ۂ̌��݂̌����Ă���p�x�����
		float br = GetAtan2Angle(m_vx, -m_vy);

		//��l���@�ƓG�@�p�x�����܂�ɂ��������ꂽ��
		if (ar - br > 20)
		{
			//�ړ���������l���@�̕����ɂ���
			m_vx = cos(3.14 / 180 * ar);
			m_vy = -sin(3.14 / 180 * ar);
		}

		float r = 3.14 / 180.0f;   //�p�x1��
		if (ar < br)
		{
			//�ړ�������+1��������
			m_vx = m_vx * cos(r) - m_vy * sin(r);
			m_vy = m_vy * cos(r) + m_vx * sin(r);
		}
		else
		{
			//�ړ�������-1��������
			m_vx = m_vx * cos(-r) - m_vy * sin(-r);
			m_vy = m_vy * cos(-r) + m_vx * sin(-r);
		}

		UnitVec(&m_vx, &m_vy);
	}

	//�ړ�
	m_x += m_vx * 5.0f;
	m_y += m_vy * 5.0f;

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//�̈�O�ɏo����e�ۂ�j�󂷂�
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		return;
	}
	//��l���@object�ƐڐG������G�@�폜�B
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
	//�e�ۂ̐ڐG�𒲂ׂ�B
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		Audio::Start(18);
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
	//�e�ۂ̐ڐG�𒲂ׂ�B
	if (hit->CheckObjNameHit(OBJ_ANGLE_BULLET_HERO) != nullptr)
	{
		Audio::Start(18);
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
}

//�h���[
void CObjHomingEnemy::Draw()
{
	//�`��J���[���@R=RED�@G=GREEN�@B=BLUE�@A=ALPHA�i���ߏ��j
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F dst;//�`���\���ʒu


	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	float r = 0.0f;
	//��l���@�ƗU���e�ۂŊp�x�����
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//��l���@�����݂���ꍇ�A�U���p�x�̌v�Z����
	if (obj != nullptr)
	{
		float x = obj->GetX() - m_x;
		float y = obj->GetY() - m_y;
		r = GetAtan2Angle(x, -y);

		
		///0�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������Ƃɕ`��
		Draw::Draw(3, &m_eff, &dst, c, r);
	}
}