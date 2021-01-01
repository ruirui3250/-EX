//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"


#include"GameHead.h"
#include"ObjItem Description.h"

//使用するネームスペース
using namespace GameL;

//CObjWin2::CObjWin2()
//{
//
//}

//イニシャライズ
void CObjItemD::Init()
{
	m_key_flag = false;
}
//アクション
void CObjItemD::Action()
{
	/*エンターキーを押して次の面に移行する*/
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjItemD::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	////フォントの表示
		////フォントの表示
	Font::StrDraw(L"アイテム", 0, 0, 30, c);
	Font::StrDraw(L"赤血球", 0, 50, 30, c);
	Font::StrDraw(L"赤く浮遊している楕円形状のアイテム", 0, 80, 30, c);
	Font::StrDraw(L"取ると体力が全回復する。", 0, 120, 30, c);
	Font::StrDraw(L"白血球", 0, 160, 30, c);
	Font::StrDraw(L"白く浮遊している楕円形状のアイテム", 0, 210, 30, c);
	Font::StrDraw(L"取るとレーザーと拡散弾の補給が出来る。", 0, 240, 30, c);
	Font::StrDraw(L"エンターでゲーム開始!", 0, 280, 50, c);
}