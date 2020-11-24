#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;
//オブジェクト敵機弾丸
class CObjEnemyBossBullet2 :public CObj
{
public:
	CObjEnemyBossBullet2(float x, float y, float r, float speed);
	~CObjEnemyBossBullet2() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	float m_x;//オブジェクトの位置X
	float m_y;//オブジェクトの位置Y
	float m_vx;//オブジェクトの移動用ベクトルX
	float m_vy;//オブジェクトの移動用ベクトルY
	float m_r; //移動する角度
	float m_speed;//速度

	int m_ani;
	int m_ani_time;
	bool m_del;
	RECT_F m_eff;
};
