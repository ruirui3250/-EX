//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameHead.h"
#include"ObjAttackDescriptionScene.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjAttack::Init()
{
	m_key_flag = false;
}
//�A�N�V����
void CObjAttack::Action()
{
	/*�G���^�[�L�[�������Ď��̖ʂɈڍs����*/
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneItemD());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjAttack::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	////�t�H���g�̕\��
	Font::StrDraw(L"������@", 0, 0, 30, c);
	Font::StrDraw(L"Z�L�[", 0, 50, 30, c);
	Font::StrDraw(L"�ʏ�e����", 0, 80, 30, c);
	Font::StrDraw(L"X�L�[", 0, 130, 30, c);
	Font::StrDraw(L"�g�U�e���ˁ@��Q����j��\", 0, 160, 30, c);
	Font::StrDraw(L"A�L�[", 0, 210, 30, c);
	Font::StrDraw(L"���[�U�[���ˁ@�G���т��čU���ł���", 0, 240, 30, c);
	Font::StrDraw(L"���[�U�[�Ɗg�U�e�͍���̃Q�[�W���Ȃ��Ȃ�܂Ŏg�p�\", 0, 300, 30, c);
	Font::StrDraw(L"�G���^�[�Ŏ��̃y�[�W��", 0, 360, 50, c);
}