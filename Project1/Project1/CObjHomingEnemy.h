#pragma once
//�g�p����w�b�_�[
#include "GameL/\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G�@
class CObjHomingEnemy :public CObj
{
public:
	CObjHomingEnemy(float x, float y);//�R���X�g���N�^�ʒu�������炤
	~CObjHomingEnemy() {};
	void Init();      //�C�j�V�����C�Y
	void Action();    //�A�N�V����
	void Draw();      //�h���[
private:
	float m_x;  //�G�@�̂������̈ʒu
	float m_y;  //�G�@�̂������̈ʒu
	float m_vx; //�G�@�ړ��x�N�g����
	float m_vy; //�G�@�ړ��x�N�g����
	int   m_time;//�z�[�~���O�e�۔��˃^�C�~���O�p
};