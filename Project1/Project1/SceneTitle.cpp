//STLデバック機能をOFFにする
#define _SWCURE_SCL(o)
#define _HAS_ITERATOR_DEBUGGING(o)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL/Audio.h"
//使用するネームスペース
using namespace GameL;

//使用ヘッダー
//#include "SceneMain.h"
#include "GameHead.h"

//コントラクタ
CSceneTitle::CSceneTitle()
{

}

//デストラクタ
CSceneTitle::~CSceneTitle()
{

}

//ゲームメイン初期化メソッド
void CSceneTitle::InitScene()
{
	//外部グラフィック読み込み登録0番
	Draw::LoadImage(L"タイトル(使).png", 1, TEX_SIZE_512);

	//音楽読み込み
	Audio::LoadAudio(1, L"タイトル.wav", BACK_MUSIC);
	//クリアオブジェクト登録
	CObjTitle* obj = new CObjTitle();//クリアオブジェクト作成
	Objs::InsertObj(obj, OBJ_TITLE, 10);//クリアオブジェクト登録

	Audio::Start(1);
}

//ゲームメイン実行中メソッド
void CSceneTitle::Scene()
{

}