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
    m_vx = 0.0f;
    m_vy = 0.0f;

    //当たり判定用HitBoxを作成
    Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_HOMING_BULLET, 1);
}

//アクション
void CObjHomingEnemy::Action()
{
 //移動方向
    m_vx = -1.0f;
    m_vy = 0.0f;

    //ベクトルの長さを求める。(三平方の定理。)
    float r = 0.0f;
    r = m_vx * m_vx + m_vy * m_vy;
    r = sqrt(r);//rをルートを求める。

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
    src.m_left = 32.0f;
    src.m_right = 64.0f;
    src.m_bottom = 32.0f;

    //表示位置の設定
    dst.m_top = 0.0f + m_y;
    dst.m_left = 32.0f + m_x;
    dst.m_right = 0.0f + m_x;
    dst.m_bottom = 32.0f + m_y;

    //0番目に登録したグラフィックをsrc・dst・cの情報をもとに描画
    Draw::Draw(3, &src, &dst, c, 0.0f);
}