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

	Draw::LoadImage(L"障害物.png", 8, TEX_SIZE_512);

	Draw::LoadImage(L"Boss3(使).png", 4, TEX_SIZE_512);

	Draw::LoadImage(L"レーザー.png", 10, TEX_SIZE_512);

	Draw::LoadImage(L"敵弾(使).png", 11, TEX_SIZE_512);

	Draw::LoadImage(L"主人公弾縦.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"ライフ回復.png", 31, TEX_SIZE_512);

	Draw::LoadImage(L"エナジーチャージ.png", 32, TEX_SIZE_512);

	//Draw::LoadImage(L"縦注射器(使).png", 77, TEX_SIZE_512);//Objhero

		//音楽読み込み
	Audio::LoadAudio(2, L"銃1.wav", EFFECT);

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

}

//ゲームシーン実行中メソッド
void TatesukuSceneMain::Scene()
{
	m_time++;
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
	if (m_time == 40)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(400.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 50)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(280.0f, 100);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 60)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(250.0f, 10);
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
	if (m_time == 30)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(550.0f, 10);
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
	if (m_time == 110)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(450.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 120)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(400.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 130)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(410.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 120)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(350.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 110)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(350.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 120)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 150)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(550.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	/*------------------敵連合部隊第１防衛ライン-----------------*/
	if (m_time == 400)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(550.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 400)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 400)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(550.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 400)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(600.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 400)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(650.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 400)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(700.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}

	if (m_time == 400)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(550.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 400)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(500.0f, 10);
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
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(200.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 700)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(300.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 700)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(400.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 700)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}	
	if (m_time == 700)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(600.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 700)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(700.0f, 10);
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
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(100.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(200.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(300.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
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
	if (m_time == 1500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(600.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(650.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(700.0f, 10);
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
	if (m_time == 600)
	{
		CObjTateKesen* obj = new CObjTateKesen(10.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 600)
	{
		CObjTateKesen* obj = new CObjTateKesen(300.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 600)
	{
		CObjTateKesen* obj = new CObjTateKesen(700.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	/*---------------------------------------------------------*/
	if (m_time == 900)
	{
		CObjTateKesen* obj = new CObjTateKesen(450.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 900)
	{
		CObjTateKesen* obj = new CObjTateKesen(700.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 900)
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
		CObjTateKesen* obj = new CObjTateKesen(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	/*-------------------------敵機挿入-----------------------*/
	if (m_time == 1200)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(100.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1150)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(200.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1210)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(150.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1220)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(50.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1200)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(120.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1150)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(180.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1210)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(270.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1220)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(230.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}

	if (m_time == 1200)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(10.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1150)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(20.0f, 10);
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
		CObjTateKesen* obj = new CObjTateKesen(290.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}

	if (m_time == 1500)
	{
		CObjTateKesen* obj = new CObjTateKesen(800.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}

	if (m_time == 00)
	{
		CObjTateKesen* obj = new CObjTateKesen(.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 00)
	{
		CObjTateKesen* obj = new CObjTateKesen(.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 00)
	{
		CObjTateKesen* obj = new CObjTateKesen(.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 00)
	{
		CObjTateKesen* obj = new CObjTateKesen(.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 00)
	{
		CObjTateKesen* obj = new CObjTateKesen(.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 00)
	{
		CObjTateKesen* obj = new CObjTateKesen(.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 00)
	{
		CObjTateKesen* obj = new CObjTateKesen(.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 00)
	{
		CObjTateKesen* obj = new CObjTateKesen(.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}

	/*-------------------------ボス-------------------------------*/
	if (m_time == 2000)
	{
		CObjTateBoss* obj = new CObjTateBoss(200.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);

	}
	/*------------------------------アイテム発射--------------------*/
	
}

//メモ
//障害物は１が一番左６００が一番右とする