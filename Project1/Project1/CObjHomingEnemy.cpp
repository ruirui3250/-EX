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
    m_time = 0;

    //当たり判定用HitBoxを作成
    Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_HOMING_BULLET, 1);
}

//アクション
void CObjHomingEnemy::Action()
{
    m_time++;
    if (m_time > 100)
    {
        m_time = 0;
        //誘導弾丸オブジェクト作成
        CObjHomingBullet* obj_homing_bullet = new CObjHomingBullet(m_x, m_y);
        Objs::InsertObj(obj_homing_bullet, OBJ_HOMING_BULLET, 100);
    }

    //移動方向
    m_vx = -1.0f;
    m_vy = 0.0f;

    //移動ベクトルの正規化
    UnitVec(&m_vy, &m_vx);

    //速度をつける
    m_vx *= 1.5f;
    m_vy *= 1.5f;

    //移動ベクトルを座標に加算する
    m_x += m_vx;
    m_y += m_vy;

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

    //Sin敵機が完全に領域外に出たら敵機を破棄する
    if (m_x < -32.0f)
    {
        this->SetStatus(false);   //自身に削除命令を出す
        Hits::DeleteHitBox(this); //Sin敵機が所有するHitBoxに削除する。
    }

    //弾丸と接触しているかどうか調べる
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