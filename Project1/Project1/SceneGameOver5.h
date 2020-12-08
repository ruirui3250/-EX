#pragma once
//使用するネームヘッダー
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーンクリア 名前による宣言
class CSceneGameOver5 :public CScene
{
public:
	CSceneGameOver5();
	~CSceneGameOver5();
	void InitScene();//初期化
	void Scene();//実行中
private:
};
