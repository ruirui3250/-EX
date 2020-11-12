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
#include"SceneMain4.h"
#include"GameHead.h"
//コンストラクタ
CSceneMain4::CSceneMain4()
{

}
//デストラクタ
CSceneMain4::~CSceneMain4()
{

}

//ゲームメイン初期化メソッド
void CSceneMain4::InitScene()
{
	//外部グラフィック読み込み0番  背景
	Draw::LoadImage(L"背景(使).png", 9, TEX_SIZE_512);

	Draw::LoadImage(L"ウイルス(使).png", 3, TEX_SIZE_512);

	Draw::LoadImage(L"注射器(使).png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"カプセル.png", 2, TEX_SIZE_512);

	//Draw::LoadImage(L"障害物.png", 9, TEX_SIZE_512);

	Draw::LoadImage(L"拡散弾丸.png", 6, TEX_SIZE_512);
	//外部グラフィックファイルを読み込み1番に登録 ボスグラフィックを登録
	Draw::LoadImage(L"ボス4.png", 4, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();//主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 10);//主人公オブジェクトマネージャーを登録

	////blockオブジェクト作成
	//CObjBlock* objb = new CObjBlock();
	//Objs::InsertObj(objb, OBJ_BLOCK, 9);

		//クリア時背景オブジェクト作成
	CObjSceneMain* back = new CObjSceneMain();
	Objs::InsertObj(back, OBJ_SCENE_MAIN4, 9);

	//タイム初期化
	m_time = 0;

}

//ゲームシーン実行中メソッド
void CSceneMain4::Scene()
{
	m_time++;

	if (m_time == 30)
	{
		CObjEnemy* obj = new CObjEnemy(799.0f, 400);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	else if (m_time == 80)
	{
		CObjEnemy* obj = new CObjEnemy(799.0f, 300);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	else if (m_time == 120)
	{
		CObjEnemy* obj = new CObjEnemy(799.0f, 200);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	else if (m_time == 200)
	{
		CObjEnemy* obj;
		obj = new CObjEnemy(799.0f, 100);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
		obj = new CObjEnemy(799.0f, 500);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	else if (m_time == 400)
	{
		CObjEnemy* obj1;
		obj1 = new CObjEnemy(799.0f, 300);
		Objs::InsertObj(obj1, OBJ_ENEMY, 50);

		CObjAttackEnemy* obj2;
		obj2 = new CObjAttackEnemy(799, 400);
		Objs::InsertObj(obj2, OBJ_ATTACK_ENEMY, 50);

	}
	else if (m_time == 550)
	{
		CObjEnemy* obj1;
		obj1 = new CObjEnemy(799.0f, 400);
		Objs::InsertObj(obj1, OBJ_ENEMY, 50);

		CObjAttackEnemy* obj2;
		obj2 = new CObjAttackEnemy(799, 300);
		Objs::InsertObj(obj2, OBJ_ATTACK_ENEMY, 50);

	}
	else if (m_time == 680)
	{
		CObjEnemy* obj;
		obj = new CObjEnemy(799.0f, 300);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
		obj = new CObjEnemy(799.0f, 350);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
		obj = new CObjEnemy(799.0f, 250);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	else if (m_time == 750)
	{
		CObjAttackEnemy* obj;
		obj = new CObjAttackEnemy(799, 300);
		Objs::InsertObj(obj, OBJ_ATTACK_ENEMY, 50);
	}
	else if (m_time == 1000)
	{
		CObjSinEnemy* obj;
		for (int i = 0; i < 15; i++)
		{
			obj = new CObjSinEnemy(799, i * 32);
			Objs::InsertObj(obj, OBJ_SIN_ENEMY, 50);
		}
	}
	else if (m_time == 1100)
	{
		CObjSinEnemy* obj;
		for (int i = 0; i < 15; i++)
		{
			obj = new CObjSinEnemy(799, i * 32 + 64);
			Objs::InsertObj(obj, OBJ_SIN_ENEMY, 50);
		}
	}
	else if (m_time == 1200)
	{
		CObjSinEnemy* obj;
		for (int i = 0; i < 15; i++)
		{
			obj = new CObjSinEnemy(799, i * 32);
			Objs::InsertObj(obj, OBJ_SIN_ENEMY, 50);
		}
	}
	else if (m_time == 1300)
	{
		CObjSinEnemy* obj;
		for (int i = 0; i < 15; i++)
		{
			obj = new CObjSinEnemy(799, i * 32);
			Objs::InsertObj(obj, OBJ_SIN_ENEMY, 50);
		}

		CObjDiffusionEnemy* obj2;
		obj2 = new CObjDiffusionEnemy(799, 300);
		Objs::InsertObj(obj2, OBJ_DIFFUSION_ENEMY, 50);
	}
	else if (m_time == 1500)
	{
		CObjHomingEnemy* obj;
		obj = new CObjHomingEnemy(799, 500);
		Objs::InsertObj(obj, OBJ_HOMING_ENEMY, 50);
	}
	else if (m_time == 2000)
	{
		//音楽チェンジ
		//Audio::Stop(0);//0曲ストップ
		//Audio::Start(1);//1曲目スタート

		CObjBoss* obj;
		obj = new CObjBoss(300, 100);
		Objs::InsertObj(obj, OBJ_BOSS_ENEMY, 50);
	}
}