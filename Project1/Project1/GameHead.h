#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_WIN,
	OBJ_WIN2,
	OBJ_CLEAR_BACK,
	OBJ_CLEAR_VIRUS,
	OBJ_TITLE,
	OBJ_GAME_OVER,
	OBJ_HERO,
	OBJ_SCENE_MAIN,
	OBJ_BULLET,
	OBJ_ENEMY,
	OBJ_ATTACK_ENEMY,
	OBJ_BULLET_ENEMY,
	OBJ_SIN_ENEMY,
	OBJ_BOSS_ENEMY,
	OBJ_BLOCK,
	OBJ_ANGLE_BULLET_HERO,
	OBJ_DIFFUSION_HERO,
	OBJ_HOMING_ENEMY,
	OBJ_DIFFUSION_ENEMY,
	OBJ_HOMING_BULLET,
	OBJ_ITEM,
};
//------------------------------------------------

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{
	int mSeveData;	//�T���v���Z�[�u�f�[�^
	
};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--



//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
//��ʊ֘A
#include "Objwin.h"
#include"Objwin2.h"
#include "ObjClearBack.h"
#include"ObjClearVirus.h"
#include"ObjTitle.h"
#include"ObjSceneMain.h"
//�G�֘A
#include"CObjBulletEnemy.h"
#include"ObjBullet.h"
#include"CObjSinEnemy.h"
#include"ObjAttackEnemy.h"
#include"ObjClearBack.h"
#include"ObjGameOver.h"
#include"ObjSceneMain.h"
#include"ObjHero.h"
#include"ObjEnemy.h"
#include"ObjDiffusionEnemy.h"
#include"ObjEnemyBoss.h"
#include"CObjAngleBulletHero.h"
#include"ObjEnemyBoss2.h"
#include"CObjHomingEnemy.h"
#include"CObjHomingBullet.h"
//�u���b�N�֘A
#include"ObjBlock.h"
//�A�C�e���֘A
#include"Item.h"

//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include"winscene.h"
#include"winscene2.h"
#include"SceneTitle.h"
#include"SceneMain.h"
#include"SceneGameOver.h"
//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START CSceneTitle
//-----------------------------------------------