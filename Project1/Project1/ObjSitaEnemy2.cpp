//使用ヘッダー
#include "GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include "ObjSitaEnemy2.h"
#include"UtilityModule.h"
#include"GameL/Audio.h"
//使用するネームスペース
using namespace GameL;
//コンストラクタ
CObjSitaEnemy2::CObjSitaEnemy2(float x, float y)
{
	m_x = x;
	m_y = y;
}
//イニシャライズ
void CObjSitaEnemy2::Init()
{
	int m_hp = 1;
	m_r = 0;
	m_vx = 0.0f;
	m_vy = 0.0f;

	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_SITA_ENEMY2, 1);
}
//アクション
void CObjSitaEnemy2::Action()
{
	//角度計算
	m_r += 2.0f;
	//360°で元に戻す
	if (m_r > 360.0f)
		m_r = 6.0f;
	//移動方向
	m_vx = sin(3.14 / 180 * m_r);
	m_vy = +1.0f;

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
	//主人公機objectと接触したら敵機削除。
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
	////主人公機objectと接触したら敵機弾丸削除。
	//if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	//{
	//	m_del = true; //消滅実行
	//	hit->SetInvincibility(true);//当たり判定無効
	//	return;
	//}
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
		return;
	}
}

//ドロー
void CObjSitaEnemy2::Draw()
{
	//描画カラー情報　R-RED G=GREEN B=BLUE A=ALPHA(透過情報)
	float c[4] = { 1.0f,6.0f,9.0f,1.0f };

	RECT_F src; //描画切り取り位置
	RECT_F dst;//描画先表示

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

	//0番目に登録したグラフィックをsrc.dst.cの情報をもとに描画。
	Draw::Draw(3, &src, &dst, c, 0.0f);

}