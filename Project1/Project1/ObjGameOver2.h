#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[��:�Q�[���I�[�o�[
class  CObjGameOver2:public CObj
{
public:
	CObjGameOver2() {};
	~CObjGameOver2() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	bool m_key_flag = true;
};
