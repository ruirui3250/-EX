#pragma once
#include "GameL\SceneObjManager.h"
#include"GameHead.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
//�I�u�W�F�N�g�@�A�C�e��
class CObjItem :public CObj
{
public:
	CObjItem() {};
	~CObjItem() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	float m_x;//�A�C�e����x�����̈ʒu�ϐ�
	float m_y;//�A�C�e����y�����̈ʒu�ϐ�
	float m_vx;//�A�C�e����x�����̃x�N�g���p�ϐ�
	float m_vy;//�A�C�e����y�����̃x�N�g���p�ϐ�
	bool m_del;//�폜�m�F�p���\�b�h�B


};
