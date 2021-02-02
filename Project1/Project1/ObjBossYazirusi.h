#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト敵機
class ObjBossYazirusi : public CObj
{
public:
	ObjBossYazirusi(float x, float y);//コンストラクタ位置をもらう
	~ObjBossYazirusi() {};
	void Init();	//イニシャライズ
	void Action(); //アクション
	void Draw();//ドロー
private:
	float m_x;//敵機のx方向の位置
	float m_y;//敵機のy方向の位置
	float m_vx;//敵移動のベクトルx
	float m_vy;//敵移動のベクトルy
	float m_r;
	int	  m_time;
	int   second;

};