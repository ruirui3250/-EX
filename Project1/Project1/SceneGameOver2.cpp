//STLデバッグ機能をOFFにする
#define _SEURE_SCL (o)
#define _HAS_ITERATOR_DEBUGGING (o)
//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
//使用ヘッダー
#include "SceneGameOver2.h"
#include "GameHead.h"
#include"GameL/Audio.h"
//コンストラクタ
CSceneGameOver2::CSceneGameOver2()
{

}
//デストラクタ
CSceneGameOver2::~CSceneGameOver2()
{

}
//初期化メソッド
void CSceneGameOver2::InitScene()
{
	//外部グラフィックファイルを読み込み6番目に登録
	Draw::LoadImage(L"GameOver画面コンテ.png", 0, TEX_SIZE_512);

	//音楽読み込み
	Audio::LoadAudio(16, L"ゲームオーバー.wav", BACK_MUSIC);
	//	ゲームオーバーオブジェクト作成
	CObjGameOver2* obj = new CObjGameOver2();
	Objs::InsertObj(obj, OBJ_GAME_OVER2, 10);

	Audio::Start(16);


}
//ゲームメイン実行中メソッド
void CSceneGameOver2::Scene()
{

}