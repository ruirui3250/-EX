//使用するヘッダーファイル
#include "GameL/\DrawTexture.h"
#include "GameL/\HitBoxManager.h"

#include"GameL\SceneObjManager.h"
#include "GameHead.h"
#include "CObjEnemyBossBullet4.h"
#include "UtilityModule.h"

//使用するネームスペース
using namespace GameL;

//コンスタラスタ
CObjEnemyBossBullet4::CObjEnemyBossBullet4(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjEnemyBossBullet4::Init()
{
	m_eff.m_top = 0;
	m_eff.m_left = 0;
	m_eff.m_right = 10;
	m_eff.m_bottom = 10;
	m_ani = 0;
	m_ani_time = 0;
	m_del = false;

	m_vx = 0.0f;
	m_vy = 1.0f;
	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 10, 10, ELEMENT_ENEMY, OBJ_BOSS_BULLET_ENEMY, 50);
}

//アクション
void CObjEnemyBossBullet4::Action()
{
	//Resourcesの描写物のRECT
	m_eff = GetBulletEffect(&m_ani, &m_ani_time, m_del, 2);

	//弾丸消滅処理
	if (m_del == true)
	{


		//着弾アニメーション終了で本当にオブジェクト破棄
		if (m_ani == 4)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}

		return;//消滅処理は、ここでアクションメソッドを終了させる
	}

	//主人公機と誘導弾丸で角度を取る
	CObjSitaHero* obj = (CObjSitaHero*)Objs::GetObj(OBJ_SITA_HERO);

	//主人公機が存在する場合、誘導角度の計算する
	if (obj != nullptr)
	{
		float x = obj->GetX() + m_x;
		float y = obj->GetY() + m_y;
		float ar = GetAtan2Angle(-x, +y);


		//弾丸の現在の向いている角度を取る
		float br = GetAtan2Angle(-m_vx, +m_vy);

		//主人公機と敵機角度があまりにもかけ離れたら
		if (ar - br > 20)
		{
			//移動方向を主人公機の方向にする
			m_vx = -cos(3.14 / 180 * ar);
			m_vy = +sin(3.14 / 180 * ar);
		}

		float r = 3.14 / 180.0f;   //角度1°
		if (ar < br)
		{
			//移動方向に+1°加える
			m_vx = m_vx * cos(r) + m_vy * sin(r);
			m_vy = m_vy * cos(r) - m_vx * sin(r);
		}
		else
		{
			//移動方向に-1°加える
			m_vx = m_vx * cos(-r) + m_vy* sin(-r);
			m_vy = m_vy * cos(-r) - m_vx * sin(-r);
		}

		UnitVec(&m_vx, &m_vy);
	}

	//移動
	m_x -= m_vx * 5.0f;
	m_y -= m_vy * 5.0f;

	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//領域外に出たら弾丸を破壊する
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		return;
	}
	//主人公機objectと接触したら敵機弾丸削除。
	if (hit->CheckObjNameHit(OBJ_SITA_HERO) != nullptr)
	{
		m_del = true; //消滅実行
		hit->SetInvincibility(true);//当たり判定無効
	}
	//弾丸の接触を調べる。
	if (hit->CheckObjNameHit(OBJ_SITA_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//弾丸の接触を調べる。
	if (hit->CheckObjNameHit(OBJ_ANGLE_BULLET_HERO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//ドロー
void CObjEnemyBossBullet4::Draw()
{
	//描画カラー情報　R=RED　G=GREEN　B=BLUE　A=ALPHA（透過情報）
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F dst;//描画先表示位置


	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 10.0f + m_x;
	dst.m_bottom = 10.0f + m_y;

	float r = 0.0f;
	//主人公機と誘導弾丸で角度を取る
	CObjSitaHero* obj = (CObjSitaHero*)Objs::GetObj(OBJ_SITA_HERO);

	//主人公機が存在する場合、誘導角度の計算する
	if (obj != nullptr)
	{
		float x = obj->GetX() + m_x;
		float y = obj->GetY() + m_y;
		r = GetAtan2Angle(-x, +y);


		///0番目に登録したグラフィックをsrc・dst・cの情報をもとに描画
		Draw::Draw(4, &m_eff, &dst, c, r);
	}
}