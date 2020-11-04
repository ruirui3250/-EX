#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスぺース
using namespace GameL;

//オブジェクト:ブロック&背景
class CObjBlock :public CObj
{
public:
	CObjBlock() {};
	~CObjBlock() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }
private:
	int m_map[10][100];//マップ情報(仮)

	float m_scroll;//左右スクロール
};