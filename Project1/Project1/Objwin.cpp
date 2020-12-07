//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"


#include"GameHead.h"
#include"Objwin.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjWin::Init()
{
	m_key_flag = false;
}
//アクション
void CObjWin::Action()
{
	//エンターキーを押してシーンタイトルを移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjWin::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	//出力する文字を入力
	Font::SetStrTex(L"ENDING　CREDIT");
	Font::SetStrTex(L"総合ディレクター　瀬口　琉");
	Font::SetStrTex(L"プランナー　桶谷　光城");
	Font::SetStrTex(L"プログラマー 上田　茂樹");
	Font::SetStrTex(L"グラフィック 鞍野　一哉");
	Font::SetStrTex(L"サウンドディレクター　蛭間　瑠唯");
	Font::SetStrTex(L"お借りした楽曲　魔王魂様");
}