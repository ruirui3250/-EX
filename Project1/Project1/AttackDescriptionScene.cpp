//STLデバック機能をOFFにする
#define _SWCURE_SCL(o)
#define _HAS_ITERATOR_DEBUGGING(o)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL/Audio.h"
#include"AttackDescriptionScene.h"
//使用するネームスペース
using namespace GameL;

//使用ヘッダー
//#include "SceneMain.h"
#include "GameHead.h"

//コントラクタ
CSceneAttack::CSceneAttack()
{

}

//デストラクタ
CSceneAttack::~CSceneAttack()
{

}

//ゲームメイン初期化メソッド
void CSceneAttack::InitScene()
{
	//外部グラフィック読み込み登録0番

	//説明オブジェクト登録
	CObjAttack* obj = new CObjAttack();//説明オブジェクト作成
	Objs::InsertObj(obj, OBJ_ATTACK_DESCRIPTION, 10);//説明オブジェクト登録
}

//ゲームメイン実行中メソッド
void CSceneAttack::Scene()
{

}