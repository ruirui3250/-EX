#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
//�I�u�W�F�N�g�G�@�e��
class CObjTateBulletEnemy :public CObj
{
public:
	CObjTateBulletEnemy(float x, float y);
	~CObjTateBulletEnemy() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	float m_x;//�I�u�W�F�N�g�̈ʒuX
	float m_y;//�I�u�W�F�N�g�̈ʒuY
	float m_vx;//�I�u�W�F�N�g�̈ړ��p�x�N�g��X
	float m_vy;//�I�u�W�F�N�g�̈ړ��p�x�N�g��Y
	bool m_del;
	int m_ani; //���e�A�j���[�V����
	int m_ani_time;//���e�A�j���[�V�����Ԋu
	RECT_F m_eff;//���e�G�t�F�N�g�`��
};