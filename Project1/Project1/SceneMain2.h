#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F�Q�[�����C��
class CSceneMain2 :public CScene
{
public:
	CSceneMain2();
	~CSceneMain2();
	void InitScene();//�Q�[�����C���̏��������\�b�h
	void Scene();    //�Q�[�����C���̎��s�����\�b�h
private:
	int m_time;      //�V�[���̃^�C��(��ɓG�o���Ɏg�p)

};
