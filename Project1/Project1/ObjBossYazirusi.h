#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�G�@
class ObjBossYazirusi : public CObj
{
public:
	ObjBossYazirusi(float x, float y);//�R���X�g���N�^�ʒu�����炤
	~ObjBossYazirusi() {};
	void Init();	//�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();//�h���[
private:
	float m_x;//�G�@��x�����̈ʒu
	float m_y;//�G�@��y�����̈ʒu
	float m_vx;//�G�ړ��̃x�N�g��x
	float m_vy;//�G�ړ��̃x�N�g��y
	float m_r;
	int	  m_time;
	int   second;

};