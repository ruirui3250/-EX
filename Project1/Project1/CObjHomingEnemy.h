#pragma once
//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL/\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵機
class CObjHomingEnemy :public CObj
{
public:
	CObjHomingEnemy(float x, float y);//コンストラクタ位置情報をもらう
	~CObjHomingEnemy() {};
	void Init();      //イニシャライズ
	void Action();    //アクション
	void Draw();      //ドロー
private:
	float m_x;  //敵機のｘ方向の位置
	float m_y;  //敵機のｙ方向の位置
	float m_vx; //敵機移動ベクトルｘ
	float m_vy; //敵機移動ベクトルｙ

	int m_ani;       //アニメーション用
	int m_ani_time;  //着弾アニメーション間隔
	bool m_del;      //削除チェック
	RECT_F m_eff;    //着弾エフェクト描写用
};