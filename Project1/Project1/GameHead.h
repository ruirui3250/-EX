#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_WIN,
	OBJ_WIN2,
	OBJ_WIN3,
	OBJ_WIN4,
	OBJ_WIN5,
	OBJ_WIN6,
	OBJ_CLEAR_BACK,
	OBJ_CLEAR_BACK2,
	OBJ_TITLE,
	OBJ_GAME_OVER,
	OBJ_GAME_OVER2,
	OBJ_GAME_OVER3,
	OBJ_GAME_OVER4,
	OBJ_GAME_OVER5,
	OBJ_HERO,
	OBJ_SCENE_MAIN,
	OBJ_SCENE_MAIN2,
	OBJ_SCENE_MAIN4,
	OBJ_BULLET,
	OBJ_ENEMY,
	OBJ_ATTACK_ENEMY,
	OBJ_BULLET_ENEMY,
	OBJ_SIN_ENEMY,
	OBJ_BOSS_ENEMY,
	OBJ_BOSS_ENEMY2,
	OBJ_ANGLE_BULLET_HERO,
	OBJ_DIFFUSION_HERO,
	OBJ_HOMING_ENEMY,
	OBJ_HOMING_BULLET,
	
	OBJLASER_BULLET,
	OBJ_YOKO_KESEN,

	/*----------------�񕜃A�C�e��-------------*/
	OBJ_LIFE_ITEM,
	OBJ_MIGI_LIFE_ITEM,
	OBJ_HIDARI_LIFE_ITEM,
	OBJ_SITA_LIFE_ITEM,
	/*----------�r�[����-------*/
	OBJ_ITEM,
	OBJ_MIGI_ITEM,
	OBJ_HIDARI_ITEM,
	OBJ_SITAITEM,
	/*----------------*/
	OBJ_TATE_ENEMY,
	OBJ_TATE_BOSS,
	OBJ_TATE_ATTACK_ENEMY,
	OBJ_TATE_BULLET_ENEMY,
	OBJ_TATE_HERO,
	OBJ_TATE_BULLET,
	OBJ_TATE_LASER_BULLET,
	OBJ_TATEKESEN,
	OBJ_TATESUKU_SCENE_MAIN,

	/*4�ʗp�l�[��*/
	OBJ_SITA_HERO,
	OBJ_SITA_BULLET,
	OBJ_SITA_LASER_BULLET,
	OBJ_SITA_BULLET_ENEMY,
	OBJ_SITA_ATTACK_ENEMY,
	OBJ_SITA_ENEMY,
	OBJ_SITA_KESEN,
	OBJ_BOSS_ENEMY4,
	OBJ_BOSS_BULLET_ENEMY,
	OBJ_BOSS_BULLET_ENEMY2,

	/*5��*/
	OBJ_SCENE_MAIN5,
	OBJ_BULLET_ENEMY2,
	OBJ_ENEMY2,
	OBJ_ATTACK_ENEMY2,
	OBJ_SITA_ATTACK_ENEMY2,
	OBJ_SITA_ENEMY2,
	OBJ_TATE_ENEMY2,
	OBJ_TATE_ATTACK_ENEMY2,
	OBJ_HERO5,
	OBJ_MIX_BOSS,

	//����
	OBJ_ITEM_DESCRIPTION,
	OBJ_ATTACK_DESCRIPTION,

	OBJ_BOSS_EFFECT,
	OBJ_BOSS_EFFECT2,
	OBJ_BOSS_EFFECT3,
};
//------------------------------------------------

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
	
	/*--------��l���@---*/
	ELEMENT_PLAYER,
	ELEMENT_BULLET,
	ELEMENT_ANGLE_BULLET,
	ELEMENT_LASER_BULLET,
	
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
	ELEMENT_LIFE_ITEM,
	ELEMENT_ITEM,

	/*-----------�G----------*/
	ELEMENT_ENEMY,
	ELEMENT_SIN_ENEMY,
	ELEMENT_ATTACK_ENEMY,
	ELEMENT_BLOCK,
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
#include"Objwin3.h"
#include"Objwin4.h"
#include"ObjWin5.h"
#include"ObjWin6.h"
#include "ObjClearBack.h"
#include"ObjClearBack2.h"
#include"ObjTitle.h"
#include"ObjSceneMain.h"
#include"ObjSceneMain2.h"
#include"ObjSceneMain4.h"
#include"ObjTatesukuSceneMain.h"
#include"TatesukuSceneMain.h"
#include"ObjGameOver.h"
#include"ObjGameOver2.h"
#include"ObjGameOver3.h"
#include"ObjGameOver4.h"
#include"ObjGameOver5.h"
//�G�֘A
#include"CObjBulletEnemy.h"
#include"ObjBullet.h"
#include"CObjSinEnemy.h"
#include"ObjAttackEnemy.h"
#include"ObjSceneMain.h"
#include"ObjHero.h"
#include"ObjHero2.h"
#include"ObjEnemy.h"
#include"ObjDiffusionHero.h"
#include"ObjEnemyBoss.h"
#include"ObjEnemyBoss2.h"
#include"ObjEnemyBoss4.h"
#include"CObjEnemyBossBullet4.h"
#include"CObjEnemyBossBullet2.h"
#include"CObjAngleBulletHero.h"
#include"CObjHomingEnemy.h"
#include"CObjHomingBullet.h"
#include"ObjLaserBullet.h"
#include"ObjYokoKesen.h"
/*---------------------3��---------------*/
#include"CObjTateBulletEnemy.h"
#include"ObjTateAttackEnemy.h"
#include"ObjTateEnemy.h"
#include"ObjTateHero.h"
#include"ObjTateLaserBullet.h"
#include"ObjTateBullet.h"
#include"ObjTatekesen.h"
#include"ObjTateBoss.h"

/*---------------4��--------------*/
#include"ObjSitaHero.h"
#include"ObjSitaBullet.h"
#include"ObjSitaLaserBullet.h"
#include"CObjSitaBulletEnemy.h"
#include"ObjSitaAttackEnemy.h"
#include"ObjSitaKesen.h"
#include"ObjSitaEnemy.h"
/*5��*/
#include"ObjSceneMain5.h"
#include"CObjBulletEnemy2.h"
#include"CObjEnemy2.h"
#include"ObjAttackEnemy2.h"
#include"ObjSitaAttackEnemy2.h"
#include"ObjSitaEnemy2.h"
#include"ObjTateEnemy2.h"
#include"ObjTateAttackEnemy2.h"
#include"ObjHero5.h"
#include"CObjMixBoss.h"
/*----------�񕜃A�C�e��----------------*/
#include"ObjMigiItem.h"
#include"ObjHidariItem.h"
#include"ObjSitaItem.h"
#include"ObjItem.h"
/*-----------�̗�-----------*/
#include"ObjMigiLifeItem.h"
#include"ObjHidariLifeItem.h"
#include"ObjSitaLifeItem.h"
#include"ObjLifeItem.h"
//����
#include"ObjAttackDescriptionScene.h"
#include"ObjItem Description.h"
//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include"winscene.h"
#include"winscene2.h"
#include"winscene3.h"
#include"WinScene4.h"
#include"WinScene5.h"
#include"WinScene6.h"
#include"SceneTitle.h"
#include"SceneMain.h"
#include"SceneMain4.h"
#include"SceneMain2.h"
#include"SceneMain5.h"
#include"TatesukuSceneMain.h"
#include"SceneGameOver.h"
#include"SceneGameOver2.h"
#include"SceneGameOver3.h"
#include"SceneGameOver4.h"
#include"SceneGameOver5.h"
#include"Item DescriptionScene.h"
#include"AttackDescriptionScene.h"

//�{�X�o���G�t�F�N�g
#include"ObjBossEffect.h"
#include"ObjBossEffect2.h"
#include"ObjBossEffect3.h"


//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START CSceneTitle


//
//-----------------------------------------------