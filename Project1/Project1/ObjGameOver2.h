#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//シーン:ゲームオーバー
class  CObjGameOver2:public CObj
{
public:
	CObjGameOver2() {};
	~CObjGameOver2() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	bool m_key_flag = true;
};
