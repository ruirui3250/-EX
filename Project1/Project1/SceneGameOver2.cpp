//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SEURE_SCL (o)
#define _HAS_ITERATOR_DEBUGGING (o)
//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
//�g�p�w�b�_�[
#include "SceneGameOver2.h"
#include "GameHead.h"
//�R���X�g���N�^
CSceneGameOver2::CSceneGameOver2()
{

}
//�f�X�g���N�^
CSceneGameOver2::~CSceneGameOver2()
{

}
//���������\�b�h
void CSceneGameOver2::InitScene()
{
	//�O���O���t�B�b�N�t�@�C����ǂݍ���6�Ԗڂɓo�^
	Draw::LoadImage(L"GameOver��ʃR���e.png", 0, TEX_SIZE_512);
	//	�Q�[���I�[�o�[�I�u�W�F�N�g�쐬
	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER2, 10);


}
//�Q�[�����C�����s�����\�b�h
void CSceneGameOver2::Scene()
{

}