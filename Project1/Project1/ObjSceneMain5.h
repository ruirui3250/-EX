#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//object�w�i
class CObjSceneMain5 :public CObj
{
public:
	CObjSceneMain5() {};
	~CObjSceneMain5() {};

	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:

	float m_x1;//�w�i�P�̈ʒu���
	float m_x2;//�w�i2�̈ʒu���
	float m_vx;//��]�p������X�x�N�g��
	float m_vy;//��]�p������Y�x�N�g��
	float m_y1;//�w�i1��Y�ʒu���
	float m_y2;//�w�i2��Y�ʒu���
	float m_r;//��]
	float m_speed;//���x�v���X
};
