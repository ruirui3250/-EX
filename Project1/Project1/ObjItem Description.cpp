//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"


#include"GameHead.h"
#include"ObjItem Description.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//CObjWin2::CObjWin2()
//{
//
//}

//�C�j�V�����C�Y
void CObjItemD::Init()
{
	m_key_flag = false;
}
//�A�N�V����
void CObjItemD::Action()
{
	/*�G���^�[�L�[�������Ď��̖ʂɈڍs����*/
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
}

//�h���[
void CObjItemD::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	////�t�H���g�̕\��
		////�t�H���g�̕\��
	Font::StrDraw(L"�A�C�e��", 0, 0, 30, c);
	Font::StrDraw(L"�Ԍ���", 0, 50, 30, c);
	Font::StrDraw(L"�Ԃ����V���Ă���ȉ~�`��̃A�C�e��", 0, 80, 30, c);
	Font::StrDraw(L"���Ƒ̗͂��S�񕜂���B", 0, 120, 30, c);
	Font::StrDraw(L"������", 0, 160, 30, c);
	Font::StrDraw(L"�������V���Ă���ȉ~�`��̃A�C�e��", 0, 210, 30, c);
	Font::StrDraw(L"���ƃ��[�U�[�Ɗg�U�e�̕⋋���o����B", 0, 240, 30, c);
	Font::StrDraw(L"�G���^�[�ŃQ�[���J�n!", 0, 280, 50, c);
}