////�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameHead.h"

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
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(1, &src, &dst, c, 0.0f);

}