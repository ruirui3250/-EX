#pragma once
#include "GameL\SceneObjManager.h"
#include"GameHead.h"
//使用するネームスペース
using namespace GameL;
//オブジェクト　アイテム
class CObjItem :public CObj
{
public:
	CObjItem() {};
	~CObjItem() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	float m_x;//アイテムのx方向の位置変数
	float m_y;//アイテムのy方向の位置変数
	float m_vx;//アイテムのx方向のベクトル用変数
	float m_vy;//アイテムのy方向のベクトル用変数
	bool m_del;//削除確認用メソッド。


};
