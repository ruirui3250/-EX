//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include "GameHead.h"
#include"ObjBullet.h"
#include"UtilityModule.h"
#include"GameL/Audio.h"
//#include"GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjBullet::CObjBullet(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjBullet::Init()
{
	m_eff.m_top = 32;
	m_eff.m_left = 0;
	m_eff.m_right = 32;
	m_eff.m_bottom = 64;
	m_ani = 0;
	m_ani_time = 0;
	m_del = false;
	m_vx = 0.0f;

	//当たり判定HItBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_BULLET, 1);
}
//アクション
void CObjBullet::Action()
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
	m_vx += 1.0f;
	m_x += m_vx;

	//弾丸のHitBox更新用ポインター取得
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);//HitBoxの位置を弾丸の位置を更新

		//障害物オブジェクトと接触したら弾丸削除
	//if (hit->CheckObjNameHit(OBJ_YOKO_KESEN) != nullptr)
	//{
	//	this->SetStatus(false);//自身に削除命令をだす。
	//	Hits::DeleteHitBox(this);//弾丸が所有するHitBoxを削除する。
	//}

	//領域外に出たら弾丸破棄
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false); //自身に削除命令を出す。
		Hits::DeleteHitBox(this);//敵機弾丸が所有するHitBoxを削除
		return;
	}

	////障害物に触れたら弾丸削除
	//if (hit->CheckObjNameHit(OBJ_YOKO_KESEN) != nullptr)
	//{
	//	this->SetStatus(false);
	//	Hits::DeleteHitBox(this);
	//}

	//敵機オブジェクトにぶつかったら弾丸削除。
	if (hit->CheckObjNameHit(ELEMENT_ENEMY) != nullptr)
	{
		this->SetStatus(false); //自身に削除命令
		Hits::DeleteHitBox(this);//弾丸が所有するHITBOX削除
		return;
	}

	////敵機オブジェクトにぶつかったら弾丸削除。
	//if (hit->CheckObjNameHit(OBJ_BULLET_ENEMY) != nullptr)
	//{
	//	this->SetStatus(false); //自身に削除命令
	//	Hits::DeleteHitBox(this);//弾丸が所有するHITBOX削除
	//}
	////敵機オブジェクトにぶつかったら弾丸削除。
	//if (hit->CheckObjNameHit(ELEMENT_ENEMY) != nullptr)
	//{
	//	this->SetStatus(false); //自身に削除命令
	//	Hits::DeleteHitBox(this);//弾丸が所有するHITBOX削除
	//}
	//当たり判定を行うオブジェクト情報部
	int data_base[28] =
	{
		//1,2面のやつ
		OBJ_ENEMY,
		OBJ_ATTACK_ENEMY,
		OBJ_HOMING_ENEMY,
		OBJ_SIN_ENEMY,
		OBJ_BULLET_ENEMY,
		//縦スクのやつ
		OBJ_TATE_ENEMY,
		OBJ_TATE_BULLET_ENEMY,
		OBJ_TATE_ATTACK_ENEMY,
		//下スクロール
		OBJ_SITA_BULLET_ENEMY,
		OBJ_SITA_ENEMY,
		OBJ_SITA_ATTACK_ENEMY,
		//血栓
		OBJ_SITA_KESEN,
		OBJ_TATEKESEN,
		OBJ_YOKO_KESEN,
		//ボス
		OBJ_BOSS_ENEMY,
		OBJ_BOSS_ENEMY2,
		OBJ_TATE_BOSS,
		OBJ_BOSS_ENEMY4,
		OBJ_BOSS_BULLET_ENEMY2,
		OBJ_BOSS_BULLET_ENEMY,
		//5面
		OBJ_ENEMY2,
		OBJ_BULLET_ENEMY2,
		OBJ_ATTACK_ENEMY2,
		OBJ_SITA_ATTACK_ENEMY2,
		OBJ_SITA_ENEMY2,
		OBJ_TATE_ATTACK_ENEMY2,
		OBJ_TATE_ENEMY2,
		OBJ_MIX_BOSS,
	};
	//敵機オブジェクトと接触したら拡散弾丸削除
	for (int i = 0; i < 28; i++)
	{
		if (hit->CheckObjNameHit(data_base[i]) != nullptr)
		{
			/*Audio::Start(3);*/
			Audio::Start(18);
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			return;
		}
	}

}
//ドロー
void CObjBullet::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F dst;//描画先表示
	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//2番目に登録したグラフィックを描画。
	Draw::Draw(1, &m_eff, &dst, c, 0.0f);
}