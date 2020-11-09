#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：拡散敵機
class CObjDiffusionHero :public CObj
{
public:
	CObjDiffusionHero(float x, float y);
	~CObjDiffusionHero() {};

	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	float m_x;//敵機x方向の位置
	float m_y;//敵機y方向の位置
	float m_vx;//敵機移動用ベクトルx
	float m_vy;//敵機移動用ベクトルy
	int m_time;//拡散敵機の角度弾丸を撃つ間隔用変数

};