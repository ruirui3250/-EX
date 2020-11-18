//STLデバッグ機能をOFFにする。
#define _SECURE_SCL(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameLで使用するヘッダー
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include"GameL\Audio.h"

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

	Draw::LoadImage(L"注射器(使).png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"カプセル.png", 2, TEX_SIZE_512);

	//Draw::LoadImage(L"障害物.png",9, TEX_SIZE_512);

	Draw::LoadImage(L"拡散弾丸.png",6, TEX_SIZE_512);
	//外部グラフィックファイルを読み込み1番に登録 ボスグラフィックを登録
	Draw::LoadImage(L"Boss1(使).png",4,TEX_SIZE_512);

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

	if (m_time == 30)
	{
		CObjEnemy* obj = new CObjEnemy(799.0f, 400);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);

		CObjAttackEnemy* obj1;
		obj1 = new CObjAttackEnemy(799, 230);
		Objs::InsertObj(obj1, OBJ_ATTACK_ENEMY, 50);

		CObjAttackEnemy* obj2;
		obj2 = new CObjAttackEnemy(799, 330);
		Objs::InsertObj(obj2, OBJ_ATTACK_ENEMY, 50);

		CObjEnemy* obj3 = new CObjEnemy(650.0f, 130);
		Objs::InsertObj(obj3, OBJ_ENEMY, 50);

		CObjEnemy* obj4 = new CObjEnemy(799.0f, 160);
		Objs::InsertObj(obj4, OBJ_ENEMY, 50);

	}
	else if (m_time == 40)
	{
		//block object create
	/*	CObjBlock* obj = new CObjBlock(799.0f, 0);
		Objs::InsertObj(obj, OBJ_BLOCK, 50);

		CObjBlock* obj1 = new CObjBlock(766, 0);
		Objs::InsertObj(obj1, OBJ_BLOCK, 50);

		CObjBlock* obj2 = new CObjBlock(733, 0);
		Objs::InsertObj(obj2, OBJ_BLOCK, 50);

		CObjBlock* obj3 = new CObjBlock(799.0f, 33);
		Objs::InsertObj(obj3, OBJ_BLOCK, 50);

		CObjBlock* obj4 = new CObjBlock(766,33);
		Objs::InsertObj(obj4, OBJ_BLOCK, 50);

		CObjBlock* obj5 = new CObjBlock(733,33);
		Objs::InsertObj(obj5, OBJ_BLOCK, 50);

		CObjBlock* obj6 = new CObjBlock (799.0f, 66);
		Objs::InsertObj(obj6, OBJ_BLOCK, 50);

		CObjBlock* obj7 = new CObjBlock(766, 66);
		Objs::InsertObj(obj7, OBJ_BLOCK, 50);

		CObjBlock* obj8 = new CObjBlock(733, 66);
		Objs::InsertObj(obj8, OBJ_BLOCK, 50);

		CObjBlock* obj9 = new CObjBlock (733, 566);
		Objs::InsertObj(obj9, OBJ_BLOCK, 50);

		CObjBlock* obj10 = new CObjBlock(766, 566);
		Objs::InsertObj(obj10, OBJ_BLOCK, 50);

		CObjBlock* obj11 = new CObjBlock(799.0f, 566);
		Objs::InsertObj(obj11, OBJ_BLOCK, 50);

		CObjBlock* obj12 = new CObjBlock(733, 533);
		Objs::InsertObj(obj12, OBJ_BLOCK, 50);

		CObjBlock* obj13 = new CObjBlock(766, 533);
		Objs::InsertObj(obj13, OBJ_BLOCK, 50);

		CObjBlock* obj14 = new CObjBlock(799.0f, 533);
		Objs::InsertObj(obj14, OBJ_BLOCK, 50);

		CObjBlock* obj15 = new CObjBlock(733, 500);
		Objs::InsertObj(obj15, OBJ_BLOCK, 50);

		CObjBlock* obj16 = new CObjBlock(766, 500);
		Objs::InsertObj(obj16, OBJ_BLOCK, 50);

		CObjBlock* obj17 = new CObjBlock(799.0f, 500);
		Objs::InsertObj(obj17, OBJ_BLOCK, 50);*/
	}

	else if (m_time == 110)
	{
		//CObjBlock* obj = new CObjBlock(799.0f, 0);
		//Objs::InsertObj(obj, OBJ_BLOCK, 50);

		//CObjBlock* obj1 = new CObjBlock(766, 0);
		//Objs::InsertObj(obj1, OBJ_BLOCK, 50);

		//CObjBlock* obj2 = new CObjBlock(733, 0);
		//Objs::InsertObj(obj2, OBJ_BLOCK, 50);

		//CObjBlock* obj3 = new CObjBlock(799.0f, 33);
		//Objs::InsertObj(obj3, OBJ_BLOCK, 50);

		//CObjBlock* obj4 = new CObjBlock(766, 33);
		//Objs::InsertObj(obj4, OBJ_BLOCK, 50);

		//CObjBlock* obj5 = new CObjBlock(733, 33);
		//Objs::InsertObj(obj5, OBJ_BLOCK, 50);

		//CObjBlock* obj6 = new CObjBlock(799.0f, 66);
		//Objs::InsertObj(obj6, OBJ_BLOCK, 50);

		//CObjBlock* obj7 = new CObjBlock(766, 66);
		//Objs::InsertObj(obj7, OBJ_BLOCK, 50);

		//CObjBlock* obj8 = new CObjBlock(733, 66);
		//Objs::InsertObj(obj8, OBJ_BLOCK, 50);

		//CObjBlock* obj9 = new CObjBlock(733, 566);
		//Objs::InsertObj(obj9, OBJ_BLOCK, 50);

		//CObjBlock* obj10 = new CObjBlock(766, 566);
		//Objs::InsertObj(obj10, OBJ_BLOCK, 50);

		//CObjBlock* obj11 = new CObjBlock(799.0f, 566);
		//Objs::InsertObj(obj11, OBJ_BLOCK, 50);

		//CObjBlock* obj12 = new CObjBlock(733, 533);
		//Objs::InsertObj(obj12, OBJ_BLOCK, 50);

		//CObjBlock* obj13 = new CObjBlock(766, 533);
		//Objs::InsertObj(obj13, OBJ_BLOCK, 50);

		//CObjBlock* obj14 = new CObjBlock(799.0f, 533);
		//Objs::InsertObj(obj14, OBJ_BLOCK, 50);

		//CObjBlock* obj15 = new CObjBlock(733, 500);
		//Objs::InsertObj(obj15, OBJ_BLOCK, 50);

		//CObjBlock* obj16 = new CObjBlock(766, 500);
		//Objs::InsertObj(obj16, OBJ_BLOCK, 50);

		//CObjBlock* obj17 = new CObjBlock(799.0f, 500);
		//Objs::InsertObj(obj17, OBJ_BLOCK, 50);
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
	}
	else if (m_time == 550)
	{
	//CObjBlock* obj = new CObjBlock(799.0f, 0);
	//Objs::InsertObj(obj, OBJ_BLOCK, 50);

	//CObjBlock* obj1 = new CObjBlock(766, 0);
	//Objs::InsertObj(obj1, OBJ_BLOCK, 50);

	//CObjBlock* obj2 = new CObjBlock(733, 0);
	//Objs::InsertObj(obj2, OBJ_BLOCK, 50);

	//CObjBlock* obj3 = new CObjBlock(799.0f, 33);
	//Objs::InsertObj(obj3, OBJ_BLOCK, 50);

	//CObjBlock* obj4 = new CObjBlock(766, 33);
	//Objs::InsertObj(obj4, OBJ_BLOCK, 50);

	//CObjBlock* obj5 = new CObjBlock(733, 33);
	//Objs::InsertObj(obj5, OBJ_BLOCK, 50);

	//CObjBlock* obj6 = new CObjBlock(799.0f, 66);
	//Objs::InsertObj(obj6, OBJ_BLOCK, 50);

	//CObjBlock* obj7 = new CObjBlock(766, 66);
	//Objs::InsertObj(obj7, OBJ_BLOCK, 50);

	//CObjBlock* obj8 = new CObjBlock(733, 66);
	//Objs::InsertObj(obj8, OBJ_BLOCK, 50);

	//CObjBlock* obj9 = new CObjBlock(733, 566);
	//Objs::InsertObj(obj9, OBJ_BLOCK, 50);

	//CObjBlock* obj10 = new CObjBlock(766, 566);
	//Objs::InsertObj(obj10, OBJ_BLOCK, 50);

	//CObjBlock* obj11 = new CObjBlock(799.0f, 566);
	//Objs::InsertObj(obj11, OBJ_BLOCK, 50);

	//CObjBlock* obj12 = new CObjBlock(733, 533);
	//Objs::InsertObj(obj12, OBJ_BLOCK, 50);

	//CObjBlock* obj13 = new CObjBlock(766, 533);
	//Objs::InsertObj(obj13, OBJ_BLOCK, 50);

	//CObjBlock* obj14 = new CObjBlock(799.0f, 533);
	//Objs::InsertObj(obj14, OBJ_BLOCK, 50);

	//CObjBlock* obj15 = new CObjBlock(733, 500);
	//Objs::InsertObj(obj15, OBJ_BLOCK, 50);

	//CObjBlock* obj16 = new CObjBlock(766, 500);
	//Objs::InsertObj(obj16, OBJ_BLOCK, 50);

	//CObjBlock* obj17 = new CObjBlock(799.0f, 500);
	//Objs::InsertObj(obj17, OBJ_BLOCK, 50);

	}
	else if (m_time == 780)
	{
	//CObjBlock* obj = new CObjBlock(799.0f, 300);
	//Objs::InsertObj(obj, OBJ_BLOCK, 50);
	//CObjBlock* obj2 = new CObjBlock(799.0f, 277);
	//Objs::InsertObj(obj2, OBJ_BLOCK, 50);
	//CObjBlock* obj3 = new CObjBlock(799.0f, 244);
	//Objs::InsertObj(obj3, OBJ_BLOCK, 50);
	//CObjBlock* obj4 = new CObjBlock(766.0f, 300);
	//Objs::InsertObj(obj4, OBJ_BLOCK, 50);
	//CObjBlock* obj5 = new CObjBlock(766.0f, 277);
	//Objs::InsertObj(obj5, OBJ_BLOCK, 50);
	//CObjBlock* obj5 = new CObjBlock(766.0f, 244);
	//Objs::InsertObj(obj5, OBJ_BLOCK, 50);
	//CObjBlock* obj6 = new CObjBlock(733.0f, 300);
	//Objs::InsertObj(obj6, OBJ_BLOCK, 50);
	//CObjBlock* obj7 = new CObjBlock(733.0f, 277);
	//Objs::InsertObj(obj7, OBJ_BLOCK, 50);
	//CObjBlock* obj8 = new CObjBlock(733.0f, 244);
	//Objs::InsertObj(obj8, OBJ_BLOCK, 50);


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
	else if (m_time == 1200)
	{
		//音楽チェンジ
		//Audio::Stop(0);//0曲ストップ
		//Audio::Start(1);//1曲目スタート

		CObjBoss* obj;
		obj = new CObjBoss(300, 250);
		Objs::InsertObj(obj, OBJ_BOSS_ENEMY, 50);
	}
}