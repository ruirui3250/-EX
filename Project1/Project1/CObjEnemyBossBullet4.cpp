//使用ヘッダー
#include "GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include "CObjEnemyBossBullet4.h"
#include"UtilityModule.h"

//使用するネームスペース
using namespace GameL;
//コンストラクタ
CObjEnemyBossBullet4::CObjEnemyBossBullet4(float x, float y)
{
	m_x = x;
	m_y = y;
}
//イニシャライズ
void CObjEnemyBossBullet4::Init()
{
	m_time = 0;
	m_vx = 0.0f;
	m_vy = 0.0f;


	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_x, m_y, 10, 10, ELEMENT_ENEMY, OBJ_BOSS_BULLET_ENEMY, 4);
}
//アクション
void CObjEnemyBossBullet4::Action()
{
	//20°間隔で弾丸発射
	m_time++;
	if (m_time > 50)
	{
		m_time = 0;

		//19発同時発射
		CObjEnemyBossBullet2* obj_b;
		for (int i = 0; i < 360; i += 20)
		{
			//角度iで角度弾丸発射
			obj_b = new CObjEnemyBossBullet2(m_x, m_y, i, 5.0f);
			Objs::InsertObj(obj_b, OBJ_BOSS_BULLET_ENEMY2, 100);
		}
	}
	//移動方向
	m_vx = 0.0f;
	m_vy = -1.0f;

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
	//敵機が完全に領域にでたら破棄。
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);//自身に削除命令
		Hits::DeleteHitBox(this);//敵機を所有する。
		return;

	}
	//弾丸の接触を調べる。
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
	//弾丸の接触を調べる。
	if (hit->CheckObjNameHit(OBJ_SITA_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
	//弾丸の接触を調べる。
	if (hit->CheckObjNameHit(OBJ_ANGLE_BULLET_HERO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
	//弾丸の接触を調べる。
	if (hit->CheckObjNameHit(OBJ_SITA_LASER_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
}

//ドロー
void CObjEnemyBossBullet4::Draw()
{
	//描画カラー情報　R-RED G=GREEN B=BLUE A=ALPHA(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

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