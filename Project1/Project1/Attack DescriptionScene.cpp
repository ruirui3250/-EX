//STLデバック機能をOFFにする
#define _SWCURE_SCL(o)
#define _HAS_ITERATOR_DEBUGGING(o)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL/Audio.h"
#include"Item DescriptionScene.h"
//使用するネームスペース
using namespace GameL;

//使用ヘッダー
//#include "SceneMain.h"
#include "GameHead.h"

//コントラクタ
CSceneItemD::CSceneItemD()
{

}

//デストラクタ
CSceneItemD::~CSceneItemD()
{

}

//ゲームメイン初期化メソッド
void CSceneItemD::InitItemD()
{
	//外部グラフィック読み込み登録0番

	//説明オブジェクト登録
	CObjItemD* obj = new CObjItemD();//説明オブジェクト作成
	Objs::InsertObj(obj, OBJ_ITEM_DESCRIPTION, 10);//説明オブジェクト登録
}

//ゲームメイン実行中メソッド
void CSceneItemD::Scene()
{

}