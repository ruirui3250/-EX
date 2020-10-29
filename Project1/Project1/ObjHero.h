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
	void SetX(float x) { m_px = x; }//位置情報X変更用
	void SetY(float y) { m_py = y; }//位置情報X変更用
private:
	float m_x;//主人公機のx方向の位置変数
	float m_y;//主人公機のy方向の位置変数
	float m_vx;//主人公機のx方向のベクトル用変数
	float m_vy;//主人公機のy方向のベクトル用変数
	float m_hp;//主人公の体力
	bool m_f;

	float m_px;
	float m_py;
};
