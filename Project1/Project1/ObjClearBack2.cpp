////�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "GameL\DrawFont.h"
#include"ObjClearBack2.h"

////�g�p����l�[���X�y�[�X
using namespace GameL;

////�C�j�V�����C�Y
void CObjClearBack2::Init()
{

}

//�A�N�V����
void CObjClearBack2::Action()
{
	//�w�i�P�̑���
	if (m_y1 > -1900.0f)
	{
		m_y1 -= 3.0f;
	}
	////�w�i2�̑���
	//m_y2 -= 10.0f;
	//if (m_y2 < -800.0f)
	//	m_y2 = 800;
	////��ʂ���]������
	//float ar = 170.0f;

	////���݂̕����̊p�x���l��
	//float br = 180.0f;

	//float r = 3.14 / 180.0f;//�p�x1
	//if (ar < br)
	//{
	//	//�ړ�������+1��������
	//	m_vx = m_vy * cos(r) - m_vx * sin(r);
	//	m_vy = m_vx * cos(-r) + m_vy * sin(-r);
	//}
	//�^�C��������
	m_time = 0;
}

//�h���[
void CObjClearBack2::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`��؂���ʒu
	RECT_F dst;//�`���\��

	//�؂���ʒu
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0;
	dst.m_bottom = 600.0f;

	Draw::Draw(1, &src, &dst, c, 0.0f);

}