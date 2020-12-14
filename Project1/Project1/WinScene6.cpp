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
#include "WinScene6.h"
#include"GameHead.h"

//コンストラクタ
CSceneWin6::CSceneWin6()
{

}

//デストラクタ
CSceneWin6::~CSceneWin6()
{

}

//初期化メソッド
//文字の登録
void CSceneWin6::InitScene()
{
	////外部グラフィック読み込み登録0番
	//Draw::LoadImage(L"ゲームクリア画面.png", 1, TEX_SIZE_512);
	//////外部グラフィック読み込む1番
	////Draw::LoadImage(L"virusclear.png", 1, TEX_SIZE_512);

	//音楽読み込み
	Audio::LoadAudio(21, L"エンディングテーマ.wav", BACK_MUSIC);

	//クリアオブジェクト登録
	CObjWin6* obj = new CObjWin6();//クリアオブジェクト作成
	Objs::InsertObj(obj, OBJ_WIN6, 10);//クリアオブジェクト登録

	//Font登録
	Font::SetStrTex(L"ウイルスは駆逐され。");
	Font::SetStrTex(L"体内に平和が訪れた。");
	Font::SetStrTex(L"しかし");
	Font::SetStrTex(L"ウイルスは全て");
	Font::SetStrTex(L"駆逐されたわけではない。");
	Font::SetStrTex(L"新しいウイルスが");
	Font::SetStrTex(L"体内に侵入して来たのだ");
	Font::SetStrTex(L"戦え！");
	Font::SetStrTex(L"ウイルスがいなくなる");
	Font::SetStrTex(L"その日まで!!");
	Font::SetStrTex(L"エンターでスタッフロール");

		//クリア時背景オブジェクト作成
	CObjClearBack2* back = new CObjClearBack2();
	Objs::InsertObj(back, OBJ_CLEAR_BACK2, 0);

	////クリアウイルス作成
	//CObjClearvirus* obj2 = new CObjClearvirus();//クリア作成
	//Objs::InsertObj(obj2, OBJ_CLEAR_VIRUS, 1);//クリアウイルス登録

	Audio::Start(21);

}

//実行メソッド
void CSceneWin6::Scene()
{

}