//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"


#include"GameHead.h"
#include"Objwin4.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjWin4::Init()
{
	m_key_flag = false;
}
//�A�N�V����
void CObjWin4::Action()
{
	/*�G���^�[�L�[�������Ď��̖ʂɈڍs����*/
	/*if (Input::GetVKey(VK_RETURN) == true)
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
	}*/
}

//�h���[
void CObjWin4::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	////�t�H���g�̕\��
	//Font::StrDraw(L"You Win!", 270, 200, 50, c);
	//Font::StrDraw(L"�G���^�[�Ŏ��̃X�e�[�W��!!", 170, 500, 30, c);
}