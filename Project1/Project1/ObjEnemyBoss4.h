#pragma once
//使用するヘッダー
#include "GameL/\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵機
class CObjEnemyBoss4 :public CObj
{
public:
	CObjEnemyBoss4(float x, float y);//コンストラクタ位置情報をもらう
	~CObjEnemyBoss4() {};
	void Init();      //イニシャライズ
	void Action();    //アクション
	void Draw();      //ドロー
private:
	float m_x;  //敵機のｘ方向の位置
	float m_y; //敵機のｙ方向の位置
	float m_vx; //敵機移動ベクトルｘ
	float m_vy; //敵機移動ベクトルｙ
	float m_r;  //サインカーブ用角度
	int   m_time;//弾丸間隔用
	int   m_hp; //ボスのヒットポイント
};
