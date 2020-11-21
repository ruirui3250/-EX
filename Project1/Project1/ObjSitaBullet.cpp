//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"ObjSitaBullet.h"
#include"UtilityModule.h"
//#include"GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjSitaBullet::CObjSitaBullet(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjSitaBullet::Init()
{

	m_ani = 0;
	m_ani_time = 0;
	m_del = false;
	m_vy = +1.0f;
	//�����蔻��HItBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_BULLET, 1);
}
//�A�N�V����
void CObjSitaBullet::Action()
{

	//�e�ێ��s����
	/*m_vy -= 1.0f;
	m_y -= m_vy;*/
	m_y += 10.0f;
	//Resources�̕`�敨RECT
	m_eff = GetBulletEffect(&m_ani, &m_ani_time, m_del, 1);

	//�e�ۏ��ŏ���
	if (m_del == true)
	{
		//���e�A�j���[�V�����I���Ŗ{���ɃI�u�W�F�N�g�̔j���B
		if (m_ani == 4)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
		return;
		//���ŏ����́A�����ŃA�N�V�������\�b�h���I�������B
	}


	//�e�ۂ�HitBox�X�V�p�|�C���^�[�擾
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);//HitBox�̈ʒu��e�ۂ̈ʒu���X�V

	//�̈�O�ɏo����e�۔j��
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false); //���g�ɍ폜���߂��o���B
		Hits::DeleteHitBox(this);//�G�@�e�ۂ����L����HitBox���폜
		return;
	}

	////�G�@�I�u�W�F�N�g�ɂԂ�������e�ۍ폜�B
	//if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	//{
	//	this->SetStatus(false); //���g�ɍ폜����
	//	Hits::DeleteHitBox(this);//�e�ۂ����L����HITBOX�폜
	//}

	//�����蔻����s���I�u�W�F�N�g���
	int data_base[6] =
	{
		OBJ_ENEMY,
		OBJ_ATTACK_ENEMY,
		/*	OBJ_DIFFUSION_ENEMY,
			OBJ_HOMING_ENEMY,
			OBJ_BOSS_ENEMY,*/
	};

	//�I�u�W�F�N�g��񕔂ɓ����蔻����s���B������΍폜�B
	for (int i = 0; i < 6; i++)
	{
		if (hit->CheckObjNameHit(data_base[i]) != nullptr)
		{
			//Audio::Start(3);
			m_del = true; //���Ŏ��s
			hit->SetInvincibility(true);//�����蔻�薳��
		}
	}

}
//�h���[
void CObjSitaBullet::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F dst;//�`���\��
	RECT_F src;


	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;
	//�؂���ʒu�̐ݒ�
	src.m_top = 0;
	src.m_left = 0;
	src.m_right = 32;
	src.m_bottom = 32;
	//0�Ԗڂɓo�^�����O���t�B�b�N��`��B
	Draw::Draw(1, &src, &dst, c, 0.0f);
}