//STL�f�o�b�O�@�\���I�t�ɂ���B
#define _SECURE_SCL(o)
#define _HAS_ITERATOR_DEBUGGING(o)

//GameL�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include"GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "winscene2.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneWin2::CSceneWin2()
{

}

//�f�X�g���N�^
CSceneWin2::~CSceneWin2()
{

}

//���������\�b�h
//�����̓o�^
void CSceneWin2::InitScene()
{
	//�O���O���t�B�b�N�ǂݍ��ݓo�^0��
	Draw::LoadImage(L"win���2.png", 0, TEX_SIZE_512);
	////�O���O���t�B�b�N�ǂݍ���1��
	//Draw::LoadImage(L"virusclear.png", 1, TEX_SIZE_512);

	//�N���A�I�u�W�F�N�g�o�^
	CObjWin2* obj = new CObjWin2();//�N���A�I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_WIN2, 10);//�N���A�I�u�W�F�N�g�o�^


		//�N���A���w�i�I�u�W�F�N�g�쐬
	CObjClearback* back = new CObjClearback();
	Objs::InsertObj(back, OBJ_CLEAR_BACK, 0);

	////�N���A�E�C���X�쐬
	//CObjClearvirus* obj2 = new CObjClearvirus();//�N���A�쐬
	//Objs::InsertObj(obj2, OBJ_CLEAR_VIRUS, 1);//�N���A�E�C���X�o�^

}

//���s���\�b�h
void CSceneWin2::Scene()
{

}