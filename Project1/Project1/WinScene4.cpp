//STLデバッグ機能をオフにする。
#define _SECURE_SCL(o)
#define _HAS_ITERATOR_DEBUGGING(o)

//GameL使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL/Audio.h"


//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "WinScene4.h"
#include"GameHead.h"

//コンストラクタ
CSceneWin4::CSceneWin4()
{

}

//デストラクタ
CSceneWin4::~CSceneWin4()
{

}

//初期化メソッド
//文字の登録
void CSceneWin4::InitScene()
{
	//外部グラフィック読み込み登録0番
	Draw::LoadImage(L"Win画面２.png", 0, TEX_SIZE_512);
	////外部グラフィック読み込む1番
	//Draw::LoadImage(L"virusclear.png", 1, TEX_SIZE_512);

	//音楽読み込み
	Audio::LoadAudio(17, L"クリア画面.wav", BACK_MUSIC);

	//クリアオブジェクト登録
	CObjWin4* obj = new CObjWin4();//クリアオブジェクト作成
	Objs::InsertObj(obj, OBJ_WIN4, 10);//クリアオブジェクト登録


		//クリア時背景オブジェクト作成
	CObjClearback* back = new CObjClearback();
	Objs::InsertObj(back, OBJ_CLEAR_BACK, 0);

	////クリアウイルス作成
	//CObjClearvirus* obj2 = new CObjClearvirus();//クリア作成
	//Objs::InsertObj(obj2, OBJ_CLEAR_VIRUS, 1);//クリアウイルス登録

	Audio::Start(17);

}

//実行メソッド
void CSceneWin4::Scene()
{

}