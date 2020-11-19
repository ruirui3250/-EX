#pragma once
//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
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

	int m_ani;       //�A�j���[�V�����p
	int m_ani_time;  //���e�A�j���[�V�����Ԋu
	bool m_del;      //�폜�`�F�b�N
	RECT_F m_eff;    //���e�G�t�F�N�g�`�ʗp
};