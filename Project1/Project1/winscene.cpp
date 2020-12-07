//STLデバッグ機能をオフにする。
#define _SECURE_SCL(o)
#define _HAS_ITERATOR_DEBUGGING(o)

//GameL使用するヘッダー
#include "GameL\SceneObjManager.h"
//#include "GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "winscene.h"
#include"GameHead.h"

//コンストラクタ
CSceneWin::CSceneWin()
{

}

//デストラクタ
CSceneWin::~CSceneWin()
{

}

//初期化メソッド
//文字の登録
void CSceneWin::InitScene()
{
	//外部グラフィック読み込み登録0番
	/*Draw::LoadImage(L"Win画面(使).png", 1, TEX_SIZE_512);*/
	////外部グラフィック読み込む1番
	//Draw::LoadImage(L"virusclear.png", 1, TEX_SIZE_512);

	//音楽読み込み
	Audio::LoadAudio(3, L"エンディング.wav", BACK_MUSIC);

	/*Font::SetStrTex(L"You Win!");
	Font::SetStrTex(L"エンターキーでタイトル戻る。");*/

	//クリアオブジェクト登録
	CObjWin* obj = new CObjWin();//クリアオブジェクト作成
	Objs::InsertObj(obj, OBJ_WIN, 10);//クリアオブジェクト登録


		//クリア時背景オブジェクト作成
	CObjClearBack2* back = new CObjClearBack2();//背景オブジェクト作成
	Objs::InsertObj(back, OBJ_CLEAR_BACK2, 1);//背景オブジェクト作成

	////クリアウイルス作成
	//CObjClearvirus* obj2 = new CObjClearvirus();//クリア作成
	//Objs::InsertObj(obj2, OBJ_CLEAR_VIRUS, 1);//クリアウイルス登録
	Audio::Start(3);
}

//実行メソッド
void CSceneWin::Scene()
{

}