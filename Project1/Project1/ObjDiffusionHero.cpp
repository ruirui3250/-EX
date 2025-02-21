//使用ヘッダー
#include "GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include "ObjDiffusionHero.h"
#include"UtilityModule.h"

//使用するネームスペース
using namespace GameL;
//コンストラクタ
CObjDiffusionHero::CObjDiffusionHero(float x, float y)
{
	m_x = x;
	m_y = y;
}
//イニシャライズ
void CObjDiffusionHero::Init()
{
	m_time = 0;
	m_vx = 0.0f;
	m_vy = 0.0f;


	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_DIFFUSION_HERO, 1);
}
//アクション
void CObjDiffusionHero::Action()
{
	//20°間隔で弾丸発射
	m_time++;
	if (m_time > 50)
	{
		m_time = 0;

		//19発同時発射
		CObjAngleBulletHero* obj_b;
		for (int i = 0; i < 360; i += 20)
		{
			//角度iで角度弾丸発射
			obj_b = new CObjAngleBulletHero(m_x, m_y, i, 5.0f);
			Objs::InsertObj(obj_b, OBJ_ANGLE_BULLET_HERO, 100);
		}
	}
	//移動方向
	m_vx = -1.0f;
	m_vy = 0.0f;

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
	//敵機オブジェクトにぶつかったら弾丸削除。
	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
		this->SetStatus(false); //自身に削除命令
		Hits::DeleteHitBox(this);//弾丸が所有するHITBOX削除
		return;
	}

	//当たり判定を行うオブジェクト情報部
	int data_base[8] =
	{
		OBJ_ENEMY,
		OBJ_ENEMY2,
		OBJ_ATTACK_ENEMY,
		OBJ_BULLET_ENEMY2,
		//OBJ_DIFFUSION_ENEMY,
		OBJ_HOMING_ENEMY,
		OBJ_BOSS_ENEMY,
		OBJ_BOSS_ENEMY2,
		OBJ_ATTACK_ENEMY2,
	};

	//オブジェクト情報部に当たり判定を行い。当たれば削除。
	for (int i = 0; i < 8; i++)
	{
		if (hit->CheckObjNameHit(data_base[i]) != nullptr)
		{
			/*Audio::Start(3);*/
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			return;
		}
	}
}

//ドロー
void CObjDiffusionHero::Draw()
{
	//描画カラー情報　R-RED G=GREEN B=BLUE A=ALPHA(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画切り取り位置
	RECT_F dst;//描画先表示

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 32.0f;
	src.m_right = 64.0f;
	src.m_bottom = 32.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 32.0f + m_x;
	dst.m_right = 0.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//0番目に登録したグラフィックをsrc.dst.cの情報をもとに描画。
	Draw::Draw(6, &src, &dst, c, 0.0f);

}