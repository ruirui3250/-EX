#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�N���A
class CObjWin4 :public CObj
{
public:
	CObjWin4() {};
	~CObjWin4() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	bool m_key_flag;//�L�[�t���O
};
