#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト拡散機
class CObjDiffusionEnemy : public CObj
{
public:
	CObjDiffusionEnemy(float x, float y);//コンストラクタ位置をもらう
	~CObjDiffusionEnemy() {};
	void Init();	//イニシャライズ
	void Action(); //アクション
	void Draw();//ドロー
private:
	float m_x;//敵機のx方向の位置
	float m_y;//敵機のy方向の位置
	float m_vx;//敵移動のベクトルx
	float m_vy;//敵移動のベクトルy
	int	m_time;//拡散敵機の角度弾丸を撃つ間隔用変数
};
