#pragma once
//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�e��
class CObjAngleBullet :public CObj
{
public:
	CObjAngleBullet(float x, float y, float r, float speed);   //�R���X�g���N�^
	~CObjAngleBullet() {};
	void Init();     //�C�j�V�����C�Y
	void Action();   //�A�N�V����
	void Draw();     //�h���[
private:
	float m_x;       //�I�u�W�F�N�g�̈ʒu��
	float m_y;       //�I�u�W�F�N�g�̈ʒu��
	float m_vx;      //�I�u�W�F�N�g�̈ړ��p�x�N�g����
	float m_vy;      //�I�u�W�F�N�g�̈ړ��p�x�N�g����
	float m_r;       //�ړ�����p�x
	float m_speed;   //���x

	int m_ani;       //�A�j���[�V�����p
	int m_ani_time;  //���e�A�j���[�V�����Ԋu
	bool m_del;      //�폜�`�F�b�N
	RECT_F m_eff;    //���e�G�t�F�N�g�`�ʗp

};