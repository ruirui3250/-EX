#pragma once
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�A�U���G�@
class CObjTateAttackEnemy2 :public CObj
{
public:
	CObjTateAttackEnemy2(float x, float y);
	~CObjTateAttackEnemy2() {};
	void Init(); //�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	float m_x; //�U�����@��x�����̈ʒu�B
	float m_y;//�U�����@�̂������̈ʒu�B
	float m_vx;//�U���G�@�����x�N�g��x
	float m_vy;//�U���G�@�����x�N�g��y
	bool m_del;      //�폜�`�F�b�N
	int m_hp;
	int m_time;//�U���G�@�p�e�۔��˃^�C�~���O�p
};
