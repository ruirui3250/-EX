#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
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

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
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
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
//画面関連
#include "Objwin.h"
#include"Objwin2.h"
#include "ObjClearBack.h"
#include"ObjClearVirus.h"
#include"ObjTitle.h"
#include"ObjSceneMain.h"
//敵関連
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
//ブロック関連
#include"ObjBlock.h"
//アイテム関連
#include"Item.h"

//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include"winscene.h"
#include"winscene2.h"
#include"SceneTitle.h"
#include"SceneMain.h"
#include"SceneGameOver.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneTitle
//-----------------------------------------------