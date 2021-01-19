﻿//使用するヘッダーファイル
#include "GameL/\DrawTexture.h"
#include "GameL/\HitBoxManager.h"

#include "GameHead.h"
#include "ObjEnemyBoss2.h"
#include "UtilityModule.h"
#include "GameL/DrawFont.h"

//使用するネームスペース
using namespace GameL;

//コンスタラスタ
CObjBoss2::CObjBoss2(float x, float y)
{
    m_x = x;
    m_y = y;
}

//イニシャライズ
void CObjBoss2::Init()
{
    m_hp = 45;
    m_time = 0;
    m_r = 0.0f;
    m_vx = 0.0f;
    m_vy = 0.0f;

   // 当たり判定用HitBoxを作成
    Hits::SetHitBox(this, m_x, m_y, 352, 352, ELEMENT_ENEMY, OBJ_BOSS_ENEMY2, 50);
}

//アクション
void CObjBoss2::Action()
{
    m_time++;

    //敵機発射
    if (m_time % 50 == 0)
    {
       // 敵機オブジェクト
        CObjAttackEnemy* obj_b = new CObjAttackEnemy(m_x + 68, m_y + 114);//敵機オブジェクト作成
        Objs::InsertObj(obj_b, OBJ_ATTACK_ENEMY, 100);//敵機オブジェクト登録
        CObjAttackEnemy* obj_b2 = new CObjAttackEnemy(m_x + 68, m_y + 250);//敵機オブジェクト作成
        Objs::InsertObj(obj_b2, OBJ_ATTACK_ENEMY, 100);//敵機オブジェクト登録
        CObjAttackEnemy* obj_b3 = new CObjAttackEnemy(m_x + 68, m_y + 10);//敵機オブジェクト作成
        Objs::InsertObj(obj_b3, OBJ_ATTACK_ENEMY, 100);//敵機オブジェクト登録
    }
    ////360度弾丸発射
    //if (m_time % 200 == 0)
    //{
    //        //19発同時発射
    //        //CObjAngleBullet* obj_b;
    //        //for (int i = 0; i < 360; i += 20)
    //        //{
    //        //    //角度iで角度弾丸発射
    //        //    obj_b = new CObjAngleBullet(m_x + 124, m_y + 91, i, 5.0f);
    //        //    Objs::InsertObj(obj_b, OBJ_ANGLE_BULLET, 100);
    //        //}
    //}
        //誘導弾発射
        if (m_time % 200 == 0)
        {
            //誘導弾丸オブジェクト作成
           CObjHomingEnemy* obj_homing_enemy = new CObjHomingEnemy(m_x + 68, m_y + 120);
            Objs::InsertObj(obj_homing_enemy, OBJ_HOMING_ENEMY, 100);
            CObjHomingEnemy* obj_homing_enemy2 = new CObjHomingEnemy(m_x + 68, m_y + 250);
            Objs::InsertObj(obj_homing_enemy2, OBJ_HOMING_ENEMY, 100);
        }
    //m_timeの初期化
    if (m_time > 1000)
    {
        m_time = 0;
    }


    //角度加算
    m_r += 2.0f;

    //360で初期値に戻す
    if (m_r > 360.0f)
        m_r = 0.0f;

    //移動方向
    m_vx = 0.0f;
    m_vy = sin(3.14 / 180 * m_r);

    //移動ベクトルの正規化
    UnitVec(&m_vy, &m_vx);

    ///移動ベクトルを座標に加算する
    m_x += m_vx;
    m_y += m_vy;

    //HitBoxの内容を更新
    CHitBox* hit = Hits::GetHitBox(this);
    hit->SetPos(m_x , m_y);

    //領域外に出たら弾丸を破壊する
    bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
    if (check == false)
    {
        this->SetStatus(false);
        Hits::DeleteHitBox(this);

        return;
    }

   // 弾丸と接触しているかどうか調べる
    if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
    {
        m_hp -= 1;
        return;
    }

    //HPが0になったら破棄
    if (m_hp <= 0)
    {
        this->SetStatus(false);
        Hits::DeleteHitBox(this);

        Scene::SetScene(new CSceneWin3());
        return;

    }
    //弾丸と接触しているかどうか調べる
    if (hit->CheckObjNameHit(OBJ_ANGLE_BULLET_HERO) != nullptr)
    {
        m_hp -= 1;
        return;
    }

    //HPが0になったら破棄
    if (m_hp <= 0)
    {
        this->SetStatus(false);
        Hits::DeleteHitBox(this);

        Scene::SetScene(new CSceneWin3());
        return;
    }
}

//ドロー
void CObjBoss2::Draw()
{
   // 描画カラー情報　R=RED　G=GREEN　B=BLUE　A=ALPHA（透過情報）
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };

    wchar_t str[256];
    swprintf_s(str, L"BossLife=%d", m_hp);
    Font::StrDraw(str, 400, 500, 20, c);
    if (m_hp == 100)
    {
        swprintf_s(str, L"████████████████████", m_hp);
        Font::StrDraw(str, 400, 550, 20, c);
    }
    if (m_hp >= 90)
    {
        swprintf_s(str, L"███████████████████", m_hp);
        Font::StrDraw(str, 400, 550, 20, c);
    }
    if (m_hp >= 80)
    {
        swprintf_s(str, L"███████████████", m_hp);
        Font::StrDraw(str, 400, 550, 20, c);
    }
    if (m_hp >= 70)
    {
        swprintf_s(str, L"█████████████", m_hp);
        Font::StrDraw(str, 400, 550, 20, c);
    }
    if (m_hp >= 60)
    {
        swprintf_s(str, L"███████████", m_hp);
        Font::StrDraw(str, 400, 550, 20, c);
    }
    if (m_hp >= 50)
    {
        swprintf_s(str, L"█████████", m_hp);
        Font::StrDraw(str, 400, 550, 20, c);
    }
    if (m_hp >= 40)
    {
        swprintf_s(str, L"███████", m_hp);
        Font::StrDraw(str, 400, 550, 20, c);
    }
    if (m_hp >= 30)
    {
        swprintf_s(str, L"████", m_hp);
        Font::StrDraw(str, 400, 550, 20, c);
    }
    if (m_hp >= 20)
    {
        swprintf_s(str, L"███", m_hp);
        Font::StrDraw(str, 400, 550, 20, c);
    }
    if (m_hp >= 10)
    {
        swprintf_s(str, L"██", m_hp);
        Font::StrDraw(str, 400, 550, 20, c);
    }
    if (m_hp <= 10)
    {
        swprintf_s(str, L"█", m_hp);
        Font::StrDraw(str, 400, 550, 20, c);
    }

    RECT_F src;//描画元切り取り位置
    RECT_F dst;//描画先表示位置

    //切り取り位置の設定
    src.m_top = 0.0f;
    src.m_left = 0.0f;
    src.m_right = 352.0f;
    src.m_bottom = 352.0f;

    //表示位置の設定
    dst.m_top = 0.0f + m_y;
    dst.m_left = 0.0f + m_x;
    dst.m_right = 352.0f + m_x;
    dst.m_bottom = 352.0f + m_y;

    //1番目に登録したグラフィックをsrc・dst・cの情報をもとに描画
    Draw::Draw(4, &src, &dst, c, 0.0f);
}