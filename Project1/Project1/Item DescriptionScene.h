#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CSceneItemD :public CScene
{
public:
	CSceneItemD();
	~CSceneItemD();
	void InitScene();
	void Scene();
private:
};

