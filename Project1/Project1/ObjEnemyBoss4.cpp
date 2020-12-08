//使用ヘッダー
#include "GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include "GameL/DrawFont.h"
#include "ObjEnemyBoss4.h"
#include"UtilityModule.h"
//使用するネームスペース
using namespace GameL;
//コンストラクタ
CObjEnemyBoss4::CObjEnemyBoss4(float x, float y)
{
	m_x = x;
	m_y = y;
}
//イニシャライズ
void CObjEnemyBoss4::Init()
{
	m_hp = 10;
	m_time = 0;
	m_r = 0.0f;
	m_vx = 250.0f;
	m_vy = 250.0f;


	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_x, m_y, 10, 10, ELEMENT_ENEMY, OBJ_BOSS_ENEMY4, 50);
}
//アクション
void CObjEnemyBoss4::Action()
{
	m_time++;

	//通常弾発射
	if (m_time % 50 == 0)
	{
		//弾丸発射オブジェクト
		CObjEnemyBossBullet4* obj_b = new CObjEnemyBossBullet4(m_x, m_y);
		Objs::InsertObj(obj_b, OBJ_BOSS_BULLET_ENEMY, 100);
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
	hit->SetPos(m_x, m_y);
	//領域外に出たら敵機を破棄。
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false); //自身に削除命令を出す。
		Hits::DeleteHitBox(this);//敵機弾丸が所有するHitBoxを削除
		return;
	}
	// 弾丸と接触しているかどうか調べる
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
	}

	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//弾丸と接触しているかどうか調べる
	if (hit->CheckObjNameHit(OBJ_ANGLE_BULLET_HERO) != nullptr)
	{
		m_hp -= 1;
	}

	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		Scene::SetScene(new CSceneWin5());

	}
	// 弾丸と接触しているかどうか調べる
	if (hit->CheckObjNameHit(OBJ_SITA_BULLET) != nullptr)
	{
		m_hp -= 1;
	}

	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		Scene::SetScene(new CSceneWin5());
	}
	// 弾丸と接触しているかどうか調べる
	if (hit->CheckObjNameHit(OBJ_TATE_BULLET) != nullptr)
	{
		m_hp -= 1;
	}

	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	// 弾丸と接触しているかどうか調べる
	if (hit->CheckObjNameHit(OBJ_SITA_LASER_BULLET) != nullptr)
	{
		m_hp -= 1;
	}

	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		Scene::SetScene(new CSceneWin5());
	}
	// 弾丸と接触しているかどうか調べる
	if (hit->CheckObjNameHit(OBJ_TATE_LASER_BULLET) != nullptr)
	{
		m_hp -= 1;
	}

	//HPが0になったら破棄
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//ドロー
void CObjEnemyBoss4::Draw()
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
	src.m_right = 25.0f;
	src.m_bottom = 25.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 25.0f + m_x;
	dst.m_bottom = 25.0f + m_y;

	//0番目に登録したグラフィックをsrc.dst.cの情報をもとに描画。
	Draw::Draw(4, &src, &dst, c, 0.0f);

}