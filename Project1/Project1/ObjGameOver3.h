#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//シーン:ゲームオーバー
class  CObjGameOver3 :public CObj
{
public:
	CObjGameOver3() {};
	~CObjGameOver3() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	bool m_key_flag = true;
};
