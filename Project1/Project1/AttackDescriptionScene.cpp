//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SWCURE_SCL(o)
#define _HAS_ITERATOR_DEBUGGING(o)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL/Audio.h"
#include"AttackDescriptionScene.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
//#include "SceneMain.h"
#include "GameHead.h"

//�R���g���N�^
CSceneAttack::CSceneAttack()
{

}

//�f�X�g���N�^
CSceneAttack::~CSceneAttack()
{

}

//�Q�[�����C�����������\�b�h
void CSceneAttack::InitScene()
{
	//�O���O���t�B�b�N�ǂݍ��ݓo�^0��

	Font::SetStrTex(L"������@");
	Font::SetStrTex(L"Z�L�[");
	Font::SetStrTex(L"�ʏ�e����");
	Font::SetStrTex(L"X�L�[");
	Font::SetStrTex(L"�g�U�e���ˁ@��Q����j��\");
	Font::SetStrTex(L"A�L�[");
	Font::SetStrTex(L"���[�U�[���ˁ@�G���т��čU���ł���");
	Font::SetStrTex(L"���[�U�[�Ɗg�U�e�͍���̃Q�[�W���Ȃ��Ȃ�܂Ŏg�p�\");

	//�����I�u�W�F�N�g�o�^
	CObjAttack* obj = new CObjAttack();//�����I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_ATTACK_DESCRIPTION, 10);//�����I�u�W�F�N�g�o�^
}

//�Q�[�����C�����s�����\�b�h
void CSceneAttack::Scene()
{

}