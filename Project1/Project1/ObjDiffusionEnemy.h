#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�g�U�@
class CObjDiffusionEnemy : public CObj
{
public:
	CObjDiffusionEnemy(float x, float y);//�R���X�g���N�^�ʒu�����炤
	~CObjDiffusionEnemy() {};
	void Init();	//�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();//�h���[
private:
	float m_x;//�G�@��x�����̈ʒu
	float m_y;//�G�@��y�����̈ʒu
	float m_vx;//�G�ړ��̃x�N�g��x
	float m_vy;//�G�ړ��̃x�N�g��y
	int	m_time;//�g�U�G�@�̊p�x�e�ۂ����Ԋu�p�ϐ�
};
