//�g�p����w5�b�_�[�t�@�C��INput
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "ObjHero.h"
#include"GameL\HitBoxManager.h"


//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_hp = 3;
	m_x = 6;
	//�����蔻��phitbox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_HERO, 100);

	//block�̏Փˏ�Ԃ̊m�F�p
	m_hit_up=false;
	m_hit_down=false;
	m_hit_left=false;
	m_hit_right=false;
}

//�A�N�V����
/*--------------------��l���̒e------------------------------*/
void CObjHero::Action()
{
	//��l���@�̒e�۔���
	if (Input::GetVKey('Z') == true)
	{
		if (m_f == true)
		{

			//�e�ۃI�u�W�F�N�g�쐬
			CObjBullet* obj_b = new CObjBullet(m_x + 30.0f, m_y + 3.0f);//�e�ۃI�u�W�F�N�g
			Objs::InsertObj(obj_b, OBJ_BULLET, 100);//������e�ۃI�u�W�F�N�g
			m_f = false;
		}
	}
	//��l���@�̊g�U�e����
	if (Input::GetVKey('X') == true)
	{
		if (m_f == true)
		{

			//�e�ۃI�u�W�F�N�g�쐬
			CObjAngleBulletHero* obj_b = new CObjAngleBulletHero (m_x + 30.0f, m_y + 3.0f);//�e�ۃI�u�W�F�N�g
			Objs::InsertObj(obj_b, OBJ_ANGLEBULLET_HERO, 100);//������e�ۃI�u�W�F�N�g
			m_f = false;
		}
		else
		{
			m_f = true;
		}
		
	}
	/*-------------------------��l���̈ړ�---------------------*/
	//��l���@�̈ړ�
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_x += 6.0f;

	}
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_x -= 6.0f;

	}
	if (Input::GetVKey(VK_UP) == true)

	{
		m_y -= 6.0f;
	}
	if (Input::GetVKey(VK_DOWN) == true)

	{
		m_y += 6.0f;
	}

	//��l�����̈�O�ɍs���Ȃ�����
	if (m_x + 32.0 > 800.0f)
	{
		m_x = 800.0f - 32.0f;//���_�Ɉړ�
	}
	if (m_y + 32.0 > 600.0f)
	{
		m_y = 600.0f - 32.0f;
	}
	if (m_y < 0.0f)
	{
		m_y = 0.0f;
	}
	if (m_x < 0.0f)
	{
		m_x = 0.0f;
	}


	//HITbox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this); //�쐬����hitBox�X�V�p�̓���������o��
	hit->SetPos(m_x, m_y);				  //���������V�����ʒu�i��l���@�̈ʒu�j���ɒu��������
	//ELEMENT_ENEMY�����I�u�W�F�N�g�ƐڐG�������l���@�폜
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//��l�������L����HitBox�ɑ������

		//��l���@���łŃV�[�����Q�[���I�[�o�[�Ɉڍs����
		Scene::SetScene(new CSceneGameOver());
	}
	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;
}
//�h���[
void CObjHero::Draw()
{
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f, };
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu
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

	Draw::Draw(1, &src, &dst, c, 0.0f);
}