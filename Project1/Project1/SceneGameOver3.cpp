//STLデバッグ機能をOFFにする
#define _SEURE_SCL (o)
#define _HAS_ITERATOR_DEBUGGING (o)
//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
//使用ヘッダー
#include "SceneGameOver3.h"
#include "GameHead.h"
#include"GameL/Audio.h"
//コンストラクタ
CSceneGameOver3::CSceneGameOver3()
{

}
//デストラクタ
CSceneGameOver3::~CSceneGameOver3()
{

}
//初期化メソッド
void CSceneGameOver3::InitScene()
{
	//外部グラフィックファイルを読み込み6番目に登録
	Draw::LoadImage(L"GameOver画面コンテ.png", 0, TEX_SIZE_512);

	//音楽読み込み
	Audio::LoadAudio(16, L"ゲームオーバー.wav", BACK_MUSIC);
	//	ゲームオーバーオブジェクト作成
	CObjGameOver3* obj = new CObjGameOver3();
	Objs::InsertObj(obj, OBJ_GAME_OVER3, 10);

	Audio::Start(16);


}
//ゲームメイン実行中メソッド
void CSceneGameOver3::Scene()
{

}