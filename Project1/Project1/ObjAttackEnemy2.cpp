//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"ObjAttackEnemy2.h"
#include"UtilityModule.h"

//使用するネームスペース。
using namespace GameL;
//コンストラクタ
CObjAttackEnemy2::CObjAttackEnemy2(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjAttackEnemy2::Init()
{
	m_hp = 10;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 0;

	//当たり判定用HitBoxを作成.
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_ATTACK_ENEMY2, 1);

}
//アクション
void CObjAttackEnemy2::Action()
{
	m_time++;//1加算

	if (m_time > 50)
	{
		m_time = 0;
		//弾丸敵機object
		CObjBulletEnemy2* obj_b = new CObjBulletEnemy2(m_x, m_y);//弾丸発射オブジェクト作成
		Objs::InsertObj(obj_b, OBJ_BULLET_ENEMY2, 100);//弾丸敵機object登録
	}
	//移動方向
	m_vx = -1.0f;
	m_vy = 0.0f;

	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//速度を付ける。
	m_vx *= 1.5f;
	m_vy *= 1.5f;

	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//移動ベクトルを座標に加算する。
	m_x += m_vx;
	m_y += m_vy;

	//HitBoxの内容を更新。
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//敵機が完全に領域にでたら破棄。
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);//自身に削除命令
		Hits::DeleteHitBox(this);//敵機を所有するHITBOX削除
		return;

	}
	//主人公機objectと接触したら敵機弾丸削除。
	if (hit->CheckObjNameHit(OBJ_HERO5) != nullptr)
	{
		m_del = true; //消滅実行
		hit->SetInvincibility(true);//当たり判定無効
	}
	//弾丸と接触しているかどうか調べる
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
void CObjAttackEnemy2::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,0.5f,0.5f,1.0f };

	RECT_F src;//描画切り取り位置
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

	//0番目に登録したグラフィックを描画
	Draw::Draw(3, &src, &dst, c, 0.0f);
}