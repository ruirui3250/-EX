//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"


#include"GameHead.h"
#include"Objwin.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjWin::Init()
{
	m_key_flag = false;
	m_y1 = 0;
}
//�A�N�V����
void CObjWin::Action()
{
	//�G���^�[�L�[�������ăV�[���^�C�g�����ڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
	//�w�i�P�̑���
	if (m_y1 > -1900.0f)
	{
		m_y1 -= 2.0f;
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
void CObjWin::Draw()
{
	float c[4]{ 1.0f, 1.0f, 1.0f, 1.0f };
		Font::StrDraw(L"STAFF CREDIT", 150, 300 + m_y1, 100, c);
		Font::StrDraw(L"�����f�B���N�^�[�@���� ��", 0, 450 + m_y1, 50, c);
		Font::StrDraw(L"�v�����i�[ ���J�@����", 0, 600 + m_y1, 50, c);
		Font::StrDraw(L"�`�[�t�v�����i�[ ��c�@�Ύ�", 0, 750 + m_y1, 50, c);
		Font::StrDraw(L"�O���t�B�b�N�f�U�C�i�[�@�Ɩ�@���", 0, 900 + m_y1, 45, c);
		Font::StrDraw(L"�T�E���h�f�B���N�^�[�@�g�ԁ@�ڗB", 0, 1050 + m_y1, 50, c);
		Font::StrDraw(L"���؂肵���y�� �������l", 0, 1300 + m_y1, 50, c);
		Font::StrDraw(L"Congratulation!!", 0, 300, 2000 + m_y1, c);
		Font::StrDraw(L"�G���^�[�Ń^�C�g���ɖ߂�", 0, 2400 + m_y1, 65, c);
}