//STLデバッグ機能をOFFにする。
#define _SECURE_SCL(o)
#define _HAS_ITERATOR_DEBUGGING(o)

//GameLで使用するヘッダー
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include"GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneMain4.h"
#include"GameHead.h"
//コンストラクタ
CSceneMain4::~CSceneMain4()
{

}
//デストラクタ
CSceneMain4::CSceneMain4()
{

}

//ゲームメイン初期化メソッド
void CSceneMain4::InitScene()
{
	//外部グラフィック読み込み0番  背景
	Draw::LoadImage(L"背景(使).png", 5, TEX_SIZE_512);

	Draw::LoadImage(L"敵弾(使).png", 2, TEX_SIZE_512);//敵機弾丸

	Draw::LoadImage(L"注射器下.png", 0, TEX_SIZE_512);

	Draw::LoadImage(L"拡散弾丸.png", 6, TEX_SIZE_512);

	Draw::LoadImage(L"ウイルス(使).png", 7, TEX_SIZE_512);

	Draw::LoadImage(L"障害物.png", 29, TEX_SIZE_512);

	Draw::LoadImage(L"ボス4.png", 4, TEX_SIZE_512);

	Draw::LoadImage(L"レーザー縦.png", 12, TEX_SIZE_512);

	/*Draw::LoadImage(L"敵弾(使).png", 11, TEX_SIZE_512);*/

	Draw::LoadImage(L"主人公弾縦.png", 11, TEX_SIZE_512);//bulletHero

	//Draw::LoadImage(L"縦注射器(使).png", 77, TEX_SIZE_512);//Objhero

	Draw::LoadImage(L"ボスエフェクト.png", 8, TEX_SIZE_512);

	Draw::LoadImage(L"BOSSYAZIRUSITATE.png", 34, TEX_SIZE_512);

	Draw::LoadImage(L"ライフ回復.png", 31, TEX_SIZE_512);

	Draw::LoadImage(L"エナジーチャージ.png", 32, TEX_SIZE_512);

		//音楽読み込み
	Audio::LoadAudio(2, L"銃1.wav", EFFECT);

	//音楽読み込み
	Audio::LoadAudio(4, L"レーザー.wav", EFFECT);

	//音楽読み込み
	Audio::LoadAudio(5, L"拡散弾.wav", EFFECT);

	//音楽読み込み
	Audio::LoadAudio(18, L"敵死亡.wav", EFFECT);

	//音楽読み込み
	Audio::LoadAudio(9, L"4面.wav", BACK_MUSIC);

	//音楽読み込み
	Audio::LoadAudio(14, L"ボス4.wav", BACK_MUSIC);

	//アイテム回復BGM
	Audio::LoadAudio(19, L"HP.wav", EFFECT);

	Audio::LoadAudio(20, L"LK.wav", EFFECT);

	//外部グラフィックファイルを読み込み1番に登録 ボスグラフィックを登録
	//Draw::LoadImage(L"BossBack.png",,TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjSitaHero* obj = new CObjSitaHero();//主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_SITA_HERO, 10);//主人公オブジェクトマネージャーを登録

		//クリア時背景オブジェクト作成
	CObjSceneMain4* back = new CObjSceneMain4();
	Objs::InsertObj(back, OBJ_SCENE_MAIN4, 5);

	//タイム初期化
	m_time = 0;

	Audio::Start(9);

}

//ゲームシーン実行中メソッド
void CSceneMain4::Scene()
{
	m_time++;
	if (m_time == 30)
	{
		CObjSitaAttackEnemy* obj = new CObjSitaAttackEnemy(200.0f, 500);
		Objs::InsertObj(obj, OBJ_SITA_ATTACK_ENEMY,50);
	}
	///*-------------------------回復アイテム出現---------------------------*/
	if (m_time == 700)
	{
		CObjLifeItem* obj = new CObjLifeItem(600.0f, 500);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1000)
	{
		CObjLifeItem* obj = new CObjLifeItem(350.0f, 500);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 300)
	{
		CObjItem* obj = new CObjItem(550.0f, 500);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1300)
	{
		CObjItem* obj = new CObjItem(250.0f, 500);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1500)
	{
		CObjLifeItem* obj = new CObjLifeItem(400.0f, 500);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1750)
	{
		CObjLifeItem* obj = new CObjLifeItem(50.0f, 500);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1800)
	{
		CObjItem* obj = new CObjItem(550.0f, 500);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1400)
	{
		CObjItem* obj = new CObjItem(350.0f, 500);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	/////*-------------------------------敵出現タイミング及び位置制御コード-----------------------------------------------*/
	if (m_time == 30)
	{
		CObjSitaEnemy* obj = new CObjSitaEnemy(350.0f, 500);
		Objs::InsertObj(obj, OBJ_SITA_ENEMY, 50);
		CObjSitaEnemy* obj2 = new CObjSitaEnemy(390.0f, 500);
		Objs::InsertObj(obj2, OBJ_SITA_ENEMY, 50);
		CObjSitaAttackEnemy* obj3 = new CObjSitaAttackEnemy(450.0f, 500);
		Objs::InsertObj(obj3, OBJ_SITA_ATTACK_ENEMY, 50);
		CObjSitaAttackEnemy* obj4 = new CObjSitaAttackEnemy(300.0f, 500);
		Objs::InsertObj(obj4, OBJ_SITA_ATTACK_ENEMY, 50);

	}
	if (m_time == 60)
	{
		CObjSitaKesen* obj = new CObjSitaKesen(500.0f, 500);
		Objs::InsertObj(obj, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj2= new CObjSitaKesen(100.0f, 500);
		Objs::InsertObj(obj2, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj3 = new CObjSitaKesen(50.0f, 500);
		Objs::InsertObj(obj3, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj4 = new CObjSitaKesen(550.0f, 500);
		Objs::InsertObj(obj4, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj5 = new CObjSitaKesen(600.0f, 500);
		Objs::InsertObj(obj5, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj6 = new CObjSitaKesen(650.0f, 500);
		Objs::InsertObj(obj6, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj7 = new CObjSitaKesen(700.0f, 500);
		Objs::InsertObj(obj7, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj8 = new CObjSitaKesen(0.0f, 500);
		Objs::InsertObj(obj8, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj9 = new CObjSitaKesen(750.0f, 500);
		Objs::InsertObj(obj9, OBJ_SITA_KESEN, 50);
	}

	if (m_time == 80)
	{
		CObjSitaEnemy* obj = new CObjSitaEnemy(550.0f, 500);
		Objs::InsertObj(obj, OBJ_SITA_ENEMY, 50);
		CObjSitaAttackEnemy* obj2 = new CObjSitaAttackEnemy(100.0f, 500);
		Objs::InsertObj(obj2, OBJ_SITA_ATTACK_ENEMY, 50);
	}
	if (m_time == 200)
	{
		CObjSitaKesen* obj = new CObjSitaKesen(500.0f, 500);
		Objs::InsertObj(obj, OBJ_SITA_KESEN, 50);
		CObjSitaEnemy* obj2 = new CObjSitaEnemy(0.0f, 500);
		Objs::InsertObj(obj2, OBJ_SITA_ENEMY, 50);
		CObjSitaAttackEnemy* obj3 = new CObjSitaAttackEnemy(350.0f, 500);
		Objs::InsertObj(obj3, OBJ_SITA_ATTACK_ENEMY, 50);
		CObjSitaKesen* obj4 = new CObjSitaKesen(500.0f, 500);
		Objs::InsertObj(obj4, OBJ_SITA_KESEN, 50);
	}
	if (m_time == 300)
	{
		CObjSitaAttackEnemy* obj = new CObjSitaAttackEnemy(250.0f, 500);
		Objs::InsertObj(obj, OBJ_SITA_ATTACK_ENEMY, 50);
		CObjSitaEnemy* obj2 = new CObjSitaEnemy(0.0f, 500);
		Objs::InsertObj(obj2, OBJ_SITA_ENEMY, 50);
		CObjSitaAttackEnemy* obj3 = new CObjSitaAttackEnemy(350.0f, 500);
		Objs::InsertObj(obj3, OBJ_SITA_ATTACK_ENEMY, 50);

		CObjSitaAttackEnemy* obj4 = new CObjSitaAttackEnemy(400.0f, 500);
		Objs::InsertObj(obj4, OBJ_SITA_ATTACK_ENEMY, 50);

		CObjSitaAttackEnemy* obj5 = new CObjSitaAttackEnemy(500.0f, 500);
		Objs::InsertObj(obj5, OBJ_SITA_ATTACK_ENEMY, 50);
	}

	if (m_time == 500)
	{
		CObjSitaAttackEnemy* obj5 = new CObjSitaAttackEnemy(500.0f,500);
		Objs::InsertObj(obj5, OBJ_SITA_ATTACK_ENEMY, 50);
		CObjSitaAttackEnemy* obj6 = new CObjSitaAttackEnemy(450.0f, 500);
		Objs::InsertObj(obj6, OBJ_SITA_ATTACK_ENEMY, 50);

	}
	if (m_time == 600)
	{
		CObjSitaEnemy* obj2 = new CObjSitaEnemy(200.0f, 500);
		Objs::InsertObj(obj2, OBJ_SITA_ENEMY, 50);
		CObjSitaEnemy* obj3 = new CObjSitaEnemy(150.0f, 500);
		Objs::InsertObj(obj3, OBJ_SITA_ENEMY, 50);
	}

	if (m_time == 700)
	{
		CObjSitaKesen* obj = new CObjSitaKesen(500.0f, 500);
		Objs::InsertObj(obj, OBJ_SITA_KESEN, 50);
		CObjSitaEnemy* obj2 = new CObjSitaEnemy(450.0f, 500);
		Objs::InsertObj(obj2, OBJ_SITA_ENEMY, 50);
	}

	if(m_time==900)
	{
		CObjSitaKesen* obj = new CObjSitaKesen(500.0f, 500);
		Objs::InsertObj(obj, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj2 = new CObjSitaKesen(300.0f, 500);
		Objs::InsertObj(obj2, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj3 = new CObjSitaKesen(100.0f, 500);
		Objs::InsertObj(obj3, OBJ_SITA_KESEN, 50);
		CObjSitaEnemy* obj4 = new CObjSitaEnemy(150.0f, 500);
		Objs::InsertObj(obj4, OBJ_SITA_ENEMY, 50);
		CObjSitaEnemy* obj5 = new CObjSitaEnemy(100.0f, 500);
		Objs::InsertObj(obj5, OBJ_SITA_ENEMY, 50);
		CObjSitaAttackEnemy* obj6 = new CObjSitaAttackEnemy(450.0f, 500);
		Objs::InsertObj(obj6, OBJ_SITA_ATTACK_ENEMY, 50);
		CObjSitaAttackEnemy* obj7 = new CObjSitaAttackEnemy(250.0f, 500);
		Objs::InsertObj(obj7, OBJ_SITA_ATTACK_ENEMY, 50);
	}
	if (m_time == 1000)
	{
		CObjEnemyBossBullet4* obj = new CObjEnemyBossBullet4(800.0f, 500);
		Objs::InsertObj(obj, OBJ_BOSS_BULLET_ENEMY, 50);
	}
	if (m_time == 1200)
	{
		CObjSitaAttackEnemy* obj = new CObjSitaAttackEnemy(150.0f, 500);
		Objs::InsertObj(obj, OBJ_SITA_ATTACK_ENEMY, 50);

		CObjSitaAttackEnemy* obj2 = new CObjSitaAttackEnemy(350.0f, 500);
		Objs::InsertObj(obj2, OBJ_SITA_ATTACK_ENEMY, 50);

		CObjSitaEnemy* obj3 = new CObjSitaEnemy(450.0f, 500);
		Objs::InsertObj(obj3, OBJ_SITA_ATTACK_ENEMY, 50);

		CObjSitaEnemy* obj4 = new CObjSitaEnemy(250.0f, 500);
		Objs::InsertObj(obj4, OBJ_SITA_ATTACK_ENEMY, 50);

		CObjSitaAttackEnemy* obj5 = new CObjSitaAttackEnemy(350.0f, 500);
		Objs::InsertObj(obj5, OBJ_SITA_ATTACK_ENEMY, 50);


		CObjSitaKesen* obj6 = new CObjSitaKesen(750.0f, 500);
		Objs::InsertObj(obj6, OBJ_SITA_KESEN, 50);


		CObjSitaKesen* obj7 = new CObjSitaKesen(0.0f, 500);
		Objs::InsertObj(obj7, OBJ_SITA_KESEN, 50);

		CObjSitaAttackEnemy* obj8 = new CObjSitaAttackEnemy(600.0f, 500);
		Objs::InsertObj(obj8, OBJ_SITA_ATTACK_ENEMY, 50);

		CObjSitaAttackEnemy* obj9 = new CObjSitaAttackEnemy(350.0f, 500);
		Objs::InsertObj(obj9, OBJ_SITA_ATTACK_ENEMY, 50);

		CObjSitaEnemy* obj10 = new CObjSitaEnemy(350.0f, 500);
		Objs::InsertObj(obj10, OBJ_SITA_ATTACK_ENEMY, 50);

		CObjSitaAttackEnemy* obj11 = new CObjSitaAttackEnemy(750.0f, 500);
		Objs::InsertObj(obj11, OBJ_SITA_ATTACK_ENEMY, 50);

		CObjSitaAttackEnemy* obj12 = new CObjSitaAttackEnemy(50.0f, 500);
		Objs::InsertObj(obj12, OBJ_SITA_ATTACK_ENEMY, 50);

	}

	if (m_time == 1400)
	{
		CObjSitaKesen* obj1 = new CObjSitaKesen(750.0f, 500);
		Objs::InsertObj(obj1, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj2 = new CObjSitaKesen(150.0f, 500);
		Objs::InsertObj(obj2, OBJ_SITA_KESEN, 50);
	}

	if (m_time == 1600)
	{
		CObjEnemyBossBullet4* obj = new CObjEnemyBossBullet4(0.0f, 500);
		Objs::InsertObj(obj, OBJ_BOSS_BULLET_ENEMY, 50);
		CObjEnemyBossBullet4* obj2 = new CObjEnemyBossBullet4(800.0f, 500);
		Objs::InsertObj(obj2, OBJ_BOSS_BULLET_ENEMY, 50);
	}

	if (m_time == 2000)
	{
		ObjBossEffect3* obj;
		obj = new  ObjBossEffect3(150.0f, 500);
		Objs::InsertObj(obj, OBJ_BOSS_EFFECT3, 50);
	}
	if (m_time == 2100)
	{
		ObjBossYazirusi4* obj = new ObjBossYazirusi4();
		Objs::InsertObj(obj, OBJ_BOSS_YAZIRUSI4, 50);
	}

	///*-------------------------ボス-------------------------------*/
	if (m_time == 2500)
	{
		//音楽チェンジ
		Audio::Stop(9);//0曲ストップ
		Audio::Start(14);//1曲目スタート
		CObjEnemyBoss4* obj = new CObjEnemyBoss4(250,400);
		Objs::InsertObj(obj, OBJ_BOSS_ENEMY4, 100);

	}

}

//メモ
//障害物は１が一番左６００が一番右とする