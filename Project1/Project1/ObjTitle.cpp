//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL/Audio.h"


#include"GameHead.h"
#include"ObjTitle.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	m_key_flag = false;
}
//�A�N�V����
void CObjTitle::Action()
{
	//�G���^�[�L�[�������ăV�[���^�C�g�����ڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}

	//2
	if (Input::GetVKey('2') == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain2());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
	//4
	if (Input::GetVKey('4') == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain4());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
	//5
	if (Input::GetVKey('5') == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain5());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}

}

//�h���[
void CObjTitle::Draw()
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