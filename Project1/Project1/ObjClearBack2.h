#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//objectクリア画面の敵キャラ
class CObjClearBack2 :public CObj
{
public:
	CObjClearBack2() {};
	~CObjClearBack2() {};

	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	float m_y1;//背景１の位置情報
	float m_y2;//背景2の位置情報
	float m_x1;//背景１の位置情報
	float m_x2;//背景2の位置情報
	float m_vx;//回転用処理のXベクトル
	float m_vy;//回転用処理のYベクトル
	int m_time;
};
