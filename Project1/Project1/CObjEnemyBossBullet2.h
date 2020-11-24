#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
//�I�u�W�F�N�g�G�@�e��
class CObjEnemyBossBullet2 :public CObj
{
public:
	CObjEnemyBossBullet2(float x, float y, float r, float speed);
	~CObjEnemyBossBullet2() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	float m_x;//�I�u�W�F�N�g�̈ʒuX
	float m_y;//�I�u�W�F�N�g�̈ʒuY
	float m_vx;//�I�u�W�F�N�g�̈ړ��p�x�N�g��X
	float m_vy;//�I�u�W�F�N�g�̈ړ��p�x�N�g��Y
	float m_r; //�ړ�����p�x
	float m_speed;//���x

	int m_ani;
	int m_ani_time;
	bool m_del;
	RECT_F m_eff;
};
