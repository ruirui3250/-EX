//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "CObjSitaBulletEnemy.h"
#include"UtilityModule.h"
#include"GameL/Audio.h"

//使用するネーム
using namespace GameL;

CObjSitaBulletEnemy::CObjSitaBulletEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjSitaBulletEnemy::Init()
{
	m_eff.m_top = 32;
	m_eff.m_left = 0;
	m_eff.m_right =32;
	m_eff.m_bottom = 64;
	m_ani = 0;
	m_ani_time = 0;
	m_vx = 0.0f;
	m_vy = +1.0f;

	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//当たり判定用HitBoxを作成。
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_SITA_BULLET_ENEMY, 50);

}

//アクション
void CObjSitaBulletEnemy::Action()
{
	//Resourcesの描画物RECT
	m_eff = GetBulletEffect(&m_ani, &m_ani_time, m_del, 2);

	//弾丸消滅処理
	if (m_del == true)
	{
		//着弾アニメーション終了で本当にオブジェクトの破棄。
		if (m_ani == 4)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
		return; //消滅処理は、ここでアクションメソッドを終了される。
	}
	//弾丸実行処理
	//移動
	m_x -= m_vx * 4.0f;
	m_y -= m_vy * 4.0f;

	//敵機弾丸の交信用ポインターを獲得。
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);	//HitBoxの位置を敵機弾丸の位置を更新。
	//領域外に出たら弾丸を破棄。
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false); //自身に削除命令を出す。
		Hits::DeleteHitBox(this);//敵機弾丸が所有するHitBoxを削除
		return;
	}
	if (hit->CheckObjNameHit(OBJ_SITA_HERO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
	//	//弾丸と接触しているかどうか調べる。
	if (hit->CheckObjNameHit(OBJ_SITA_BULLET) != nullptr)
	{
		Audio::Start(18);
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
	//弾丸の接触を調べる。
	if (hit->CheckObjNameHit(OBJ_ANGLE_BULLET_HERO) != nullptr)
	{
		Audio::Start(18);
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
	//弾丸の接触を調べる。
	if (hit->CheckObjNameHit(OBJ_SITA_LASER_BULLET) != nullptr)
	{
		Audio::Start(18);
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
	////主人公機objectと接触したら敵機弾丸削除。
	/*if (hit->CheckObjNameHit(OBJ_SITA_HERO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}*/
	//弾丸の接触を調べる。
	if (hit->CheckObjNameHit(OBJ_SITA_HERO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
}

//ドロー
void CObjSitaBulletEnemy::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F dst;//描画先表示

	//切り取り位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//0番目に登録したグラフィックを描画。
	Draw::Draw(2, &m_eff, &dst, c, 180.0f);
}