#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
//使用するネームスペース
using namespace GameL;
//オブジェクト：主人公
class CObjHero :public CObj
{
public:
	CObjHero() {};
	~CObjHero() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	float GetX() { return m_px; }	   //位置情報X変更用
	float GetY() { return m_py; } 	   //位置情報X変更用
	float GetVY() { return m_vy; }	//blockobject操作用メソッド
	float GetVX() { return m_vx; }

	void SetX(float x) { m_px = x; }//位置情報X変更用
	void SetY(float y) { m_py = y; }//位置情報X変更用
	void SetVY(float vy) { m_vy = vy; }//位置情報更新宣言
	void SetVX(float vx) { m_vx = vx; }//位置情報更新宣言
	
	void SetUp(bool b) { m_hit_up = b; }//衝突状態変更宣言上
	void SetDown(bool b) { m_hit_down = b; }//下
	void SetLeft(bool b) { m_hit_left = b; }//左
	void SetRight(bool b) { m_hit_right = b; }//右
private:
	float m_x;//主人公機のx方向の位置変数
	float m_y;//主人公機のy方向の位置変数
	float m_vx;//主人公機のx方向のベクトル用変数
	float m_vy;//主人公機のy方向のベクトル用変数
	float m_hp;//主人公の体力
	bool m_f;//弾丸発射

	float m_px;//主人公位置取得X座標
	float m_py;//主人公位置取得Y座標
	float m_vv;//データ更新用 当たった場合はこれが機能する

	//blockの衝突状態の確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};
