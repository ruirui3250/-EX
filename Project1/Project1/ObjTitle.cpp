//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL/Audio.h"


#include"GameHead.h"
#include"ObjTitle.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{
	m_key_flag = false;
}
//アクション
void CObjTitle::Action()
{
	//エンターキーを押してシーンタイトルを移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneAttack());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
	//3
	
	if (Input::GetVKey('3') == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new TatesukuSceneMain());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
	//2
	if (Input::GetVKey('2') == true)
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
	//4
	if (Input::GetVKey('4') == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain4());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
	//5
	if (Input::GetVKey('5') == true)
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

}

//ドロー
void CObjTitle::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画切り取り位置
	RECT_F dst;//描画先表示

	//切り取り位置
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(1, &src, &dst, c, 0.0f);
}