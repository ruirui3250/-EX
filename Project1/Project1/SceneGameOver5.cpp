//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SEURE_SCL (o)
#define _HAS_ITERATOR_DEBUGGING (o)
//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
//�g�p�w�b�_�[
#include "SceneGameOver5.h"
#include "GameHead.h"
//�R���X�g���N�^
CSceneGameOver5::CSceneGameOver5()
{

}
//�f�X�g���N�^
CSceneGameOver5::~CSceneGameOver5()
{

}
//���������\�b�h
void CSceneGameOver5::InitScene()
{
	//�O���O���t�B�b�N�t�@�C����ǂݍ���6�Ԗڂɓo�^
	Draw::LoadImage(L"GameOver��ʃR���e.png", 0, TEX_SIZE_512);
	//	�Q�[���I�[�o�[�I�u�W�F�N�g�쐬
	CObjGameOver5* obj = new CObjGameOver5();
	Objs::InsertObj(obj, OBJ_GAME_OVER5, 10);


}
//�Q�[�����C�����s�����\�b�h
void CSceneGameOver5::Scene()
{

}