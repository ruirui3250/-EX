#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�g�U�G�@
class CObjDiffusionHero :public CObj
{
public:
	CObjDiffusionHero(float x, float y);
	~CObjDiffusionHero() {};

	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	float m_x;//�G�@x�����̈ʒu
	float m_y;//�G�@y�����̈ʒu
	float m_vx;//�G�@�ړ��p�x�N�g��x
	float m_vy;//�G�@�ړ��p�x�N�g��y
	int m_time;//�g�U�G�@�̊p�x�e�ۂ����Ԋu�p�ϐ�

};