//�g�p�w�b�_�[
#include "GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include "ObjBossYazirusi2.h"
#include"UtilityModule.h"
#include "GameL/DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;
//�R���X�g���N�^
//ObjBossYazirusi::ObjBossYazirusi(float x, float y)
//{
//	m_x = x;
//	m_y = y;
//
//
//}
//�C�j�V�����C�Y
void ObjBossYazirusi2::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	second = 0;
	m_time = 0;
}
//�A�N�V����
void ObjBossYazirusi2::Action()
{
	m_time++;
	if (m_time % 30 == 0)
	{
		second++;
	}
	////�ړ�����
	//m_vx = 0.0f;
	//m_vy = 0.0f;

	////�ړ��x�N�g���̐��K��
	//UnitVec(&m_vy, &m_vx);


	////�̈�O�ɏo����j���B
	//bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	//if (check == false)
	//{
	//	this->SetStatus(false); //���g�ɍ폜���߂��o���B
	//	Hits::DeleteHitBox(this);//�G�@�e�ۂ����L����HitBox���폜
	//	return;
	//}
	//if (m_time == 1450)

	//{
	//	this->SetStatus(false); //���g�ɍ폜���߂��o���B
	//	Hits::DeleteHitBox(this);//�G�@�e�ۂ����L����HitBox���폜
	//	return;
	//}
	//if (m_time==1550)

	//{
	//	this->SetStatus(false); //���g�ɍ폜���߂��o���B
	//	Hits::DeleteHitBox(this);//�G�@�e�ۂ����L����HitBox���폜
	//	return;
	//}
	//if (m_time == 1650)
	//
	//{
	//	this->SetStatus(false); //���g�ɍ폜���߂��o���B
	//	Hits::DeleteHitBox(this);//�G�@�e�ۂ����L����HitBox���폜
	//	return;
	//}
	//if (m_time == 1750)

	//{
	//	this->SetStatus(false); //���g�ɍ폜���߂��o���B
	//	Hits::DeleteHitBox(this);//�G�@�e�ۂ����L����HitBox���폜
	//	return;
	//}
	//if (m_time == 1850)

	//{
	//	this->SetStatus(false); //���g�ɍ폜���߂��o���B
	//	Hits::DeleteHitBox(this);//�G�@�e�ۂ����L����HitBox���폜
	//	return;
	//}
}

//�h���[
void ObjBossYazirusi2::Draw()
{
	//�`��J���[���@R-RED G=GREEN B=BLUE A=ALPHA(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`��؂���ʒu
	RECT_F dst;//�`���\��

	wchar_t str[256];

	swprintf_s(str, L"%d", m_time);
	Font::StrDraw(str, 500, 0, 40, c);

	swprintf_s(str, L"%d", second);
	Font::StrDraw(str, 550, 50, 40, c);

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 250.0f;



	if (second % 2 == 0)
	{
		//�\���ʒu�̐ݒ�
		dst.m_top = 100.0f + m_y;
		dst.m_left = 500.0f + m_x;
		dst.m_right = 700.0f + m_x;
		dst.m_bottom = 400.0f + m_y;

		//0�Ԗڂɓo�^�����O���t�B�b�N��src.dst.c�̏������Ƃɕ`��B
		Draw::Draw(33, &src, &dst, c, 0.0f);

	}


}