#pragma once
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト、攻撃敵機
class CObjAttackEnemy2 :public CObj
{
public:
	CObjAttackEnemy2(float x, float y);
	~CObjAttackEnemy2() {};
	void Init(); //イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	float m_x; //攻撃方法のx方向の位置。
	float m_y;//攻撃方法のｙ方向の位置。
	float m_vx;//攻撃敵機方向ベクトルx
	float m_vy;//攻撃敵機方向ベクトルy
	int m_hp;
	bool m_del;

	int m_time;//攻撃敵機用弾丸発射タイミング用
};
