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
	void SetX(float x) { m_px = x; }//�ʒu���X�ύX�p
	void SetY(float y) { m_py = y; }//�ʒu���X�ύX�p
private:
	float m_x;//��l���@��x�����̈ʒu�ϐ�
	float m_y;//��l���@��y�����̈ʒu�ϐ�
	float m_vx;//��l���@��x�����̃x�N�g���p�ϐ�
	float m_vy;//��l���@��y�����̃x�N�g���p�ϐ�
	float m_hp;//��l���̗̑�
	bool m_f;

	float m_px;
	float m_py;
};
