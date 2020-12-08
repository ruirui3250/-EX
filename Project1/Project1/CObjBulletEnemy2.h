#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;
//オブジェクト敵機弾丸
class CObjBulletEnemy2 :public CObj
{
public:
	CObjBulletEnemy2(float x, float y);
	~CObjBulletEnemy2() {};
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
	int   m_hp; //ヒットポイント
};
