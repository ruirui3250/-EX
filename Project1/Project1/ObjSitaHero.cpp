//使用するヘ5ッダーファイルINput
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "ObjSitaHero.h"
#include"GameL\HitBoxManager.h"
#include "GameL/DrawFont.h"
#include"CObjAngleBulletHero.h"
#include"GameL/Audio.h"

//位置情報X取得用
float CObjSitaHero::GetX()
{
	return m_x;
}

//位置情報Y取得用
float CObjSitaHero::GetY()
{
	return m_y;
}

//イニシャライズ
void CObjSitaHero::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_la = 100;
	m_hp = 3;
	m_ka = 3;
	m_x = 350;
	m_y = 0;
	m_time = 0;
	//当たり判定用hitboxを作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_SITA_HERO, 100);
}


//アクション
void CObjSitaHero::Action()
{
	m_time++;
	/*-------------------------------タイトル画面に戻る--------------------------*/
	//if (Input::GetVKey('S') == true)
	//{
	//	if (m_key_flag == true)
	//	{
	//		Scene::SetScene(new CSceneTitle());
	//		m_key_flag = false;
	//	}

	//}
	/*---------------主人公機のレーザー弾丸発射-------------------------*/
	if (Input::GetVKey(VK_SPACE) == true)
	{
		if (m_la >= 0)
		{
			//発射音を流す
			Audio::Start(4);
			//弾丸オブジェクト作成
			CObjSitaLaserBullet* obj_b = new CObjSitaLaserBullet(m_x + 3.0f, m_y -= 0.0f);//弾丸オブジェクト
			Objs::InsertObj(obj_b, OBJ_SITA_LASER_BULLET, 100);//作った弾丸オブジェクト
			m_la--;
		}



	}
	/*----------------------主人公機通常弾丸-----------------------------------*/
	if (Input::GetVKey('Z') == true)
	{

		m_vx = 0.0f;
		m_vy = +1.0f;
		if (m_f == true)
		{
			//発射音を流す
			Audio::Start(2);

			//弾丸オブジェクト作成
			CObjSitaBullet* obj_b = new CObjSitaBullet(m_x + 3.0f, m_y -= 0.0f);//弾丸オブジェクト
			Objs::InsertObj(obj_b, OBJ_SITA_BULLET, 100);//作った弾丸オブジェクト
			m_f = false;
		}

	}
	else
	{
		m_f = true;
	}

	//主人公機の拡散弾丸弾発射
	/*------------------------これは一回のみ発射可能------------------*/
	//主人公機の拡散弾丸発射
	if (Input::GetVKey('X') == true)
	{
		m_ka -= 1;
		if (m_ka <= 0 == false)
			if (m_f == true)
			{
				//発射音を流す
				Audio::Start(5);
				//19発同時発射
				CObjAngleBulletHero* obj_b;
				for (int i = 0; i < 360; i += 20)
				{
					obj_b = new CObjAngleBulletHero(m_x + 30.0f, m_y + 30.0f, i, 7.0f);
					Objs::InsertObj(obj_b, OBJ_ANGLE_BULLET_HERO, 100);
					m_f = false;
				}
			}

			else
			{
				m_f = true;
			}
		//m_ka -= 1;
		//if (m_ka <= 0 == false)
		//	if (m_f == true)
		//	{
		//		//19発同時発射
		//		CObjAngleBulletHero* obj_b;
		//		for (int i = 0; i < 360; i += 20)
		//		{
		//			obj_b = new CObjAngleBulletHero(m_x + 30.0f, m_y + 30.0f, i, 7.0f);
		//			Objs::InsertObj(obj_b, OBJ_ANGLE_BULLET_HERO, 100);
		//			m_f = false;
		//		}
		//	}


	}
	//主人公機の移動
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_x += 5.0f;

	}
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_x -= 5.0f;

	}
	if (Input::GetVKey(VK_UP) == true)

	{
		m_y -= 5.0f;
	}
	if (Input::GetVKey(VK_DOWN) == true)

	{
		m_y += 5.0f;
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


	////ELEMENT_ENEMYを持つオブジェクトと接触したらライフ1つ減らす
	if (m_f == true)
	{
		if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
		{

			m_hp -= 1;
			m_f = false;
		}
		if (m_hp <= 0)
		{
			this->SetStatus(false);//自身に削除命令を出す
			Hits::DeleteHitBox(this);//主人公が所有するHitBoxに代入する

			////主人公機消滅でシーンをゲームオーバーに移行する
			Scene::SetScene(new CSceneGameOver3());
			return;
		}

	}

	/*-----------時間経過でアイテム復活-------------------------------------------*/
	if (m_time == 600)
	{
		m_hp = 3;

	}
	if (m_time == 600)//時間経過により弾回復
	{

		m_ka = 3;//拡散弾丸
	}
	if (m_time == 1200)//時間経過により弾回復
	{

		m_ka = 3;//拡散弾丸
	}
	if (m_time == 1800)//時間経過により弾回復
	{

		m_ka = 3;//拡散弾丸
	}
	/*------------------------------------------------------*/
	//ELEMENT_ITEMを持つオブジェクトと接触したらライフ回復
	if (hit->CheckElementHit(ELEMENT_LIFE_ITEM) == true)
	{
		Audio::Start(20);
		m_hp = 3;//HP
		return;


	}



	//ELEMENT_ENEMYを持つオブジェクトと接触したら主人公機削除
	//if (hit->CheckObjNameHit(ELEMENT_ENEMY) != nullptr)
	//{
	//	m_hp -= 1;

	//	if (m_hp == 0)
	//	{
	//		this->SetStatus(false);//自身に削除命令を出す
	//		Hits::DeleteHitBox(this);//主人公が所有するHitBoxに代入する

	//		//主人公機消滅でシーンをゲームオーバーに移行する
	//		Scene::SetScene(new CSceneGameOver());
	//	}
	//}
}
//ドロー
void CObjSitaHero::Draw()
{
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f, };
	wchar_t str[256];

	/*---------HP表示---------------------*/

	if (m_hp == 3)
	{
		swprintf_s(str, L"♥♥♥", m_hp);
		Font::StrDraw(str, 155, 20, 60, c);
		this->SetPrio(50);
	}
	if (m_hp == 2)
	{
		swprintf_s(str, L"♥♥♡", m_hp);
		Font::StrDraw(str, 155, 20, 60, c);
		this->SetPrio(50);
	}
	if (m_hp == 1)
	{
		swprintf_s(str, L"♥♡♡", m_hp);
		Font::StrDraw(str, 155, 20, 60, c);
		this->SetPrio(50);
	}
	/*-------------------拡散団残りメーター-----------------*/
	swprintf_s(str, L"拡散弾丸：", m_hp);
	Font::StrDraw(str, 20, 70, 30, c);
	this->SetPrio(50);
	if (m_ka == 3)
	{
		swprintf_s(str, L"発射可能！！", m_ka);
		Font::StrDraw(str, 150, 70, 40, c);
		this->SetPrio(50);
	}
	if (m_ka == 2)
	{
		swprintf_s(str, L"発射可能！！", m_ka);
		Font::StrDraw(str, 150, 70, 40, c);
		this->SetPrio(50);
	}
	if (m_ka == 1)
	{
		swprintf_s(str, L"発射可能！！", m_ka);
		Font::StrDraw(str, 150, 70, 40, c);
		this->SetPrio(50);
	}

	if (m_ka <= 0)
	{
		swprintf_s(str, L"Eroor", m_ka);
		Font::StrDraw(str, 150, 70, 40, c);
		this->SetPrio(50);
	}
	/*-------------レーザーゲージ-------------------*/
	swprintf_s(str, L"レーザー：", m_hp);
	Font::StrDraw(str, 20, 110, 30, c);
	this->SetPrio(50);
	if (m_la == 100)
	{
		swprintf_s(str, L"■■■■■■■■■■", m_la);
		Font::StrDraw(str, 150, 110, 40, c);
		this->SetPrio(50);
	}
	if (m_la >= 90)
	{
		swprintf_s(str, L"■■■■■■■■■□", m_la);
		Font::StrDraw(str, 150, 110, 40, c);
		this->SetPrio(50);
	}
	if (m_la >= 80)
	{
		swprintf_s(str, L"■■■■■■■■□□", m_la);
		Font::StrDraw(str, 150, 110, 40, c);
		this->SetPrio(50);
	}
	if (m_la >= 70)
	{
		swprintf_s(str, L"■■■■■■■□□□", m_la);
		Font::StrDraw(str, 150, 110, 40, c);
		this->SetPrio(50);
	}
	if (m_la >= 60)
	{
		swprintf_s(str, L"■■■■■■□□□□", m_la);
		Font::StrDraw(str, 150, 110, 40, c);
		this->SetPrio(50);
	}
	if (m_la >= 50)
	{
		swprintf_s(str, L"■■■■■□□□□□", m_la);
		Font::StrDraw(str, 150, 110, 40, c);
		this->SetPrio(50);
	}
	if (m_la >= 40)
	{
		swprintf_s(str, L"■■■■□□□□□□", m_la);
		Font::StrDraw(str, 150, 110, 40, c);
		this->SetPrio(50);
	}
	if (m_la >= 30)
	{
		swprintf_s(str, L"■■■□□□□□□□", m_la);
		Font::StrDraw(str, 150, 110, 40, c);
		this->SetPrio(50);
	}
	if (m_la >= 20)
	{
		swprintf_s(str, L"■■□□□□□□□□", m_la);
		Font::StrDraw(str, 150, 110, 40, c);
		this->SetPrio(50);
	}
	if (m_la >= 10)
	{
		swprintf_s(str, L"■□□□□□□□□□", m_la);
		Font::StrDraw(str, 150, 110, 40, c);
		this->SetPrio(50);
	}
	if (m_la >= 0)
	{
		swprintf_s(str, L"□□□□□□□□□□", m_la);
		Font::StrDraw(str, 150, 110, 40, c);
		this->SetPrio(50);
	}
	if (m_la == -1)
	{
		swprintf_s(str, L"Error", m_la);
		Font::StrDraw(str, 150, 110, 40, c);
		this->SetPrio(50);
	}
	if (m_la <= -1)
	{
		swprintf_s(str, L"Error", m_la);
		Font::StrDraw(str, 150, 110, 40, c);
		this->SetPrio(50);
	}

	if (m_la == -1)
	{
		swprintf_s(str, L"Error", m_la);
		Font::StrDraw(str, 150, 110, 40, c);
		this->SetPrio(50);
	}
	if (m_la <= -1)
	{
		swprintf_s(str, L"Error", m_la);
		Font::StrDraw(str, 150, 110, 40, c);
		this->SetPrio(50);
	}


	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 32.0f;
	src.m_bottom = 32.0f;
	//表示位置の設定
		//dst.m_top = 480.0f + m_y;
		//dst.m_left = 128.0f + m_x;
		//dst.m_right = 96.0f + m_x;
		//dst.m_bottom = 512.0f + m_y;
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;
	Draw::Draw(0, &src, &dst, c, 0.0f);

}