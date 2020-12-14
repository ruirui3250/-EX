//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjBoss.h"
#include "UtilityModule.h"

//使用するネームスペース
using namespace GameL;
//コンストラクタ
ObjBoss::ObjBoss(float x, float y)
{
	m_x = x;
	m_y = y;
}
//イニシャライズ
void ObjBoss::Init()
{
	m_hp = 30;
	m_time = 0;
	m_r = 0.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x + 100, m_y + 50, 250, 200, ELEMENT_ENEMY, OBJ_BOSS, 1);

}

//アクション
void ObjBoss::Action()
{
	m_time++;
	//通常弾発射
	if (m_time % 50 == 0)
	{
		//弾丸発射オブジェクト
		CObjBulletEnemy* obj_b = new CObjBulletEnemy(m_x + 12, m_y + 22);
		Objs::InsertObj(obj_b, OBJ_BULLET_ENEMY, 100);
	}

	////360°弾発射
	//if (m_time % 200 == 0)
	//{
	//	//19発同時発射
	//	CObjAngleBullet* obj_b;
	//	for (int i = 0; i < 360; i += 20)
	//	{
	//		obj_b = new CObjAngleBullet(m_x + 31, m_y + 42, i, 5.0f);
	//		Objs::InsertObj(obj_b, OBJ_ANGLE_BULLET, 1);
	//	}
	//}
	////誘導弾発射
	//if (m_time % 500 == 0)
	//{
	//	//誘導弾作成
	//	CObjHomingBullet* obj_homing_bullet = new CObjHomingBullet(m_x + 53, m_y + 62);
	//	Objs::InsertObj(obj_homing_bullet, OBJ_HOMING_BULLET, 1);
	//}

	//m_timeの初期化
	if (m_time % 1000 == 0)
	{
		m_time = 0;
	}

	//角度加算
	m_r += 2.0f;
	//360°で初期値に戻す
	if (m_r > 360.0f)
		m_r = 0.0f;
	//移動方向
	m_vx = 0.0f;
	m_vy = sin(3.14 / 180 * m_r);//sinθを求めてm_vyに入れる

	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//速度をつける。
	m_vx *= 1.5f;
	m_vy *= 1.5f;
	//移動用ベクトルを座標に加算する
	m_x += m_vx;
	m_y += m_vy;


	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x + 100, m_y + 50);
	////敵機拡散弾丸が完全に領域外から出たら敵機拡散弾丸を破棄する
	//bool check = CheakWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	//if (check == false)
	//{
	//	this->SetStatus(false);//自身に削除命令を出す
	//	Hits::DeleteHitBox(this);//敵機弾丸が所有するHitBoxに削除する。
	//}

	//弾丸と接触したらHPを減らす
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
	}

	//HPが０になったら破棄
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		Scene::SetScene(new CSceneTitle());

	}

}


//ドロー
void ObjBoss::Draw()
{
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f, };
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;
	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 250.0f + m_x;
	dst.m_bottom = 128.0f + m_y;
	//1番目に登録したグラフィックをsrc・dst・ｃの情報を元に描画
	Draw::Draw(9, &src, &dst, c, 0.0f);
}