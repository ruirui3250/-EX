#pragma once
//使用するネームヘッダー
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーンクリア 名前による宣言
class CSceneGameOver4 :public CScene
{
public:
	CSceneGameOver4();
	~CSceneGameOver4();
	void InitScene();//初期化
	void Scene();//実行中
private:
};

