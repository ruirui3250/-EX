//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"CObjAngleBulletHero.h"
#include "UtilityModule.h"
//#include"GameL\Audio.h"
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
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_BULLET, 1);
}

//アクション

void CObjAngleBulletHero::Action()
{
	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
	//Resourcesの描画物のRECT
	m_eff = GetBulletEffect(&m_ani, &m_ani_time, m_del, 2);
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

	////主人公機弾丸のHitBox更新用ポインター取得
	//CHitBox* hit = Hits::GetHitBox(this);
	//hit->SetPos(m_x, m_y);//HitBoxの位置を敵機弾丸の位置に更新

	//敵機拡散弾丸が完全に領域外から出たら主人公機拡散弾丸を破棄する
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//敵機弾丸が所有するHitBoxに削除する。
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
	//敵機オブジェクトと接触したら拡散弾丸削除
	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
	/*	Audio::Start(3);*/
		//m_del = true;//消滅実行
		//hit->SetInvincibility(true);//敵機弾丸が所有するHitBoxに削除する。
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
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