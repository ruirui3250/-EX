#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
using namespace GameL;
//object �u���b�N���w�i
class CObjBlock :public CObj
{
public:
	CObjBlock() {};
	~CObjBlock() {};
	void Init();//�C�j�V�����C�Y
	void Action();
	void Draw();
private:
	int m_map[10][100];
};