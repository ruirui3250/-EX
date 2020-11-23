#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//シーン:ゲームオーバー
class  CObjGameOver4 :public CObj
{
public:
	CObjGameOver4() {};
	~CObjGameOver4() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	bool m_key_flag = true;
};

