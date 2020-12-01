//STLデバッグ機能をOFFにする
#define _SEURE_SCL (o)
#define _HAS_ITERATOR_DEBUGGING (o)
//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
//使用ヘッダー
#include "SceneGameOver5.h"
#include "GameHead.h"
//コンストラクタ
CSceneGameOver5::CSceneGameOver5()
{

}
//デストラクタ
CSceneGameOver5::~CSceneGameOver5()
{

}
//初期化メソッド
void CSceneGameOver5::InitScene()
{
	//外部グラフィックファイルを読み込み6番目に登録
	Draw::LoadImage(L"GameOver画面コンテ.png", 0, TEX_SIZE_512);
	//	ゲームオーバーオブジェクト作成
	CObjGameOver5* obj = new CObjGameOver5();
	Objs::InsertObj(obj, OBJ_GAME_OVER5, 10);


}
//ゲームメイン実行中メソッド
void CSceneGameOver5::Scene()
{

}