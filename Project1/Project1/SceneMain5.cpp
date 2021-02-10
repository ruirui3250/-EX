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
#include"SceneMain5.h"
#include"GameHead.h"
//コンストラクタ
CSceneMain5::CSceneMain5()
{

}
//デストラクタ
CSceneMain5::~CSceneMain5()
{

}

//ゲームメイン初期化メソッド
void CSceneMain5::InitScene()
{
	//外部グラフィック読み込み0番  背景
	Draw::LoadImage(L"背景(使).png", 9, TEX_SIZE_512);

	Draw::LoadImage(L"ウイルス無.png", 3, TEX_SIZE_512);

	/*Draw::LoadImage(L"ウイルス.png", 7, TEX_SIZE_512);*/

	Draw::LoadImage(L"敵弾(使).png", 5, TEX_SIZE_512);

	Draw::LoadImage(L"注射器.png", 0, TEX_SIZE_512);

	Draw::LoadImage(L"カプセル.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"主人公弾縦.png", 11, TEX_SIZE_512);

	//Draw::LoadImage(L"障害物.png",9, TEX_SIZE_512);
	Draw::LoadImage(L"レーザー.png", 10, TEX_SIZE_512);

	Draw::LoadImage(L"レーザー縦.png", 12, TEX_SIZE_512);

	Draw::LoadImage(L"拡散弾丸.png", 6, TEX_SIZE_512);
	//外部グラフィックファイルを読み込み1番に登録 ボスグラフィックを登録
	Draw::LoadImage(L"ボス５.png", 4, TEX_SIZE_512);

	Draw::LoadImage(L"障害物.png", 29, TEX_SIZE_512);

	Draw::LoadImage(L"ライフ回復.png", 31, TEX_SIZE_512);

	Draw::LoadImage(L"ボスエフェクト.png", 8, TEX_SIZE_512);

	Draw::LoadImage(L"BOSSYAZIRUSI.png", 33, TEX_SIZE_512);

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
	Audio::LoadAudio(10, L"5面.wav", BACK_MUSIC);

	//音楽読み込み
	Audio::LoadAudio(15, L"ボス5.wav", BACK_MUSIC);

	//アイテム回復BGM
	Audio::LoadAudio(19, L"HP.wav", EFFECT);

	Audio::LoadAudio(20, L"LK.wav", EFFECT);

	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((0.8 - v));

	//主人公オブジェクト作成
	CObjHero5* obj = new CObjHero5();//主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 10);//主人公オブジェクトマネージャーを登録

	////blockオブジェクト作成
	//CObjBlock* objb = new CObjBlock();
	//Objs::InsertObj(objb, OBJ_BLOCK, 9);

		//背景オブジェクト作成
	CObjSceneMain5* back = new CObjSceneMain5();
	Objs::InsertObj(back, OBJ_SCENE_MAIN5, 9);

	//タイム初期化
	m_time = 0;

	Audio::Start(10);

}

//ゲームシーン実行中メソッド
void CSceneMain5::Scene()
{
	m_time++;
	////アイテム配置
	//if (m_time == 500)
	//{
	//	CObjMigiLifeItem* obj = new CObjMigiLifeItem(799.0f, 600);
	//	Objs::InsertObj(obj, OBJ_ITEM, 50);
	//}
	//if (m_time == 700)
	//{
	//	CObjHidariLifeItem* obj = new CObjHidariLifeItem(500.0f, 1);
	//	Objs::InsertObj(obj, OBJ_ITEM, 50);
	//}
	//if (m_time == 1000)
	//{
	//	CObjSitaLifeItem* obj = new CObjSitaLifeItem(1.0f, 300);
	//	Objs::InsertObj(obj, OBJ_ITEM, 50);
	//}
	//if (m_time == 1400)
	//{
	//	CObjItem* obj = new CObjItem(250.0f, 1);
	//	Objs::InsertObj(obj, OBJ_ITEM, 50);
	//}

	//if (m_time == 30)
	//{
	//	CObjEnemy2* obj = new CObjEnemy2(799.0f, 400);
	//	Objs::InsertObj(obj, OBJ_ENEMY2, 50);

	//	CObjAttackEnemy2* obj2;
	//	obj2 = new CObjAttackEnemy2(799, 330);
	//	Objs::InsertObj(obj2, OBJ_ATTACK_ENEMY2, 50);

	//	CObjEnemy2* obj3 = new CObjEnemy2(650.0f, 130);
	//	Objs::InsertObj(obj3, OBJ_ENEMY2, 50);

	//	CObjEnemy2* obj4 = new CObjEnemy2(799.0f, 160);
	//	Objs::InsertObj(obj4, OBJ_ENEMY2, 50);

	//}
	//else if (m_time == 40)
	//{
	//	//block object create
	//	CObjYokoKesen* obj = new CObjYokoKesen(799.0f, 0);
	//	Objs::InsertObj(obj, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj1 = new CObjYokoKesen(766, 0);
	//	Objs::InsertObj(obj1, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj2 = new CObjYokoKesen(733, 0);
	//	Objs::InsertObj(obj2, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj3 = new CObjYokoKesen(799.0f, 33);
	//	Objs::InsertObj(obj3, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj4 = new CObjYokoKesen(766, 33);
	//	Objs::InsertObj(obj4, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj5 = new CObjYokoKesen(733, 33);
	//	Objs::InsertObj(obj5, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj6 = new CObjYokoKesen(799.0f, 66);
	//	Objs::InsertObj(obj6, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj7 = new CObjYokoKesen(766, 66);
	//	Objs::InsertObj(obj7, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj8 = new CObjYokoKesen(733, 66);
	//	Objs::InsertObj(obj8, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj9 = new CObjYokoKesen(733, 566);
	//	Objs::InsertObj(obj9, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj10 = new CObjYokoKesen(766, 566);
	//	Objs::InsertObj(obj10, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj11 = new CObjYokoKesen(799.0f, 566);
	//	Objs::InsertObj(obj11, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj12 = new CObjYokoKesen(733, 533);
	//	Objs::InsertObj(obj12, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj13 = new CObjYokoKesen(766, 533);
	//	Objs::InsertObj(obj13, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj14 = new CObjYokoKesen(799.0f, 533);
	//	Objs::InsertObj(obj14, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj15 = new CObjYokoKesen(733, 500);
	//	Objs::InsertObj(obj15, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj16 = new CObjYokoKesen(766, 500);
	//	Objs::InsertObj(obj16, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj17 = new CObjYokoKesen(799.0f, 500);
	//	Objs::InsertObj(obj17, OBJ_YOKO_KESEN, 50);
	//}

	//else if (m_time == 300)
	//{
	//	CObjTateEnemy2* obj = new CObjTateEnemy2(10.0f, 1);
	//	Objs::InsertObj(obj, OBJ_TATE_ENEMY2, 50);

	//	CObjTateEnemy2* obj2 = new CObjTateEnemy2(70.0f, 1);
	//	Objs::InsertObj(obj2, OBJ_TATE_ENEMY2, 50);

	//	CObjTateEnemy2* obj3 = new CObjTateEnemy2(120.0f, 1);
	//	Objs::InsertObj(obj3, OBJ_TATE_ENEMY2, 50);

	//	CObjTateEnemy2* obj4 = new CObjTateEnemy2(170.0f, 1);
	//	Objs::InsertObj(obj4, OBJ_TATE_ENEMY2, 50);

	//	CObjTateEnemy2* obj5 = new CObjTateEnemy2(190.0f, 1);
	//	Objs::InsertObj(obj5, OBJ_TATE_ENEMY2, 50);
	//}

	//else if (m_time == 400)
	//{
	//	//block object create
	//	CObjEnemy2* obj = new CObjEnemy2(799.0f, 400);
	//	Objs::InsertObj(obj, OBJ_ENEMY2, 50);

	//	CObjEnemy2* obj2 = new CObjEnemy2(799.0f, 350);
	//	Objs::InsertObj(obj2, OBJ_ENEMY2, 50);

	//	CObjTateKesen* obj3 = new CObjTateKesen(10, -1);
	//	Objs::InsertObj(obj3, OBJ_TATEKESEN, 50);

	//	CObjSitaKesen* obj4 = new CObjSitaKesen(70, 550);
	//	Objs::InsertObj(obj4, OBJ_SITA_KESEN, 50);

	//	CObjTateKesen* obj5 = new CObjTateKesen(130, -1);
	//	Objs::InsertObj(obj5, OBJ_TATEKESEN, 50);

	//	CObjSitaKesen* obj6 = new CObjSitaKesen(180, 550);
	//	Objs::InsertObj(obj6, OBJ_SITA_KESEN, 50);

	//	CObjTateKesen* obj7 = new CObjTateKesen(230, -1);
	//	Objs::InsertObj(obj7, OBJ_TATEKESEN, 50);

	//	
	//}
	//else if (m_time == 450)
	//{
	//	CObjEnemy2* obj;
	//	obj = new CObjEnemy2(799.0f, 300);
	//	Objs::InsertObj(obj, OBJ_ENEMY2, 50);
	//	obj = new CObjEnemy2(799.0f, 350);
	//	Objs::InsertObj(obj, OBJ_ENEMY2, 50);
	//	obj = new CObjEnemy2(799.0f, 250);
	//	Objs::InsertObj(obj, OBJ_ENEMY2, 50);

	//	CObjAttackEnemy2* obj2;
	//	obj2 = new CObjAttackEnemy2(799.0f, 200);
	//	Objs::InsertObj(obj2, OBJ_ATTACK_ENEMY2, 50);
	//	obj2 = new CObjAttackEnemy2(799.0f, 400);
	//	Objs::InsertObj(obj2, OBJ_ATTACK_ENEMY2, 50);

	//}

	//else if (m_time == 550)
	//{
	//CObjEnemy2* obj = new CObjEnemy2(799.0f, 400);
	//Objs::InsertObj(obj, OBJ_ENEMY2, 50);

	//CObjTateEnemy2* obj3 = new CObjTateEnemy2(10.0f, 30);
	//Objs::InsertObj(obj3, OBJ_TATE_ENEMY2, 50);

	//CObjSitaEnemy2* obj4 = new CObjSitaEnemy2(10.0f, 500);
	//Objs::InsertObj(obj4, OBJ_SITA_ENEMY2, 50);

	//CObjTateEnemy2* obj5 = new CObjTateEnemy2(70.0f, 500);
	//Objs::InsertObj(obj5, OBJ_TATE_ENEMY2, 50);

	//CObjSitaEnemy2* obj6 = new CObjSitaEnemy2(70.0f, 500);
	//Objs::InsertObj(obj6, OBJ_SITA_ENEMY2, 50);
	//}

	//else if (m_time == 800)
	//{
	//CObjEnemy2* obj = new CObjEnemy2(550.0f, 400);
	//Objs::InsertObj(obj, OBJ_ENEMY2, 50);

	//CObjEnemy2* obj2 = new CObjEnemy2(550.0f, 400);
	//Objs::InsertObj(obj2, OBJ_ENEMY2, 50);

	//CObjSitaEnemy2* obj3 = new CObjSitaEnemy2(550.0f, 400);
	//Objs::InsertObj(obj3, OBJ_SITA_ENEMY2, 50);

	//CObjTateKesen* obj6 = new CObjTateKesen(280, -1);
	//Objs::InsertObj(obj6, OBJ_TATEKESEN, 50);

	//CObjSitaKesen* obj7 = new CObjSitaKesen(330, 550);
	//Objs::InsertObj(obj7, OBJ_SITA_KESEN, 50);

	//CObjTateKesen* obj8 = new CObjTateKesen(380, -1);
	//Objs::InsertObj(obj8, OBJ_TATEKESEN, 50);

	//CObjSitaKesen* obj4 = new CObjSitaKesen(430, 550);
	//Objs::InsertObj(obj4, OBJ_SITA_KESEN, 50);

	//CObjTateKesen* obj5 = new CObjTateKesen(480, -1);
	//Objs::InsertObj(obj5, OBJ_TATEKESEN, 50);
	//

	//}
	//else if (m_time == 1000)
	//{
	//CObjTateKesen* obj = new CObjTateKesen(10, -1);
	//Objs::InsertObj(obj, OBJ_TATEKESEN, 50);

	//CObjSitaKesen* obj2 = new CObjSitaKesen(70, 550);
	//Objs::InsertObj(obj2, OBJ_SITA_KESEN, 50);

	//CObjTateKesen* obj3 = new CObjTateKesen(130, -1);
	//Objs::InsertObj(obj3, OBJ_TATEKESEN, 50);

	//CObjSitaKesen* obj4 = new CObjSitaKesen(180, 550);
	//Objs::InsertObj(obj4, OBJ_SITA_KESEN, 50);

	//CObjTateKesen* obj5 = new CObjTateKesen(230, -1);
	//Objs::InsertObj(obj5, OBJ_TATEKESEN, 50);
	//}

	//else if (m_time == 1200)
	//{
	//CObjTateKesen* obj = new CObjTateKesen(280, -1);
	//Objs::InsertObj(obj, OBJ_TATEKESEN, 50);

	//CObjSitaKesen* obj2 = new CObjSitaKesen(330, 501);
	//Objs::InsertObj(obj2, OBJ_SITA_KESEN, 50);

	//CObjTateKesen* obj3 = new CObjTateKesen(380, -1);
	//Objs::InsertObj(obj3, OBJ_TATEKESEN, 50);

	//CObjSitaKesen* obj4 = new CObjSitaKesen(430, 501);
	//Objs::InsertObj(obj4, OBJ_SITA_KESEN, 50);
 //}

	//else if (m_time == 1500)
	//{
	//ObjBossEffect* obj;
	//obj = new  ObjBossEffect(733.0f, 177);
	//Objs::InsertObj(obj, OBJ_BOSS_EFFECT, 50);
	//}
	//if (m_time == 1600)
	//{
	//	ObjBossYazirusi5* obj;
	//	obj = new ObjBossYazirusi5(50, 100);
	//	Objs::InsertObj(obj, OBJ_BOSS_YAZIRUSI5, 50);
	//}

	/*else*/ 
		if (m_time == 20)
	{
		//音楽チェンジ
		Audio::Stop(10);//0曲ストップ
		Audio::Start(15);//1曲目スタート

		CObjMIXBoss* obj;
		obj = new CObjMIXBoss(450, 250);
		Objs::InsertObj(obj, OBJ_MIX_BOSS, 50);

		CObjTateKesen* obj2 = new CObjTateKesen(150, 10);
		Objs::InsertObj(obj2, OBJ_TATEKESEN, 50);

		CObjTateKesen* obj3 = new CObjTateKesen(200, 50);
		Objs::InsertObj(obj3, OBJ_TATEKESEN, 50);

		CObjTateKesen* obj5 = new CObjTateKesen(250, 100);
		Objs::InsertObj(obj5, OBJ_TATEKESEN, 50);

		CObjTateKesen* obj6 = new CObjTateKesen(300, 300);
		Objs::InsertObj(obj6, OBJ_TATEKESEN, 50);

		CObjTateKesen* obj7 = new CObjTateKesen(350, 200);
		Objs::InsertObj(obj7, OBJ_TATEKESEN, 50);

		/*CObjEnemyBossBullet4* obj8 = new CObjEnemyBossBullet4(800.0f, 500);
		Objs::InsertObj(obj8, OBJ_BOSS_BULLET_ENEMY, 50);*/


	}
}