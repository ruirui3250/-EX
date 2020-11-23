#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
//オブジェクト：主人公
class CObjSitaHero :public CObj
{
public:
	CObjSitaHero() {};
	~CObjSitaHero() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
	float GetX();	   //位置情報X変更用
	float GetY();	   //位置情報X変更用
	void SetX(float x) { m_px = x; }//位置情報X変更用
	void SetY(float y) { m_py = y; }//位置情報X変更用
	void SetVY(float vy) { m_vy = vy; }//位置情報更新宣言
private:
	float m_x;//主人公機のx方向の位置変数
	float m_y;//主人公機のy方向の位置変数
	float m_vx;//主人公機のx方向のベクトル用変数
	float m_vy;//主人公機のy方向のベクトル用変数
	int		m_hp;//最初からある分
	int     m_ka;
	int     m_la;

	int		m_nhp;//残り分
	int     m_nka;
	int     m_nla;

	float m_px;//主人公位置取得X座標
	float m_py;//主人公位置取得Y座標
	float m_vv;//データ更新用 当たった場合はこれが機能する

	bool m_f = true;
	bool m_key_flag = true;
};
