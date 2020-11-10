#pragma once
//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：弾丸
class CObjAngleBullet :public CObj
{
public:
	CObjAngleBullet(float x, float y, float r, float speed);   //コンストラクタ
	~CObjAngleBullet() {};
	void Init();     //イニシャライズ
	void Action();   //アクション
	void Draw();     //ドロー
private:
	float m_x;       //オブジェクトの位置ｘ
	float m_y;       //オブジェクトの位置ｙ
	float m_vx;      //オブジェクトの移動用ベクトルｘ
	float m_vy;      //オブジェクトの移動用ベクトルｙ
	float m_r;       //移動する角度
	float m_speed;   //速度

	int m_ani;       //アニメーション用
	int m_ani_time;  //着弾アニメーション間隔
	bool m_del;      //削除チェック
	RECT_F m_eff;    //着弾エフェクト描写用

};