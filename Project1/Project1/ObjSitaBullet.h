#pragma once
//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：弾丸
class CObjSitaBullet :public CObj
{
public:
	CObjSitaBullet(float x, float y);   //コンストラクタ
	~CObjSitaBullet() {};
	void Init();     //イニシャライズ
	void Action();   //アクション
	void Draw();     //ドロー
private:
	float m_x;       //弾丸のX方向の位置用変数
	float m_y;       //弾丸のY方向の位置用変数
	float m_vy;      //弾丸のY方向の速度用変数
private:
	bool m_key_flag;//キーフラグ
	int m_ani;       //アニメーション用
	int m_ani_time;  //着弾アニメーション間隔
	bool m_del;      //削除チェック
	RECT_F m_eff;    //着弾エフェクト描写用
};
