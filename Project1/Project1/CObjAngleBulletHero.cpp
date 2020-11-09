//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"CObjAngleBulletHero.h"
#include "UtilityModule.h"
//#include"GameL\Audio.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjAngleBulletHero::CObjAngleBulletHero(float x, float y, float r, float speed)
{
	m_x = x;
	m_y = y;
	m_r = r;
	m_speed = speed;
}
//�C�j�V�����C�Y
void CObjAngleBulletHero::Init()
{
	m_eff.m_top = 32;
	m_eff.m_left = 0;
	m_eff.m_right = 32;
	m_eff.m_bottom = 64;
	m_ani = 0;
	m_ani_time = 0;
	m_del = false;


	m_vx = cos(3.14f / 180.0f * m_r);
	m_vy = sin(3.14f / 180.0f * m_r);
	//�ړ��p�x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_BULLET, 1);
}

//�A�N�V����

void CObjAngleBulletHero::Action()
{
	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
	//Resources�̕`�敨��RECT
	m_eff = GetBulletEffect(&m_ani, &m_ani_time, m_del, 2);
	//�e�ۏ��ő��u--------
	if (m_del == true)
	{
		//���e�A�j���[�V�����I���Ŗ{���ɃI�u�W�F�N�g�̔j��
		if (m_del == 4)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
		return;//���ŏ����́A�����ŃA�N�V�������\�b�h���I��������
	}
	//�e�ێ��s����-----
	//�ړ�
	m_x += m_vx * m_speed;
	m_y -= m_vy * m_speed;

	////��l���@�e�ۂ�HitBox�X�V�p�|�C���^�[�擾
	//CHitBox* hit = Hits::GetHitBox(this);
	//hit->SetPos(m_x, m_y);//HitBox�̈ʒu��G�@�e�ۂ̈ʒu�ɍX�V

	//�G�@�g�U�e�ۂ����S�ɗ̈�O����o�����l���@�g�U�e�ۂ�j������
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�G�@�e�ۂ����L����HitBox�ɍ폜����B
	}

	if (m_del == true)
	{

		//�A�j���[�V����RECT���
		RECT_F ani_src[4] =
		{
			{32,0,32,64},
			{32,32,64,64},
			{32,64,96,64},
			{32,96,128,64},
		};
		//�A�j���[�V�����̃R�}���o����
		if (m_ani_time > 2)
		{
			m_ani++;
			m_ani_time = 0;

			m_eff = ani_src[m_ani];//�A�j���[�V������RECT�z�񂩂�m_ani�Ԗڂ�RECT���擾
		}
		else
		{
			m_ani_time++;
		}
		//���e�A�j���[�V�����I���Ŗ{���ɃI�u�W�F�N�g�̔j��
		if (m_ani == 4)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
		return;//���ŏ����́A�����ŃA�N�V�������\�b�h���I��������
	}
	//�G�@�I�u�W�F�N�g�ƐڐG������g�U�e�ۍ폜
	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
	/*	Audio::Start(3);*/
		//m_del = true;//���Ŏ��s
		//hit->SetInvincibility(true);//�G�@�e�ۂ����L����HitBox�ɍ폜����B
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}



}
//�h���[
void CObjAngleBulletHero::Draw()
{
	//�`��J���[���@R=RED G=GREEN B=BLUE A=ALPHA(���ߏ��j
	float c[4] = { 1.0f,1.0f ,1.0f ,1.0f };
	RECT_F dst;//�`���\��
		//�؂���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;
	//6�Ԗڂɓo�^�����O���t�B�b�N��src�E�������E���̏������Ƃɕ`��
	Draw::Draw(6, &m_eff, &dst, c, m_r);

}