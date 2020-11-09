﻿//使用するヘ5ッダーファイルINput
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "ObjHero.h"
#include"GameL\HitBoxManager.h"


//イニシャライズ
void CObjHero::Init()
{
	m_hp = 3;
	m_ka = 1;
	m_x = 6;
	//当たり判定用hitboxを作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_HERO, 100);

	//blockの衝突状態の確認用
	m_hit_up=false;
	m_hit_down=false;
	m_hit_left=false;
	m_hit_right=false;
}

//アクション
/*--------------------主人公の弾------------------------------*/
void CObjHero::Action()
{
	//主人公機の弾丸発射
	if (Input::GetVKey('Z') == true)
	{
		if (m_f == true)
		{

			//弾丸オブジェクト作成
			CObjBullet* obj_b = new CObjBullet(m_x + 30.0f, m_y + 3.0f);//弾丸オブジェクト
			Objs::InsertObj(obj_b, OBJ_BULLET, 100);//作った弾丸オブジェクト
			m_f = false;
		}
	}
	//主人公機の弾丸発射
	if (Input::GetVKey('X') == true)
	{
		m_ka -= 1;
		if (m_ka <= 0 == false)

			if (m_f == true)
			{

				//弾丸オブジェクト作成
				CObjAngleBulletHero* obj_b = new CObjAngleBulletHero(m_x + 30.0f, m_y + 3.0f);//弾丸オブジェクト
				Objs::InsertObj(obj_b, OBJ_ANGLE_BULLET_HERO, 100);//作った弾丸オブジェクト
				m_f = false;
			}
		if (Input::GetVKey('X') >= 5)
		{
			m_f = false;

		}
	}

	else
	{
		m_f = true;
	}
		
	}
	/*-------------------------主人公の移動---------------------*/
	//主人公機の移動
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_x += 6.0f;

	}
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_x -= 6.0f;

	}
	if (Input::GetVKey(VK_UP) == true)

	{
		m_y -= 6.0f;
	}
	if (Input::GetVKey(VK_DOWN) == true)

	{
		m_y += 6.0f;
	}

	//主人公が領域外に行かない処理
	if (m_x + 32.0 > 800.0f)
	{
		m_x = 800.0f - 32.0f;//原点に移動
	}
	if (m_y + 32.0 > 600.0f)
	{
		m_y = 600.0f - 32.0f;
	}
	if (m_y < 0.0f)
	{
		m_y = 0.0f;
	}
	if (m_x < 0.0f)
	{
		m_x = 0.0f;
	}


	//HITboxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this); //作成したhitBox更新用の入り口を取り出す
	hit->SetPos(m_x, m_y);				  //入り口から新しい位置（主人公機の位置）情報に置き換える

	//ELEMENT_ENEMYを持つオブジェクトと接触したらライフ1つ減らす
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		m_hp -= 1;
		if (m_hp == 0)
		{
			this->SetStatus(false);//自身に削除命令を出す
			Hits::DeleteHitBox(this);//主人公が所有するHitBoxに代入する

			//主人公機消滅でシーンをゲームオーバーに移行する
			Scene::SetScene(new CSceneGameOver());
		}
	}

	//ELEMENT_ENEMYを持つオブジェクトと接触したら主人公機削除
	//if (hit->CheckObjNameHit(ELEMENT_ENEMY) != nullptr)
	//{
	//	m_hp -= 1;

		//if (m_hp == 0)
		//{
		//	this->SetStatus(false);//自身に削除命令を出す
		//	Hits::DeleteHitBox(this);//主人公が所有するHitBoxに代入する

		//	//主人公機消滅でシーンをゲームオーバーに移行する
		//	Scene::SetScene(new CSceneGameOver());
		//}
	//}
}
//ドロー
void CObjHero::Draw()
{
/*-------------------主人公ライフ------------------*/
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f, };

	wchar_t str[256];
	swprintf_s(str, L"HP=%d", m_hp);
	Font::StrDraw(str, 50, 20, 30, c);
if (m_hp == 3)
{
	swprintf_s(str, L"♡♡♡", m_hp);
	Font::StrDraw(str, 100, 70, 40, c);
}
if (m_hp == 2)
{
	swprintf_s(str, L"♡♡", m_hp);
	Font::StrDraw(str, 100, 70, 40, c);
}
if (m_hp == 1)
{
	swprintf_s(str, L"♡", m_hp);
	Font::StrDraw(str, 100, 70, 40, c);
}
/*--------------------拡散弾使用確認メーター---------*/
if (m_ka == 5)
{
	swprintf_s(str, L"*****", m_ka);
	Font::StrDraw(str, 40, 30, 60, c);
}

	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f, };
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 32.0f;
	src.m_bottom = 32.0f;
	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	Draw::Draw(1, &src, &dst, c, 0.0f);
}