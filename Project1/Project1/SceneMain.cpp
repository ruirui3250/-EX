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
#include"SceneMain.h"
#include"GameHead.h"
//コンストラクタ
CSceneMain::CSceneMain()
{

}
//デストラクタ
CSceneMain::~CSceneMain()
{

}

//ゲームメイン初期化メソッド
void CSceneMain::InitScene()
{
	//外部グラフィック読み込み0番  背景
	Draw::LoadImage(L"背景(使).png", 9, TEX_SIZE_512);

	Draw::LoadImage(L"ウイルス(使).png", 3, TEX_SIZE_512);

	Draw::LoadImageW(L"敵弾(使).png", 5, TEX_SIZE_512);

	Draw::LoadImage(L"注射器.png", 0, TEX_SIZE_512);

	Draw::LoadImage(L"カプセル.png", 1, TEX_SIZE_512);


	//Draw::LoadImage(L"障害物.png",9, TEX_SIZE_512);
	Draw::LoadImage(L"レーザー.png", 10, TEX_SIZE_512);

	Draw::LoadImage(L"拡散弾丸.png",6, TEX_SIZE_512);
	//外部グラフィックファイルを読み込み1番に登録 ボスグラフィックを登録
	Draw::LoadImage(L"Boss1(使).png",4,TEX_SIZE_512);

	Draw::LoadImage(L"障害物.png", 29, TEX_SIZE_512);

	Draw::LoadImage(L"ボスエフェクト.png",8, TEX_SIZE_512);

	Draw::LoadImage(L"BOSSYAZIRUSI.png", 33, TEX_SIZE_512);

	Draw::LoadImage(L"ライフ回復.png", 31, TEX_SIZE_512);

	Draw::LoadImage(L"エナジーチャージ.png", 32, TEX_SIZE_512);

	//音楽読み込み
	Audio::LoadAudio(2, L"銃1.wav", EFFECT);

	//音楽読み込み
	Audio::LoadAudio(4, L"レーザー.wav", EFFECT);

	//音楽読み込み
	Audio::LoadAudio(5, L"拡散弾.wav", EFFECT);
	//アイテム回復BGM
	Audio::LoadAudio(19, L"HP.wav", EFFECT);

	Audio::LoadAudio(20, L"LK.wav", EFFECT);

	//音楽読み込み
	Audio::LoadAudio(18, L"敵死亡.wav", EFFECT);

	//音楽読み込み
	Audio::LoadAudio(6, L"1面.wav", BACK_MUSIC);

	//音楽読み込み
	Audio::LoadAudio(11, L"ボス1.wav", BACK_MUSIC);

	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((0.8 - v));

	Audio::Start(6);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();//主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 10);//主人公オブジェクトマネージャーを登録

	////blockオブジェクト作成
	//CObjBlock* objb = new CObjBlock();
	//Objs::InsertObj(objb, OBJ_BLOCK, 9);

		//クリア時背景オブジェクト作成
	CObjSceneMain* back = new CObjSceneMain();
	Objs::InsertObj(back, OBJ_SCENE_MAIN, 9);

	//タイム初期化
	m_time = 0;

}

//ゲームシーン実行中メソッド
void CSceneMain::Scene()
{
	m_time++;



//アイテム制御
	
	if (m_time ==400)
	{
		CObjHidariItem* obj = new CObjHidariItem(799.0f, 400);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}

	if (m_time == 650)
	{
		CObjHidariLifeItem* obj = new CObjHidariLifeItem(799.0f, 250);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 840)
	{
		CObjHidariItem* obj = new CObjHidariItem(799.0f, 145);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1170)
	{
		CObjHidariLifeItem* obj = new CObjHidariLifeItem(799.0f, 250);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}

	
	/*-----て--------き--------敵*/
	if (m_time == 30)
	{
		CObjEnemy* obj = new CObjEnemy(799.0f, 400);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);

		CObjAttackEnemy* obj1;
		obj1 = new CObjAttackEnemy(799, 230);
		Objs::InsertObj(obj1, OBJ_ATTACK_ENEMY, 50);

		/*CObjAttackEnemy* obj2;
		obj2 = new CObjAttackEnemy(799, 330);
		Objs::InsertObj(obj2, OBJ_ATTACK_ENEMY, 50);*/

		CObjEnemy* obj3 = new CObjEnemy(650.0f, 130);
		Objs::InsertObj(obj3, OBJ_ENEMY, 50);

		CObjEnemy* obj4 = new CObjEnemy(799.0f, 160);
		Objs::InsertObj(obj4, OBJ_ENEMY, 50);

		CObjHomingEnemy* obj2;
		obj2 = new CObjHomingEnemy(799.0f, 150);
		Objs::InsertObj(obj2, OBJ_HOMING_ENEMY, 50);

	}
	else if (m_time == 40)
	{
		//block object create
		CObjYokoKesen* obj = new CObjYokoKesen(799.0f, 0);
		Objs::InsertObj(obj, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj1 = new CObjYokoKesen(766, 0);
		Objs::InsertObj(obj1, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj2 = new CObjYokoKesen(733, 0);
		Objs::InsertObj(obj2, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj3 = new CObjYokoKesen(799.0f, 33);
		Objs::InsertObj(obj3, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj4 = new CObjYokoKesen(766,33);
		Objs::InsertObj(obj4, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj5 = new CObjYokoKesen(733,33);
		Objs::InsertObj(obj5, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj6 = new CObjYokoKesen(799.0f, 66);
		Objs::InsertObj(obj6, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj7 = new CObjYokoKesen(766, 66);
		Objs::InsertObj(obj7, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj8 = new CObjYokoKesen(733, 66);
		Objs::InsertObj(obj8, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj9 = new CObjYokoKesen(733, 566);
		Objs::InsertObj(obj9, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj10 = new CObjYokoKesen(766, 566);
		Objs::InsertObj(obj10, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj11 = new CObjYokoKesen(799.0f, 566);
		Objs::InsertObj(obj11, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj12 = new CObjYokoKesen(733, 533);
		Objs::InsertObj(obj12, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj13 = new CObjYokoKesen(766, 533);
		Objs::InsertObj(obj13, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj14 = new CObjYokoKesen(799.0f, 533);
		Objs::InsertObj(obj14, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj15 = new CObjYokoKesen(733, 500);
		Objs::InsertObj(obj15, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj16 = new CObjYokoKesen(766, 500);
		Objs::InsertObj(obj16, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj17 = new CObjYokoKesen(799.0f, 500);
		Objs::InsertObj(obj17, OBJ_YOKO_KESEN, 50);
	}

	else if (m_time == 110)
	{
		//block object create
		CObjYokoKesen* obj = new CObjYokoKesen(799.0f, 0);
		Objs::InsertObj(obj, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj1 = new CObjYokoKesen(766, 0);
		Objs::InsertObj(obj1, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj2 = new CObjYokoKesen(733, 0);
		Objs::InsertObj(obj2, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj3 = new CObjYokoKesen(799.0f, 33);
		Objs::InsertObj(obj3, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj4 = new CObjYokoKesen(766, 33);
		Objs::InsertObj(obj4, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj5 = new CObjYokoKesen(733, 33);
		Objs::InsertObj(obj5, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj6 = new CObjYokoKesen(799.0f, 66);
		Objs::InsertObj(obj6, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj7 = new CObjYokoKesen(766, 66);
		Objs::InsertObj(obj7, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj8 = new CObjYokoKesen(733, 66);
		Objs::InsertObj(obj8, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj9 = new CObjYokoKesen(733, 566);
		Objs::InsertObj(obj9, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj10 = new CObjYokoKesen(766, 566);
		Objs::InsertObj(obj10, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj11 = new CObjYokoKesen(799.0f, 566);
		Objs::InsertObj(obj11, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj12 = new CObjYokoKesen(733, 533);
		Objs::InsertObj(obj12, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj13 = new CObjYokoKesen(766, 533);
		Objs::InsertObj(obj13, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj14 = new CObjYokoKesen(799.0f, 533);
		Objs::InsertObj(obj14, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj15 = new CObjYokoKesen(733, 500);
		Objs::InsertObj(obj15, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj16 = new CObjYokoKesen(766, 500);
		Objs::InsertObj(obj16, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj17 = new CObjYokoKesen(799.0f, 500);
		Objs::InsertObj(obj17, OBJ_YOKO_KESEN, 50);
	}
	else if (m_time == 450)
	{
		CObjEnemy* obj;
		obj = new CObjEnemy(799.0f, 300);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
		obj = new CObjEnemy(799.0f, 350);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
		obj = new CObjEnemy(799.0f, 250);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);

		CObjAttackEnemy* obj2;
		obj2 = new CObjAttackEnemy(799.0f, 200);
		Objs::InsertObj(obj2, OBJ_ATTACK_ENEMY, 50);
		obj2 = new CObjAttackEnemy(799.0f, 400);
		Objs::InsertObj(obj2, OBJ_ATTACK_ENEMY, 50);

		CObjHomingEnemy* obj3;
		obj3 = new CObjHomingEnemy(799.0f, 250);
		Objs::InsertObj(obj3, OBJ_HOMING_ENEMY, 50);

	}
	else if (m_time == 550)
	{
	//block object create
	CObjYokoKesen* obj = new CObjYokoKesen(799.0f, 0);
	Objs::InsertObj(obj, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj1 = new CObjYokoKesen(766, 0);
	Objs::InsertObj(obj1, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj2 = new CObjYokoKesen(733, 0);
	Objs::InsertObj(obj2, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj3 = new CObjYokoKesen(799.0f, 33);
	Objs::InsertObj(obj3, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj4 = new CObjYokoKesen(766, 33);
	Objs::InsertObj(obj4, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj5 = new CObjYokoKesen(733, 33);
	Objs::InsertObj(obj5, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj6 = new CObjYokoKesen(799.0f, 66);
	Objs::InsertObj(obj6, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj7 = new CObjYokoKesen(766, 66);
	Objs::InsertObj(obj7, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj8 = new CObjYokoKesen(733, 66);
	Objs::InsertObj(obj8, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj9 = new CObjYokoKesen(733, 566);
	Objs::InsertObj(obj9, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj10 = new CObjYokoKesen(766, 566);
	Objs::InsertObj(obj10, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj11 = new CObjYokoKesen(799.0f, 566);
	Objs::InsertObj(obj11, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj12 = new CObjYokoKesen(733, 533);
	Objs::InsertObj(obj12, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj13 = new CObjYokoKesen(766, 533);
	Objs::InsertObj(obj13, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj14 = new CObjYokoKesen(799.0f, 533);
	Objs::InsertObj(obj14, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj15 = new CObjYokoKesen(733, 500);
	Objs::InsertObj(obj15, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj16 = new CObjYokoKesen(766, 500);
	Objs::InsertObj(obj16, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj17 = new CObjYokoKesen(799.0f, 500);
	Objs::InsertObj(obj17, OBJ_YOKO_KESEN, 50);

	}
	else if (m_time == 780)
	{
	CObjYokoKesen* obj = new CObjYokoKesen(799.0f, 300);
	Objs::InsertObj(obj, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj2 = new CObjYokoKesen(799.0f, 277);
	Objs::InsertObj(obj2, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj3 = new CObjYokoKesen(799.0f, 244);
	Objs::InsertObj(obj3, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj4 = new CObjYokoKesen(766.0f, 300);
	Objs::InsertObj(obj4, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj5 = new CObjYokoKesen(766.0f, 277);
	Objs::InsertObj(obj5, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj1 = new CObjYokoKesen(766.0f, 244);
	Objs::InsertObj(obj1, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj6 = new CObjYokoKesen(733.0f, 300);
	Objs::InsertObj(obj6,OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj7 = new CObjYokoKesen(733.0f, 277);
	Objs::InsertObj(obj7, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj8 = new CObjYokoKesen(733.0f, 244);
	Objs::InsertObj(obj8, OBJ_YOKO_KESEN, 50);


	}
	else if (m_time == 850)
	{
	CObjHomingEnemy* obj;
	obj = new CObjHomingEnemy(799.0f, 460);
	}
	else if (m_time == 890)
	{
	CObjAttackEnemy* obj;
	obj = new CObjAttackEnemy(799.0f, 450);
	}
	else if (m_time == 850)
	{
	CObjEnemy* obj;
	obj = new CObjEnemy(799.0, 305);
	}
	else if (m_time == 500)
	{
	CObjHomingEnemy* obj;
	obj = new CObjHomingEnemy(799.0f, 0);
	Objs::InsertObj(obj, OBJ_HOMING_ENEMY, 50);
	}
	/*---------------------BOSS----------------------*/
	else if (m_time == 1200)
	{
	ObjBossEffect* obj;
	obj = new  ObjBossEffect(733.0f, 177);
	Objs::InsertObj(obj, OBJ_BOSS_EFFECT, 50);
     }
	if (m_time == 1300)
	{
	ObjBossYazirusi* obj;
	obj = new  ObjBossYazirusi(200.0f, 100);
	Objs::InsertObj(obj, OBJ_BOSS_YAZIRUSI, 50);
	}
	if (m_time == 1700)
	
	{
		//音楽チェンジ
		Audio::Stop(6);//0曲ストップ
		Audio::Start(11);//1曲目スタート

		CObjBoss* obj;
		obj = new CObjBoss(300, 0);
		Objs::InsertObj(obj, OBJ_BOSS_ENEMY, 50);
	}
}