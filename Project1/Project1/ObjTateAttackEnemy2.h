#pragma once
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト、攻撃敵機
class CObjTateAttackEnemy2 :public CObj
{
public:
	CObjTateAttackEnemy2(float x, float y);
	~CObjTateAttackEnemy2() {};
	void Init(); //イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	float m_x; //攻撃方法のx方向の位置。
	float m_y;//攻撃方法のｙ方向の位置。
	float m_vx;//攻撃敵機方向ベクトルx
	float m_vy;//攻撃敵機方向ベクトルy
	bool m_del;      //削除チェック
	int m_hp;
	int m_time;//攻撃敵機用弾丸発射タイミング用
};
