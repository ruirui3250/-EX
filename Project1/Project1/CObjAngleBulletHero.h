#pragma once
//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：弾丸
class CObjAngleBulletHero :public CObj
{
public:
	CObjAngleBulletHero(float x, float y, float r, float speed);//コンストラクタ
	~CObjAngleBulletHero() {};
	void Init(); //イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	float m_x;//オブジェクトの位置X
	float m_y;//オブジェクトの位置Y
	float m_vx;//オブジェクトの移動用ベクトルX
	float m_vy;//オブジェクトの移動用ベクトルX
	float m_r; //移動する角度
	float m_speed;//速度用

	int m_ani;
	int m_ani_time;
	bool m_del;
	RECT_F m_eff;

};