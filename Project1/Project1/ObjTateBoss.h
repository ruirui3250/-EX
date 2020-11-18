#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;


//オブジェクト：敵機
class CObjTateBoss :public CObj
{
public:
	CObjTateBoss(float x, float y);//コンストラクタ位置情報をもらう
	~CObjTateBoss() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	float m_x;//ボス敵機のｘ方向の位置
	float m_y;//ボス敵機のｙ方向の位置
	float m_vx;//ボス敵機移動ベクトルX
	float m_vy;//ボス敵機移動ベクトルY
	float m_r;//サインカーブ用の角度
	int m_time;//弾丸間隔用
	int m_hp;//ボスのヒットポイント
	float m_w;//移動用サインカーブ用の角度
};