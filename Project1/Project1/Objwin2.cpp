//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

//448579
#include"GameHead.h"
#include"Objwin2.h"

//使用するネームスペース
using namespace GameL;

//CObjWin2::CObjWin2()
//{
//
//}

//イニシャライズ
void CObjWin2::Init()
{
	m_key_flag = false;
}
//アクション
void CObjWin2::Action()
{
	/*エンターキーを押して次の面に移行する*/
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain2());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjWin2::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	////フォントの表示
	//Font::StrDraw(L"You Win!", 270, 200, 50, c);
	//Font::StrDraw(L"エンターで次のステージへ!!", 170, 500, 30, c);
}