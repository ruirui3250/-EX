//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"ObjAttackEnemy2.h"
#include"UtilityModule.h"

//�g�p����l�[���X�y�[�X�B
using namespace GameL;
//�R���X�g���N�^
CObjAttackEnemy2::CObjAttackEnemy2(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjAttackEnemy2::Init()
{
	m_hp = 10;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 0;

	//�����蔻��pHitBox���쐬.
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_ATTACK_ENEMY2, 1);

}
//�A�N�V����
void CObjAttackEnemy2::Action()
{
	m_time++;//1���Z

	if (m_time > 50)
	{
		m_time = 0;
		//�e�ۓG�@object
		CObjBulletEnemy2* obj_b = new CObjBulletEnemy2(m_x, m_y);//�e�۔��˃I�u�W�F�N�g�쐬
		Objs::InsertObj(obj_b, OBJ_BULLET_ENEMY2, 100);//�e�ۓG�@object�o�^
	}
	//�ړ�����
	m_vx = -1.0f;
	m_vy = 0.0f;

	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//���x��t����B
	m_vx *= 1.5f;
	m_vy *= 1.5f;

	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//�ړ��x�N�g�������W�ɉ��Z����B
	m_x += m_vx;
	m_y += m_vy;

	//HitBox�̓��e���X�V�B
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//�G�@�����S�ɗ̈�ɂł���j���B
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);//���g�ɍ폜����
		Hits::DeleteHitBox(this);//�G�@�����L����HITBOX�폜
		return;

	}
	//��l���@object�ƐڐG������G�@�e�ۍ폜�B
	if (hit->CheckObjNameHit(OBJ_HERO5) != nullptr)
	{
		m_del = true; //���Ŏ��s
		hit->SetInvincibility(true);//�����蔻�薳��
	}
	//�e�ۂƐڐG���Ă��邩�ǂ������ׂ�
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
	}

	//HP��0�ɂȂ�����j��
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

	}
	//�e�ۂƐڐG���Ă��邩�ǂ������ׂ�
	if (hit->CheckObjNameHit(OBJ_ANGLE_BULLET_HERO) != nullptr)
	{
		m_hp -= 1;
	}

	//HP��0�ɂȂ�����j��
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	// �e�ۂƐڐG���Ă��邩�ǂ������ׂ�
	if (hit->CheckObjNameHit(OBJ_SITA_BULLET) != nullptr)
	{
		m_hp -= 1;
	}

	//HP��0�ɂȂ�����j��
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	// �e�ۂƐڐG���Ă��邩�ǂ������ׂ�
	if (hit->CheckObjNameHit(OBJ_TATE_BULLET) != nullptr)
	{
		m_hp -= 1;
	}

	//HP��0�ɂȂ�����j��
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	// �e�ۂƐڐG���Ă��邩�ǂ������ׂ�
	if (hit->CheckObjNameHit(OBJ_SITA_LASER_BULLET) != nullptr)
	{
		m_hp -= 1;
	}

	//HP��0�ɂȂ�����j��
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	// �e�ۂƐڐG���Ă��邩�ǂ������ׂ�
	if (hit->CheckObjNameHit(OBJ_TATE_LASER_BULLET) != nullptr)
	{
		m_hp -= 1;
	}

	//HP��0�ɂȂ�����j��
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}
//�h���[
void CObjAttackEnemy2::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,0.5f,0.5f,1.0f };

	RECT_F src;//�`��؂���ʒu
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

	//0�Ԗڂɓo�^�����O���t�B�b�N��`��
	Draw::Draw(3, &src, &dst, c, 0.0f);
}