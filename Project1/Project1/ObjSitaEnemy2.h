#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト敵機
class CObjSitaEnemy2 : public CObj
{
public:
	CObjSitaEnemy2(float x, float y);//コンストラクタ位置をもらう
	~CObjSitaEnemy2() {};
	void Init();	//イニシャライズ
	void Action(); //アクション
	void Draw();//ドロー
private:
	float m_x;//敵機のx方向の位置
	float m_y;//敵機のy方向の位置
	float m_vx;//敵移動のベクトルx
	float m_vy;//敵移動のベクトルy
	float m_r;
	int m_hp;
};

