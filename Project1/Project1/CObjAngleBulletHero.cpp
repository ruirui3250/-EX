//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"CObjAngleBulletHero.h"
#include"ObjDiffusionHero.h"
#include "UtilityModule.h"
#include"GameL/Audio.h"
//使用するネームスペース
using namespace GameL;

CObjAngleBulletHero::CObjAngleBulletHero(float x, float y, float r, float speed)
{
	m_x = x;
	m_y = y;
	m_r = r;
	m_speed = speed;
}
//イニシャライズ
void CObjAngleBulletHero::Init()
{
	m_eff.m_top = 32;
	m_eff.m_left = 0;
	m_eff.m_right = 32;
	m_eff.m_bottom = 64;
	m_ani = 0;
	m_ani_time = 0;
	m_del = false;

	m_vx = cos(3.14f / 180.0f * m_r);
	m_vy = sin(3.14f / 180.0f * m_r);
	//移動用ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_ANGLE_BULLET_HERO, 1);
}

//アクション

void CObjAngleBulletHero::Action()
{
	
	//弾丸消滅装置--------
	if (m_del == true)
	{
		//着弾アニメーション終了で本当にオブジェクトの破棄
		if (m_del == 4)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
		return;//消滅処理は、ここでアクションメソッドを終了させる
	}
	//弾丸実行処理-----
	//移動
	m_x += m_vx * m_speed;
	m_y -= m_vy * m_speed;

	//主人公機弾丸のHitBox更新用ポインター取得
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);//HitBoxの位置を敵機弾丸の位置に更新
	{


		//領域外に出たら弾丸破棄
		bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
		if (check == false)
		{
			this->SetStatus(false);//自身に削除命令を出す
			Hits::DeleteHitBox(this);//敵機弾丸が所有するHitBoxに削除する。
			return;
		}

		//敵機オブジェクトにぶつかったら弾丸削除。
		if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
		{
			this->SetStatus(false); //自身に削除命令
			Hits::DeleteHitBox(this);//弾丸が所有するHITBOX削除
			return;
		}
		//敵機オブジェクトにぶつかったら弾丸削除。
		if (hit->CheckObjNameHit(OBJ_BULLET_ENEMY) != nullptr)
		{
			this->SetStatus(false); //自身に削除命令
			Hits::DeleteHitBox(this);//弾丸が所有するHITBOX削除
			return;
		}
		//敵機オブジェクトにぶつかったら弾丸削除。
		if (hit->CheckObjNameHit(ELEMENT_ENEMY) != nullptr)
		{
			this->SetStatus(false); //自身に削除命令
			Hits::DeleteHitBox(this);//弾丸が所有するHITBOX削除
			return;
		}
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

		if (m_del == true)
		{

			//アニメーションRECT情報
			RECT_F ani_src[4] =
			{
				{32,0,32,64},
				{32,32,64,64},
				{32,64,96,64},
				{32,96,128,64},
			};
			//アニメーションのコマ感覚制御
			if (m_ani_time > 2)
			{
				m_ani++;
				m_ani_time = 0;

				m_eff = ani_src[m_ani];//アニメーションのRECT配列からm_ani番目のRECT情報取得
			}
			else
			{
				m_ani_time++;
			}
			//着弾アニメーション終了で本当にオブジェクトの破棄
			if (m_ani == 4)
			{
				this->SetStatus(false);
				Hits::DeleteHitBox(this);
			}
			return;//消滅処理は、ここでアクションメソッドを終了させる
		}




	}
}
//ドロー
	void CObjAngleBulletHero::Draw()
{
	//描画カラー情報　R=RED G=GREEN B=BLUE A=ALPHA(透過情報）
	float c[4] = { 1.0f,1.0f ,1.0f ,1.0f };
	RECT_F dst;//描画先表示
		//切り取り位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;
	//6番目に登録したグラフィックをsrc・ｄｓｔ・ｃの情報をもとに描画
	Draw::Draw(6, &m_eff, &dst, c, m_r);

}




