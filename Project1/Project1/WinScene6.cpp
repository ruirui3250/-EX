//STL�f�o�b�O�@�\���I�t�ɂ���B
#define _SECURE_SCL(o)
#define _HAS_ITERATOR_DEBUGGING(o)

//GameL�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL/Audio.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "WinScene6.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneWin6::CSceneWin6()
{

}

//�f�X�g���N�^
CSceneWin6::~CSceneWin6()
{

}

//���������\�b�h
//�����̓o�^
void CSceneWin6::InitScene()
{
	////�O���O���t�B�b�N�ǂݍ��ݓo�^0��
	//Draw::LoadImage(L"�Q�[���N���A���.png", 1, TEX_SIZE_512);
	//////�O���O���t�B�b�N�ǂݍ���1��
	////Draw::LoadImage(L"virusclear.png", 1, TEX_SIZE_512);

	//���y�ǂݍ���
	Audio::LoadAudio(21, L"�G���f�B���O�e�[�}.wav", BACK_MUSIC);

	//�N���A�I�u�W�F�N�g�o�^
	CObjWin6* obj = new CObjWin6();//�N���A�I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_WIN6, 10);//�N���A�I�u�W�F�N�g�o�^

	//Font�o�^
	Font::SetStrTex(L"�E�C���X�͋쒀����B");
	Font::SetStrTex(L"�̓��ɕ��a���K�ꂽ�B");
	Font::SetStrTex(L"������");
	Font::SetStrTex(L"�E�C���X�͑S��");
	Font::SetStrTex(L"�쒀���ꂽ�킯�ł͂Ȃ��B");
	Font::SetStrTex(L"�V�����E�C���X��");
	Font::SetStrTex(L"�̓��ɐN�����ė����̂�");
	Font::SetStrTex(L"�킦�I");
	Font::SetStrTex(L"�E�C���X�����Ȃ��Ȃ�");
	Font::SetStrTex(L"���̓��܂�!!");
	Font::SetStrTex(L"�G���^�[�ŃX�^�b�t���[��");

		//�N���A���w�i�I�u�W�F�N�g�쐬
	CObjClearBack2* back = new CObjClearBack2();
	Objs::InsertObj(back, OBJ_CLEAR_BACK2, 0);

	////�N���A�E�C���X�쐬
	//CObjClearvirus* obj2 = new CObjClearvirus();//�N���A�쐬
	//Objs::InsertObj(obj2, OBJ_CLEAR_VIRUS, 1);//�N���A�E�C���X�o�^

	Audio::Start(21);

}

//���s���\�b�h
void CSceneWin6::Scene()
{

}