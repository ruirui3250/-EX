//使用するヘッダーファイルINput
#include	"GameL\DrawFont.h"
#include	"GameL\WinInputs.h"
#include	"GameL\SceneManager.h"
#include	"GameHead.h"
#include	"ObjGameOver4.h"
#include	"GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameOver4::Init()
{
	m_key_flag = false;
}
//アクション
void CObjGameOver4::Action()
{
	//エンターキーを押してシーン：ゲームTitleに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain5());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}

	//Vキーを押してシーン：ゲームメイン1に移行する
	if (Input::GetVKey('V') == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new  CSceneTitle());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjGameOver4::Draw()
{
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f, };
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;
	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);



}