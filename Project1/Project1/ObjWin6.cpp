//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"


#include"GameHead.h"
#include"Objwin6.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjWin6::Init()
{
	m_key_flag = false;
	m_y1 = 0;
}
//�A�N�V����
void CObjWin6::Action()
{
		//�G���^�[�L�[�������ăV�[���^�C�g�����ڍs����
		if (Input::GetVKey(VK_RETURN) == true)
		{
			if (m_key_flag == true)
			{
				Scene::SetScene(new CSceneWin());
				m_key_flag = false;
			}
		}
		else
		{
			m_key_flag = true;
		}

	//�w�i�P�̑���
	if (m_y1 > -900.0f)
	{
		m_y1 -= 1.0f;
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
void CObjWin6::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	////�t�H���g�̕\��
	Font::StrDraw(L"�E�C���X�͋쒀����B",0, 200+m_y1, 60, c);
	Font::StrDraw(L"�̓��ɕ��a���K�ꂽ�B", 0, 250+m_y1, 60, c);
	Font::StrDraw(L"������", 0, 400+m_y1, 60, c);
	Font::StrDraw(L"�E�C���X�͑S��", 0,450+m_y1, 60, c);
	Font::StrDraw(L"�쒀���ꂽ�킯�ł͂Ȃ��B", 0, 500 + m_y1, 60, c);
	Font::StrDraw(L"�V�����E�C���X��", 0, 750 + m_y1, 60, c);
	Font::StrDraw(L"�̓��ɐN�����ė����̂�", 0, 800 + m_y1, 60, c);
	Font::StrDraw(L"�킦�I", 0, 1050 + m_y1, 60, c);
	Font::StrDraw(L"�E�C���X�����Ȃ��Ȃ�", 0, 1100 + m_y1, 60, c);
	Font::StrDraw(L"���̓��܂�!!", 0, 1150 + m_y1, 60, c);
	Font::StrDraw(L"�G���^�[�ŃX�^�b�t���[��", 0, 1300 + m_y1, 60, c);
	




}