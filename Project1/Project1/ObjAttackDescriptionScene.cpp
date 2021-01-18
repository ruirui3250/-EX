//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameHead.h"
#include"ObjAttackDescriptionScene.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjAttack::Init()
{
	m_key_flag = false;
}
//アクション
void CObjAttack::Action()
{
	/*エンターキーを押して次の面に移行する*/
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneItemD());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjAttack::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	////フォントの表示
	Font::StrDraw(L"操作方法", 0, 0, 30, c);
	Font::StrDraw(L"Zキー", 0, 50, 30, c);
	Font::StrDraw(L"通常弾発射", 0, 80, 30, c);
	Font::StrDraw(L"Xキー", 0, 130, 30, c);
	Font::StrDraw(L"拡散弾発射　障害物を破壊可能", 0, 160, 30, c);
	Font::StrDraw(L"Aキー", 0, 210, 30, c);
	Font::StrDraw(L"レーザー発射　敵を貫いて攻撃できる", 0, 240, 30, c);
	Font::StrDraw(L"レーザーと拡散弾は左上のゲージがなくなるまで使用可能", 0, 300, 30, c);
	Font::StrDraw(L"エンターで次のページへ", 0, 360, 50, c);
}