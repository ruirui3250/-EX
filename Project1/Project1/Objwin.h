#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�N���A
class CObjWin :public CObj
{
public:
	CObjWin() {};
	~CObjWin() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	bool m_key_flag;//�L�[�t���O
	float m_y1;//�w�i�P�̈ʒu���
	float m_y2;//�w�i2�̈ʒu���
	float m_x1;//�w�i�P�̈ʒu���
	float m_x2;//�w�i2�̈ʒu���
	float m_vx;//��]�p������X�x�N�g��
	float m_vy;//��]�p������Y�x�N�g��
	int m_time;
};
