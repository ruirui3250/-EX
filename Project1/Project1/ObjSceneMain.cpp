//�g�p����l�[���X�y�[�X
#include "GameL\DrawTexture.h"
#include"GameHead.h"
#include"ObjSceneMain.h"
#include"UtilityModule.h"
#include<math.h>

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjSceneMain::Init()
{
	m_x1 = 0.0f;
	m_x2 = 800.0f;
}
//�A�N�V����
void CObjSceneMain::Action()
{
	//�w�i�P�̑���
	m_x1 -= 10.0f;
	if (m_x1 < -800.0f)
		m_x1 = 800;
	//�w�i2�̑���
	m_x2 -= 10.0f;
	if (m_x2 < -800.0f)
		m_x2 = 800;
	//��ʂ���]������
	float ar = 170.0f;

	//���݂̕����̊p�x���l��
	float br = 180.0f;

	float r = 3.14 / 180.0f;//�p�x1
	if (ar < br)
	{
		//����悤�ɃR�����g
		//�ړ�������+1��������
		m_vx = m_vx * cos(r) - m_vy * sin(r);
		m_vy = m_vy * cos(-r) + m_vx * sin(-r);
	}
	
}

//�h���[
void CObjSceneMain::Draw()
{
	//�`��J���[��� R=Red G=Green B=blue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`���؂���ʒu
	RECT_F dst;//�`���\��

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	////�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 500.0f;
	dst.m_bottom = 500.0f;

	////�摜�\��
	Draw::Draw(5, &src, &dst, c, 0.0f);

	//�w�i�P��ݒ�`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 1000.0f + m_x1;
	dst.m_bottom = 600.0f;

	//0�Ԗڂɓo�^�����O���t�B�b�N��`��B
	Draw::Draw(5, &src, &dst, c, 0.0f);

	//�w�i2��ݒ�`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x2;
	dst.m_right = 1000.0f + m_x2;
	dst.m_bottom = 600.0f;

	//0�Ԗڂɓo�^�����O���t�B�b�N��`��B
	Draw::Draw(5, &src, &dst, c, 0.0f);
}