//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SWCURE_SCL(o)
#define _HAS_ITERATOR_DEBUGGING(o)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL/Audio.h"
#include"Item DescriptionScene.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
//#include "SceneMain.h"
#include "GameHead.h"

//�R���g���N�^
CSceneItemD::CSceneItemD()
{

}

//�f�X�g���N�^
CSceneItemD::~CSceneItemD()
{

}

//�Q�[�����C�����������\�b�h
void CSceneItemD::InitItemD()
{
	//�O���O���t�B�b�N�ǂݍ��ݓo�^0��

	//�����I�u�W�F�N�g�o�^
	CObjItemD* obj = new CObjItemD();//�����I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_ITEM_DESCRIPTION, 10);//�����I�u�W�F�N�g�o�^
}

//�Q�[�����C�����s�����\�b�h
void CSceneItemD::Scene()
{

}