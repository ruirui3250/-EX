//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SEURE_SCL (o)
#define _HAS_ITERATOR_DEBUGGING (o)
//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
//�g�p�w�b�_�[
#include "SceneGameOver4.h"
#include "GameHead.h"
#include"GameL/Audio.h"
//�R���X�g���N�^
CSceneGameOver4::CSceneGameOver4()
{

}
//�f�X�g���N�^
CSceneGameOver4::~CSceneGameOver4()
{

}
//���������\�b�h
void CSceneGameOver4::InitScene()
{
	//�O���O���t�B�b�N�t�@�C����ǂݍ���6�Ԗڂɓo�^
	Draw::LoadImage(L"GameOver��ʃR���e.png", 0, TEX_SIZE_512);

	//���y�ǂݍ���
	Audio::LoadAudio(16, L"�Q�[���I�[�o�[.wav", BACK_MUSIC);
	//	�Q�[���I�[�o�[�I�u�W�F�N�g�쐬
	CObjGameOver4* obj = new CObjGameOver4();
	Objs::InsertObj(obj, OBJ_GAME_OVER4, 10);

	Audio::Start(16);


}
//�Q�[�����C�����s�����\�b�h
void CSceneGameOver4::Scene()
{

}