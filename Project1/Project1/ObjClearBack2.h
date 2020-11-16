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
};
