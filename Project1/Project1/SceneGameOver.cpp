//STLデバッグ機能をOFFにする
#define _SEURE_SCL (o)
#define _HAS_ITERATOR_DEBUGGING (o)
//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
//使用ヘッダー
#include "SceneGameOver.h"
#include "GameHead.h"
#include"GameL/Audio.h"
//コンストラクタ
CSceneGameOver::CSceneGameOver()
{

}
//デストラクタ
CSceneGameOver::~CSceneGameOver()
{

}
//初期化メソッド
void CSceneGameOver::InitScene()
{
	//外部グラフィックファイルを読み込み6番目に登録
	Draw::LoadImage(L"GameOver画面コンテ.png", 0, TEX_SIZE_512);
	//音楽読み込み
	Audio::LoadAudio(16, L"ゲームオーバー.wav", BACK_MUSIC);
	//	ゲームオーバーオブジェクト作成
	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 10);

	Audio::Start(16);


}
//ゲームメイン実行中メソッド
void CSceneGameOver::Scene()
{

}