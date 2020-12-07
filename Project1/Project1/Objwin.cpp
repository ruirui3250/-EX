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
	m_y1 -= 10.0f;
	if (m_y1 < -800.0f)
		m_y1 = 800;
	//�w�i2�̑���
	m_y2 -= 10.0f;
	if (m_y2 < -800.0f)
		m_y2 = 800;
	//��ʂ���]������
	float ar = 170.0f;

	//���݂̕����̊p�x���l��
	float br = 180.0f;

	float r = 3.14 / 180.0f;//�p�x1
	if (ar < br)
	{
		//�ړ�������+1��������
		m_vx = m_vy * cos(r) - m_vx * sin(r);
		m_vy = m_vx * cos(-r) + m_vy * sin(-r);
	}

}

//�h���[
void CObjWin::Draw()
{

}