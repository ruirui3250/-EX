//STLデバッグ機能をOFFにする。
#define _SECURE_SCL(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameLで使用するヘッダー
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include"GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"TatesukuSceneMain.h"
#include"GameHead.h"
//コンストラクタ
TatesukuSceneMain::~TatesukuSceneMain()
{

}
//デストラクタ
TatesukuSceneMain::TatesukuSceneMain()
{

}

//ゲームメイン初期化メソッド
void TatesukuSceneMain::InitScene()
{
	//外部グラフィック読み込み0番  背景
	Draw::LoadImage(L"背景(使).png", 5, TEX_SIZE_512);

	Draw::LoadImage(L"敵弾(使).png", 2, TEX_SIZE_512);//敵機弾丸

	Draw::LoadImage(L"注射器縦.png", 0, TEX_SIZE_512);

	Draw::LoadImage(L"拡散弾丸.png", 6, TEX_SIZE_512);

	Draw::LoadImage(L"ウイルス(使).png", 7, TEX_SIZE_512);

	Draw::LoadImage(L"障害物.png", 29, TEX_SIZE_512);

	Draw::LoadImage(L"Boss3(使).png", 4, TEX_SIZE_512);

	Draw::LoadImage(L"レーザー縦.png", 12, TEX_SIZE_512);

	//Draw::LoadImage(L"敵弾(使).png", 11, TEX_SIZE_512);

	Draw::LoadImage(L"主人公弾縦.png", 11, TEX_SIZE_512);

	Draw::LoadImage(L"ボスエフェクト.png", 8, TEX_SIZE_512);

	Draw::LoadImage(L"BOSSYAZIRUSITATE.png", 34, TEX_SIZE_512);

	Draw::LoadImage(L"ライフ回復.png", 31, TEX_SIZE_512);

	Draw::LoadImage(L"エナジーチャージ.png", 32, TEX_SIZE_512);

	//Draw::LoadImage(L"縦注射器(使).png", 77, TEX_SIZE_512);//Objhero

		//音楽読み込み
	Audio::LoadAudio(2, L"銃1.wav", EFFECT);

	//音楽読み込み
	Audio::LoadAudio(4, L"レーザー.wav", EFFECT);

	//音楽読み込み
	Audio::LoadAudio(5, L"拡散弾.wav", EFFECT);

	//音楽読み込み
	Audio::LoadAudio(18, L"敵死亡.wav", EFFECT);

	//音楽読み込み
	Audio::LoadAudio(8, L"3面.wav", BACK_MUSIC);

	//音楽読み込み
	Audio::LoadAudio(13, L"ボス3.wav", BACK_MUSIC);

	//アイテム回復BGM
	Audio::LoadAudio(19, L"HP.wav", EFFECT);

	Audio::LoadAudio(20, L"LK.wav", EFFECT);

	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((0.8 - v));

	//外部グラフィックファイルを読み込み1番に登録 ボスグラフィックを登録
	//Draw::LoadImage(L"BossBack.png",,TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjTateHero* obj = new CObjTateHero();//主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_TATE_HERO, 10);//主人公オブジェクトマネージャーを登録

		//クリア時背景オブジェクト作成
	CObjTatesukuSceneMain* back = new CObjTatesukuSceneMain();
	Objs::InsertObj(back, OBJ_TATESUKU_SCENE_MAIN, 5);

	//タイム初期化
	m_time = 0;


	Audio::Start(8);

}

//ゲームシーン実行中メソッド
void TatesukuSceneMain::Scene()
{
	m_time++;
	if (m_time == 10)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 30)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(200.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	/*-------------------------回復アイテム出現---------------------------*/
	if (m_time == 800)
	{
		CObjLifeItem* obj = new CObjLifeItem(350.0f, 600);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1200)
	{
		CObjLifeItem* obj = new CObjLifeItem(350.0f, 300);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1800)
	{
		CObjLifeItem* obj = new CObjLifeItem(350.0f, 300);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1500)
	{
		CObjItem* obj = new CObjItem(799.0f, 400);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	//補充アイテム
	if (m_time == 800)
	{
		CObjSitaItem* obj = new CObjSitaItem(350.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1200)
	{
		CObjSitaItem* obj = new CObjSitaItem(210.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1800)
	{
		CObjSitaItem* obj = new CObjSitaItem(210.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	///*-------------------------------敵出現タイミング及び位置制御コード-----------------------------------------------*/
	if (m_time == 30)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(200.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 20)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(300.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 50)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(280.0f, 100);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}



	if (m_time == 80)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(600.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 90)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 70)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(550.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 40)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(650.0f, 100);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 50)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(450.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 60)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(550.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 70)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(600.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 50)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(500.0f, 100);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 60)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(450.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}



	if (m_time == 70)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(600.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 80)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(650.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 70)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(700.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 210)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(450.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 220)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(400.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 220)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(450.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 150)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(480.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	
	/*------------------敵連合部隊第１防衛ライン-----------------*/
	
	if (m_time == 500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(550.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(650.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 550)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(575.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 550)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(625.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 550)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(656.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	/*--------------------敵連合部隊第２防衛ライン------------------------*/
	if (m_time == 700)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(100.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 700)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(300.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 700)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}	
	if (m_time == 700)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(700.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 800)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(150.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 800)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(350.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 800)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(550.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	/*------------------敵連合部隊第３防衛ライン----------------------*/
	if (m_time == 1000)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(100.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1000)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(200.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1000)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(400.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1000)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1000)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(600.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1000)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(700.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	/*------------------------------------------------------------------------*/
	if (m_time == 1500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(400.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1580)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(300.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1580)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(400.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1580)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1580)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1580)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(600.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	/*-----------------------------際---------------------*/
	if (m_time == 1500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(650.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(682.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(700.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(750.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1550)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(650.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1550)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(750.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1550)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(650.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1550)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(682.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1550)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(700.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1560)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(780.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1550)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(150.0f, 0);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	




	/*----------------------------障害物出現------------------------------*/
	if (m_time == 300)
	{
		CObjTateKesen* obj = new CObjTateKesen(10.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 300)
	{
		CObjTateKesen* obj = new CObjTateKesen(150.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 300)
	{
		CObjTateKesen* obj = new CObjTateKesen(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 300)
	{
		CObjTateKesen* obj = new CObjTateKesen(700.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	/*------------------------------------------------------------*/
	if (m_time == 500)
	{
		CObjTateKesen* obj = new CObjTateKesen(10.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 500)
	{
		CObjTateKesen* obj = new CObjTateKesen(400.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 500)
	{
		CObjTateKesen* obj = new CObjTateKesen(700.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	/*---------------------------------------------------------*/
	if (m_time == 1000)
	{
		CObjTateKesen* obj = new CObjTateKesen(450.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1000)
	{
		CObjTateKesen* obj = new CObjTateKesen(700.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1000)
	{
		CObjTateKesen* obj = new CObjTateKesen(10.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}

	if (m_time == 1200)																	//このタイミングで左側に普通の敵機出現させること
	{
		CObjTateKesen* obj = new CObjTateKesen(700.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1200)
	{
		CObjTateKesen* obj = new CObjTateKesen(300.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1200)
	{
		CObjTateKesen* obj = new CObjTateKesen(300.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	/*-------------------------敵機挿入-----------------------*/
	if (m_time == 1200)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(100.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1210)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(30.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1220)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(40.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1200)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(50.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1150)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(250.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1210)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(300.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1220)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(350.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}


	if (m_time == 1500)
	{
		CObjTateKesen* obj = new CObjTateKesen(10.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1500)
	{
		CObjTateKesen* obj = new CObjTateKesen(250.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}

	if (m_time == 1500)
	{
		CObjTateKesen* obj = new CObjTateKesen(550.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}

	
	if (m_time == 2000)
	{
		CObjSitaItem* obj = new CObjSitaItem(210.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 2000)
	{
		ObjBossEffect2* obj;
		obj = new  ObjBossEffect2(150.0f, 0);
		Objs::InsertObj(obj, OBJ_BOSS_EFFECT2, 50);
	}
	if (m_time == 2100)
	{
		ObjBossYazirusi3* obj;
		obj = new  ObjBossYazirusi3(60.0f, 1);
		Objs::InsertObj(obj, OBJ_BOSS_YAZIRUSI3, 50);
	
	}
	/*-------------------------ボス-------------------------------*/
	if (m_time == 2500)
	{	
		//音楽チェンジ
		Audio::Stop(8);//0曲ストップ
		Audio::Start(13);//1曲目スタート
		CObjTateBoss* obj = new CObjTateBoss(200.0f, 100);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);

	}
	/*------------------------------アイテム発射--------------------*/
	
}

//メモ
//障害物は１が一番左６００が一番右とする