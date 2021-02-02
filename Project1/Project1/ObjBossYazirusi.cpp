//�g�p�w�b�_�[
#include "GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include "ObjBossYazirusi.h"
#include"UtilityModule.h""
#include "GameL/DrawFont.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
//�R���X�g���N�^
ObjBossYazirusi::ObjBossYazirusi(float x, float y)
{
	m_x = x;
	m_y = y;
}
//�C�j�V�����C�Y
void ObjBossYazirusi::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 0;
	m_r = 0.0f;
	second = 0;
}

//�A�N�V����
void ObjBossYazirusi::Action()
{
	m_time++;
	if (m_time % 30 == 0)
	{
		second++;
	}



	//�p�x���Z
	m_r += 2.0f;

	//360�ŏ����l�ɖ߂�
	if (m_r > 360.0f)
		m_r = 0.0f;

	//�ړ�����
	m_vx = 0.0f;
	m_vy = sin(3.14 / 180 * m_r);

	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//�ړ��x�N�g�������W�ɉ��Z����
	m_x += m_vx;
	m_y += m_vy;







	if (m_time == 400)
	{
		this->SetStatus(false); //���g�ɍ폜���߂��o���B
		return;
	}

}

//�h���[
void ObjBossYazirusi::Draw()
{
	//�`��J���[���@R-RED G=GREEN B=BLUE A=ALPHA(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`��؂���ʒu
	RECT_F dst;//�`���\��

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 60.0f;
	src.m_bottom = 250.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 100.0f + m_y;
	dst.m_left = 300.0f + m_x;
	dst.m_right = 500.0f + m_x;
	dst.m_bottom = 400.0f + m_y;

	//0�Ԗڂɓo�^�����O���t�B�b�N��src.dst.c�̏������Ƃɕ`��B
	Draw::Draw(33, &src, &dst, c, 0.0f);


	


}