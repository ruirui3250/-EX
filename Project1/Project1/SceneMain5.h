#pragma once
//�g�p����l�[���X�y�[�X
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���@�Q�[�����C��
class CSceneMain5 :public CScene
{
public:
	CSceneMain5();
	~CSceneMain5();
	void InitScene();//�Q�[�����C���̏��������\�b�h
	void Scene();//�Q�[�����C���̎��s�����\�b�h
private:
	int m_time;//�V�[���̃^�C��(��ɓG�@�o���Ɏg�p)
};
