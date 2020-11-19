//使用するヘッダーファイル
#include "GameL/\DrawTexture.h"
#include "GameL/\HitBoxManager.h"

#include "GameHead.h"
#include "CObjHomingEnemy.h"
#include "UtilityModule.h"

//使用するネームスペース
using namespace GameL;


//コンスタラスタ
CObjHomingEnemy::CObjHomingEnemy(float x, float y)
{
    m_x = x;
    m_y = y;
}

//イニシャライズ
void CObjHomingEnemy::Init()
{
	m_eff.m_top = 32;
	m_eff.m_left = 0;
	m_eff.m_right = 32;
	m_eff.m_bottom = 64;
	m_ani = 0;
	m_ani_time = 0;
	m_del = false;

	m_vx = 1.0f;
	m_vy = 0.0f;
	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);
    

    //当たり判定用HitBoxを作成
    Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_HOMING_BULLET, 1);
}

//アクション
void CObjHomingEnemy::Action()
{

	//主人公機と誘導弾丸で角度を取る
	float ar = 170.0f;

	//弾丸と現在の向いている方向を取る。
	float br = 180.0f;

	float r = 3.14 / 180.0f;//角度1

	if (ar < br)
	{
		//移動方向に1加える。
		m_vx = m_vx * cos(r) - m_vy * sin(r);
		m_vy = m_vy * cos(r) + m_vx * sin(r);
	}
	else
	{
		//移動方向に-1加える。
		m_vx = m_vx * cos(-r) - m_vy * sin(-r);
		m_vy = m_vy * cos(-r) + m_vx * sin(-r);
	}
	UnitVec(&m_vx, &m_vy);
	m_x = m_vx * 5.0f;
	m_y = m_vy * 5.0f;

	//誘導弾丸のHitBoxの更新用ポインター獲得
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);//HitBoxの位置を更新

	//誘導弾丸の完全に領域外に出た場合誘導弾丸を破棄
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, -800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);//自信に削除命令出す
		Hits::DeleteHitBox(this);//誘導弾丸オブジェクトHITBOｘ削除
	}
    //長さが0かどうか調べる。
    if (r == 0.0f)
    {
        ;//0なら何もしない。
    }
    else
    {
        //正規化をする
        m_vx = 1.0f / r * m_vx;
        m_vy = 1.0f / r * m_vy;
    }
    //速度を付ける
    m_vx *= 1.5f;
    m_vy *= 1.5f;

    //移動ベクトルを座標に変換する。
    m_x += m_vx;
    m_y += m_vy;

    //HitBoxの内容を更新。
    CHitBox* hit = Hits::GetHitBox(this);
    hit->SetPos(m_x, m_y);

    //ホーミング敵機が完全に領域外でたら破棄する。
    if (m_x < 32.0f)
    {
        this->SetStatus(false);//自信に削除命令
        Hits::DeleteHitBox(this);//ホーミング敵機が所有するHitBox
    }
    //弾丸が接触しているか調べる。
    if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
    {
        this->SetStatus(false);
        Hits::DeleteHitBox(this);
    }
    //機体が接触しているか調べる。
    if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
    {
        this->SetStatus(false);
        Hits::DeleteHitBox(this);
    }
}

//ドロー
void CObjHomingEnemy::Draw()
{
    //描画カラー情報　R=RED　G=GREEN　B=BLUE　A=ALPHA（透過情報）
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };

    RECT_F src;//描画元切り取り位置
    RECT_F dst;//描画先表示位置

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

	float r = 0.0f;

	//主人公機と誘導弾丸で角度を取る
    CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//主人公機が存在する場合、誘導角度の計算する
	if (obj != nullptr)
	{
		float x = obj->GetX() - m_x;
		float y = obj->GetY() - m_y;
		r = GetAtan2Angle(x, -y);


    //0番目に登録したグラフィックをsrc・dst・cの情報をもとに描画
    Draw::Draw(3, &src, &dst, c, 0.0f);
}