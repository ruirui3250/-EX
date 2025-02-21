﻿
//使用ヘッダー
#include <stdlib.h>
#include <time.h>
#include "GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include "GameL/DrawFont.h"
#include "CObjMixBoss.h"
#include"UtilityModule.h"
//使用するネームスペース
using namespace GameL;
//コンストラクタ
CObjMIXBoss::CObjMIXBoss(float x, float y)
{
	m_x = x;
	m_y = y;
}
//イニシャライズ
void CObjMIXBoss::Init()
{
	m_hp = 250;
	m_time = 0;
	m_r = 0.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_x, m_y, 280, 280, ELEMENT_ENEMY, OBJ_MIX_BOSS, 50);
}
//アクション
void CObjMIXBoss::Action()
{
	m_time++;
	srand(time(NULL));
    a = rand() % 300 + 400;//ランダムで出力します
	srand(time(NULL));
	b = rand() % 300 + 200;//ランダムで出力します
	srand(time(NULL));
	c = rand() % 300 + 400;//ランダムで出力します
	srand(time(NULL));
	d = rand() % 300 + 200;//ランダムで出力します
	////通常弾発射
	//if (m_time % 50 == 0)
	//{
	//	//弾丸発射オブジェクト
	//	CObjBulletEnemy2* obj_b = new CObjBulletEnemy2(m_x+a , m_y+b);
	//	Objs::InsertObj(obj_b, OBJ_BULLET_ENEMY2, 100);
	//	return;
	//}
	//if (m_time % 100 == 0)
	//{
	//	//弾丸発射オブジェクト
	//	CObjBulletEnemy2* obj_b = new CObjBulletEnemy2(m_x + a, m_y + b);
	//	Objs::InsertObj(obj_b, OBJ_BULLET_ENEMY2, 100);
	//	return;
	//}
	//if (m_time % 150 == 0)
	//{
	//	//弾丸発射オブジェクト
	//	CObjAttackEnemy2* obj_b = new CObjAttackEnemy2(m_x + a, m_y + b);
	//	Objs::InsertObj(obj_b, OBJ_ATTACK_ENEMY2, 100);
	//	return;
	//}

	///*------------------------------別のタイミング----------------------------------------------*/
	///*--------------------------------------bukatouka------------------------*/
	//if (m_time % 30 == 0)
	//{
	// //弾丸発射オブジェクト
	// CObjAttackEnemy2* obj_b = new CObjAttackEnemy2(m_x + 170, m_y + 400);
	// Objs::InsertObj(obj_b, OBJ_ATTACK_ENEMY2, 100);
	// return;
	//}
	//if (m_time % 40 == 0)
	//{
	// //弾丸発射オブジェクト
	// CObjTateEnemy2* obj_b = new CObjTateEnemy2(m_x + 310, m_y + 50);
	// Objs::InsertObj(obj_b, OBJ_TATE_ENEMY2, 100);
	// return;
	//}
	//if (m_time % 40 == 0)
	//{
	//	//弾丸発射オブジェクト
	//	CObjTateEnemy2* obj_b = new CObjTateEnemy2(m_x + 310, m_y + 100);
	//	Objs::InsertObj(obj_b, OBJ_TATE_ENEMY2, 100);
	//	return;
	//}
	//if (m_time % 40 == 0)
	//{
	//	//弾丸発射オブジェクト
	//	CObjTateEnemy2* obj_b = new CObjTateEnemy2(m_x + 310, m_y + 25);
	//	Objs::InsertObj(obj_b, OBJ_TATE_ENEMY2, 100);
	//	return;
	//}
	//if (m_time % 40 == 0)
	//{
	//	//弾丸発射オブジェクト
	//	CObjTateEnemy2* obj_b = new CObjTateEnemy2(m_x + 310, m_y + 75);
	//	Objs::InsertObj(obj_b, OBJ_TATE_ENEMY2, 100);
	//	return;
	//}

	//if (m_time % 10 == 0)
	//{
	//	//血栓発射オブジェクト
	//	CObjYokoKesen* obj_b = new CObjYokoKesen(m_x, m_y+300);
	//	Objs::InsertObj(obj_b, OBJ_YOKO_KESEN, 100);
	//	return;
	//}
	//


	//if (m_time % 50 == 0)
	//{
	// //弾丸発射オブジェクト
	// CObjHomingEnemy* obj_b = new CObjHomingEnemy(m_x + 250, m_y + 100);
	// Objs::InsertObj(obj_b, OBJ_HOMING_ENEMY, 100);
	//}
	//if (m_time % 60 == 0)
	//{
	// //弾丸発射オブジェクト
	// CObjTateEnemy* obj_b = new CObjTateEnemy(m_x + 270, m_y + 100);
	// Objs::InsertObj(obj_b, OBJ_BULLET_ENEMY, 100);
	//}
	//if (m_time % 100 == 0)
	//{
	//	//弾丸発射オブジェクト
	//	CObjSitaEnemy2* obj_b = new CObjSitaEnemy2(m_x + 190, m_y + 100);
	//	Objs::InsertObj(obj_b, OBJ_SITA_ENEMY2, 100);
	//}
	//防衛血栓//横
	if (m_time % a == 0)
	{
		
		CObjYokoKesen* obj2 = new CObjYokoKesen(600,280);
		Objs::InsertObj(obj2, OBJ_TATEKESEN, 500);

	}
	if (m_time % b == 0)
	{

		CObjYokoKesen* obj2 = new CObjYokoKesen(600, 350);
		Objs::InsertObj(obj2, OBJ_TATEKESEN, 500);

	}
	if (m_time % c == 0)
	{

		CObjYokoKesen* obj2 = new CObjYokoKesen(600, 420);
		Objs::InsertObj(obj2, OBJ_TATEKESEN, 500);

	}
	if (m_time % d == 0)
	{

		CObjYokoKesen* obj2 = new CObjYokoKesen(600, 490);
		Objs::InsertObj(obj2, OBJ_TATEKESEN, 500);

	}
	//縦
	if (m_time % a == 0)
	{

		CObjSitaKesen* obj6 = new CObjSitaKesen(m_x -100.0f, 600);
		Objs::InsertObj(obj6, OBJ_SITA_KESEN, 50);

	}
	if (m_time % b == 0)
	{

		CObjSitaKesen* obj6 = new CObjSitaKesen(m_x -30.0f, 600);
		Objs::InsertObj(obj6, OBJ_SITA_KESEN, 50);

	}
	if (m_time % c == 0)
	{

		CObjSitaKesen* obj6 = new CObjSitaKesen(m_x+40.0f, 600);
		Objs::InsertObj(obj6, OBJ_SITA_KESEN, 50);

	}
	if (m_time % d == 0)
	{

		CObjSitaKesen* obj6 = new CObjSitaKesen(m_x+110.0f, 600);
		Objs::InsertObj(obj6, OBJ_SITA_KESEN, 50);

	}
	if (m_time % a == 0)
	{

		CObjSitaKesen* obj6 = new CObjSitaKesen(m_x + 180.0f, 600);
		Objs::InsertObj(obj6, OBJ_SITA_KESEN, 50);

	}
	//m_timeの初期化
	if (m_time > 1000)
	{
		m_time = 0;
		return;
	}
	//角度計算
	m_r += 1.0f;

	//360で初期値に戻す。
	if (m_r > 360.0f)
		m_r = 1.0f;

	//移動方向
	m_vy = 0.0f;
	m_vx = sin(3.14 / 180 * m_r);//sinΘを求めm_vyに入れる

	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//速度を求める
	m_vx *= 1.5f;
	m_vy *= 1.5f;
	//移動ベクトルを座標に加算する。
	m_x += m_vx;
	m_y += m_vy;
	//HitBoxの内容更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
	//領域外に出たら敵機を破棄。
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false); //自身に削除命令を出す。
		Hits::DeleteHitBox(this);//敵機弾丸が所有するHitBoxを削除
		return;
	}
	if (hit->CheckObjNameHit(OBJ_HERO5) != nullptr)
	{
		m_del = true; //消滅実行
		hit->SetInvincibility(true);//当たり判定無効
		return;
	}
	// 弾丸と接触しているかどうか調べる
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
		return;
	}

	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		Scene::SetScene(new CSceneWin6());
		return;
	}
	//弾丸と接触しているかどうか調べる
	if (hit->CheckObjNameHit(OBJ_ANGLE_BULLET_HERO) != nullptr)
	{
		m_hp -= 1;
		return;
	}

	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		Scene::SetScene(new CSceneWin6());
		return;

	}
	// 弾丸と接触しているかどうか調べる
	if (hit->CheckObjNameHit(OBJ_SITA_BULLET) != nullptr)
	{
		m_hp -= 1;
		return;
	}

	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		Scene::SetScene(new CSceneWin6());
		return;
	}
	// 弾丸と接触しているかどうか調べる
	if (hit->CheckObjNameHit(OBJ_TATE_BULLET) != nullptr)
	{
		m_hp -= 1;
		return;
	}

	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		Scene::SetScene(new CSceneWin6());
		return;
	}
	// 弾丸と接触しているかどうか調べる
	if (hit->CheckObjNameHit(OBJ_SITA_LASER_BULLET) != nullptr)
	{
		m_hp -= 1;
		return;
	}

	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		Scene::SetScene(new CSceneWin6());
		return;
	}
	// 弾丸と接触しているかどうか調べる
	if (hit->CheckObjNameHit(OBJ_TATE_LASER_BULLET) != nullptr)
	{
		m_hp -= 1;
		return;
	}

	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		Scene::SetScene(new CSceneWin6());
		return;
	}
}

//ドロー
void CObjMIXBoss::Draw()
{
	//描画カラー情報　R-RED G=GREEN B=BLUE A=ALPHA(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };


	wchar_t str[256];
	swprintf_s(str, L"BossLife=%d", m_hp);
	Font::StrDraw(str, 400, 500, 20, c);
	if (m_hp == 100)
	{
		swprintf_s(str, L"████████████████████", m_hp);
		Font::StrDraw(str, 400, 550, 20, c);
	}
	if (m_hp >= 90)
	{
		swprintf_s(str, L"███████████████████", m_hp);
		Font::StrDraw(str, 400, 550, 20, c);
	}
	if (m_hp >= 80)
	{
		swprintf_s(str, L"███████████████", m_hp);
		Font::StrDraw(str, 400, 550, 20, c);
	}
	if (m_hp >= 70)
	{
		swprintf_s(str, L"█████████████", m_hp);
		Font::StrDraw(str, 400, 550, 20, c);
	}
	if (m_hp >= 60)
	{
		swprintf_s(str, L"███████████", m_hp);
		Font::StrDraw(str, 400, 550, 20, c);
	}
	if (m_hp >= 50)
	{
		swprintf_s(str, L"█████████", m_hp);
		Font::StrDraw(str, 400, 550, 20, c);
	}
	if (m_hp >= 40)
	{
		swprintf_s(str, L"███████", m_hp);
		Font::StrDraw(str, 400, 550, 20, c);
	}
	if (m_hp >= 30)
	{
		swprintf_s(str, L"████", m_hp);
		Font::StrDraw(str, 400, 550, 20, c);
	}
	if (m_hp >= 20)
	{
		swprintf_s(str, L"███", m_hp);
		Font::StrDraw(str, 400, 550, 20, c);
	}
	if (m_hp >= 10)
	{
		swprintf_s(str, L"██", m_hp);
		Font::StrDraw(str, 400, 550, 20, c);
	}
	if (m_hp <= 10)
	{
		swprintf_s(str, L"█", m_hp);
		Font::StrDraw(str, 400, 550, 20, c);
	}

	RECT_F src; //描画切り取り位置
	RECT_F dst;//描画先表示

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 300.0f;
	src.m_bottom = 300.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 300.0f + m_x;
	dst.m_bottom = 300.0f + m_y;

	//0番目に登録したグラフィックをsrc.dst.cの情報をもとに描画。
	Draw::Draw(4, &src, &dst, c, 0.0f);

}