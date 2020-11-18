#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//object背景
class CObjSceneMain2 :public CObj
{
public:
	CObjSceneMain2() {};
	~CObjSceneMain2() {};

	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:

	float m_x1;//背景１の位置情報
	float m_x2;//背景2の位置情報
	float m_vx;//回転用処理のXベクトル
	float m_vy;//回転用処理のYベクトル
	float m_y1;//背景1のY位置情報
	float m_y2;//背景2のY位置情報
	float m_r;//回転
	float m_speed;//速度プラス
};
