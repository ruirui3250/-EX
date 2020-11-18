//使用ヘッダー
#include "GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include "GameL/DrawFont.h"
#include "ObjTateBoss.h"
#include"UtilityModule.h"
//使用するネームスペース
using namespace GameL;
//コンストラクタ
CObjTateBoss::CObjTateBoss(float x, float y)
{
	m_x = x;
	m_y = y;
}
//イニシャライズ
void CObjTateBoss::Init()
{
	m_hp = 100;
	m_time = 0;
	m_r = 0.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;


	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_x + 100, m_y + 50, 250, 200, ELEMENT_ENEMY, OBJ_TATE_BOSS, 1);
}
//アクション
void CObjTateBoss::Action()
{
	m_time++;

	//通常弾発射
	if (m_time % 100 == 0)
	{
		//弾丸発射オブジェクト
		CObjTateBulletEnemy* obj_b = new CObjTateBulletEnemy(m_x + 100, m_y + 150);
		Objs::InsertObj(obj_b, OBJ_BULLET_ENEMY, 100);
	}
	if (m_time % 100 == 0)
	{
		//弾丸発射オブジェクト
		CObjTateBulletEnemy* obj_b = new CObjTateBulletEnemy(m_x + 150, m_y + 150);
		Objs::InsertObj(obj_b, OBJ_BULLET_ENEMY, 100);
	}

	if (m_time % 100 == 0)
	{
		//弾丸発射オブジェクト
		CObjTateBulletEnemy* obj_b = new CObjTateBulletEnemy(m_x + 270, m_y + 150);
		Objs::InsertObj(obj_b, OBJ_BULLET_ENEMY, 100);
	}
	if (m_time % 100 == 0)
	{
		//弾丸発射オブジェクト
		CObjTateBulletEnemy* obj_b = new CObjTateBulletEnemy(m_x + 310, m_y + 150);
		Objs::InsertObj(obj_b, OBJ_BULLET_ENEMY, 100);
	}

	/*------------------------------別のタイミング----------------------------------------------*/
	if (m_time % 150 == 0)
	{
		//弾丸発射オブジェクト
		CObjTateBulletEnemy* obj_b = new CObjTateBulletEnemy(m_x + 200, m_y + 100);
		Objs::InsertObj(obj_b, OBJ_BULLET_ENEMY, 100);
	}
	/*--------------------------------------bukatouka------------------------*/
	//if (m_time % 30 == 0)
	//{
	//	//弾丸発射オブジェクト
	//	CObjTateBulletEnemy* obj_b = new CObjTateBulletEnemy(m_x + 170, m_y + 100);
	//	Objs::InsertObj(obj_b, OBJ_BULLET_ENEMY, 100);
	//}
	//if (m_time % 40 == 0)
	//{
	//	//弾丸発射オブジェクト
	//	CObjTateEnemy* obj_b = new CObjTateEnemy(m_x + 310, m_y + 100);
	//	Objs::InsertObj(obj_b, OBJ_BULLET_ENEMY, 100);
	//}
	//if (m_time % 50 == 0)
	//{
	//	//弾丸発射オブジェクト
	//	CObjTateEnemy* obj_b = new CObjTateEnemy(m_x + 250, m_y + 100);
	//	Objs::InsertObj(obj_b, OBJ_BULLET_ENEMY, 100);
	//}
	//if (m_time % 60 == 0)
	//{
	//	//弾丸発射オブジェクト
	//	CObjTateEnemy* obj_b = new CObjTateEnemy(m_x + 270, m_y + 100);
	//	Objs::InsertObj(obj_b, OBJ_BULLET_ENEMY, 100);
	//}
	if (m_time % 100 == 0)
	{
		//弾丸発射オブジェクト
		CObjTateEnemy* obj_b = new CObjTateEnemy(m_x + 190, m_y + 100);
		Objs::InsertObj(obj_b, OBJ_BULLET_ENEMY, 100);
	}

	//m_timeの初期化
	if (m_time > 1000)
	{
		m_time = 0;
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
	hit->SetPos(m_x + 100, m_y + 50);
	//領域外に出たら敵機を破棄。
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false); //自身に削除命令を出す。
		Hits::DeleteHitBox(this);//敵機弾丸が所有するHitBoxを削除
		return;
	}
	//弾丸と接触したらhpを減らす。
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
	}


	//HPが0になったら破棄。
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		Scene::SetScene(new CSceneWin4());
	}
}

//ドロー
void CObjTateBoss::Draw()
{
	
	//描画カラー情報　R-RED G=GREEN B=BLUE A=ALPHA(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };


	wchar_t str[256];
	swprintf_s(str, L"BossLife=%d",m_hp);
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
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 512.0f + m_x;
	dst.m_bottom = 512.0f + m_y;

	//0番目に登録したグラフィックをsrc.dst.cの情報をもとに描画。
	Draw::Draw(4, &src, &dst, c, 0.0f);

}