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
private:
	int m_map[10][10];//マップ情報(仮)
};