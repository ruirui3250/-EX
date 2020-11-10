#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
using namespace GameL;
//object ブロック＆背景
class CObjBlock :public CObj
{
public:
	CObjBlock() {};
	~CObjBlock() {};
	void Init();//イニシャライズ
	void Action();
	void Draw();
private:
	int m_map[10][100];
};