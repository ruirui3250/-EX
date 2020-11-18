#pragma once
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
//オブジェクト敵機弾丸
class CObjEnemyBossBullet4 :public CObj
{
public:
	CObjEnemyBossBullet4(float x, float y);
	~CObjEnemyBossBullet4() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	float m_x;//オブジェクトの位置X
	float m_y;//オブジェクトの位置Y
	float m_vx;//オブジェクトの移動用ベクトルX
	float m_vy;//オブジェクトの移動用ベクトルY

	int m_ani; //着弾アニメーション
	int m_ani_time;//着弾アニメーション間隔
	bool m_del;//削除チェック
	RECT_F m_eff;//着弾エフェクト描画
};
