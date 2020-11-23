#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト敵機
class CObjTateEnemy2 : public CObj
{
public:
	CObjTateEnemy2(float x, float y);//コンストラクタ位置をもらう
	~CObjTateEnemy2() {};
	void Init();	//イニシャライズ
	void Action(); //アクション
	void Draw();//ドロー
private:
	float m_x;//敵機のx方向の位置
	float m_y;//敵機のy方向の位置
	float m_vx;//敵移動のベクトルx
	float m_vy;//敵移動のベクトルy
	float m_r;
	bool m_del;      //削除チェック
	int m_hp;
};

