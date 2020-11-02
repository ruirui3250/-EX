#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
//�I�u�W�F�N�g�F��l��
class CObjHero :public CObj
{
public:
	CObjHero() {};
	~CObjHero() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	float GetX() { return m_px; }	   //�ʒu���X�ύX�p
	float GetY() { return m_py; } 	   //�ʒu���X�ύX�p
	float GetVY() { return m_vy; }	//blockobject����p���\�b�h
	float GetVX() { return m_vx; }

	void SetX(float x) { m_px = x; }//�ʒu���X�ύX�p
	void SetY(float y) { m_py = y; }//�ʒu���X�ύX�p
	void SetVY(float vy) { m_vy = vy; }//�ʒu���X�V�錾
	void SetVX(float vx) { m_vx = vx; }//�ʒu���X�V�錾
	
	void SetUp(bool b) { m_hit_up = b; }//�Փˏ�ԕύX�錾��
	void SetDown(bool b) { m_hit_down = b; }//��
	void SetLeft(bool b) { m_hit_left = b; }//��
	void SetRight(bool b) { m_hit_right = b; }//�E
private:
	float m_x;//��l���@��x�����̈ʒu�ϐ�
	float m_y;//��l���@��y�����̈ʒu�ϐ�
	float m_vx;//��l���@��x�����̃x�N�g���p�ϐ�
	float m_vy;//��l���@��y�����̃x�N�g���p�ϐ�
	float m_hp;//��l���̗̑�
	bool m_f;//�e�۔���

	float m_px;//��l���ʒu�擾X���W
	float m_py;//��l���ʒu�擾Y���W
	float m_vv;//�f�[�^�X�V�p ���������ꍇ�͂��ꂪ�@�\����

	//block�̏Փˏ�Ԃ̊m�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};
