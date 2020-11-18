//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL/\HitBoxManager.h"
#include "GameHead.h"
#include "ObjBullet.h"
#include "UtilityModule.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjAngleBullet::CObjAngleBullet(float x, float y, float r, float speed)
{
    m_x = x;
    m_y = y;
    m_r = r;
    m_speed = speed;
}

//イニシャライズ
void CObjAngleBullet::Init()
{
    m_eff.m_top = 32;
    m_eff.m_left = 0;
    m_eff.m_right = 32;
    m_eff.m_bottom = 64;
    m_ani = 0;
    m_ani_time = 0;
    m_del = false;

    m_vx = cos(3.14 / 180.0f * m_r);
    m_vy = sin(3.14 / 180.0f * m_r);
    //移動ベクトルの正規化
    UnitVec(&m_vy, &m_vx);
    //当たり判定用HitBoxを作成
    Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_HERO, 1);
}

//アクション
void CObjAngleBullet::Action()
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

    //移動
    m_x += m_vx * m_speed;
    m_y -= m_vy * m_speed;

    //弾丸のHitBox更新用ポインター取得
    CHitBox* hit = Hits::GetHitBox(this);
    hit->SetPos(m_x, m_y);           //HItBoxの位置を弾丸の位置に更新

    //領域外に出たら弾丸を破壊する
    bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
    if (check == false)
    {
        this->SetStatus(false);
        Hits::DeleteHitBox(this);
    }

    //主人公機オブジェクトと接触したら敵機拡散弾丸削除
    if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
    {
        m_del = true;                 //消滅実行
        hit->SetInvincibility(true);//当たり判定無効
    }

    //弾丸と接触しているかどうか調べる
    if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
    {
        this->SetStatus(false);    //自身に削除命令を出す
        Hits::DeleteHitBox(this);  //弾丸が所有するHitBoxを削除する
    }
}

//ドロー
void CObjAngleBullet::Draw()
{
    //描画カラー情報　R=RED　G=GREEN　B=BLUE　A=ALPHA（透過情報）
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };

    RECT_F dst;//描画先表示位置



    //表示位置の設定
    dst.m_top = 0.0f + m_y;
    dst.m_left = 0.0f + m_x;
    dst.m_right = 32.0f + m_x;
    dst.m_bottom = 32.0f + m_y;

    //0番目に登録したグラフィックをsrc・dst・cの情報をもとに描画
    Draw::Draw(5, &m_eff, &dst, c, m_r);
}