#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CSceneAttack :public CScene
{
public:
	CSceneAttack();
	~CSceneAttack();
	void InitScene();
	void Scene();
private:
};