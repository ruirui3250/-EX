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
	void SetScroll(float s) { m_scroll = s; }
private:
	int m_map[10][100];//マップ情報
	float m_scroll;//左右スクロール
	float m_x;//敵機のx方向の位置
	float m_y;//敵機のy方向の位置
	float m_vx;//敵移動のベクトルx
	float m_vy;//敵移動のベクトルy
};