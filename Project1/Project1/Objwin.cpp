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
}

//�h���[
void CObjWin::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	//�o�͂��镶�������
	Font::SetStrTex(L"ENDING�@CREDIT");
	Font::SetStrTex(L"�����f�B���N�^�[�@�����@��");
	Font::SetStrTex(L"�v�����i�[�@���J�@����");
	Font::SetStrTex(L"�v���O���}�[ ��c�@�Ύ�");
	Font::SetStrTex(L"�O���t�B�b�N �Ɩ�@���");
	Font::SetStrTex(L"�T�E���h�f�B���N�^�[�@�g�ԁ@�ڗB");
	Font::SetStrTex(L"���؂肵���y�ȁ@�������l");
}