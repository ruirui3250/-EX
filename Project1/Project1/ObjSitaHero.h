#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
//�I�u�W�F�N�g�F��l��
class CObjSitaHero :public CObj
{
public:
	CObjSitaHero() {};
	~CObjSitaHero() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
	float GetX();	   //�ʒu���X�ύX�p
	float GetY();	   //�ʒu���X�ύX�p
	void SetX(float x) { m_px = x; }//�ʒu���X�ύX�p
	void SetY(float y) { m_py = y; }//�ʒu���X�ύX�p
	void SetVY(float vy) { m_vy = vy; }//�ʒu���X�V�錾
private:
	float m_x;//��l���@��x�����̈ʒu�ϐ�
	float m_y;//��l���@��y�����̈ʒu�ϐ�
	float m_vx;//��l���@��x�����̃x�N�g���p�ϐ�
	float m_vy;//��l���@��y�����̃x�N�g���p�ϐ�
	int		m_hp;//�ŏ����炠�镪
	int     m_ka;
	int     m_la;

	int		m_nhp;//�c�蕪
	int     m_nka;
	int     m_nla;

	float m_px;//��l���ʒu�擾X���W
	float m_py;//��l���ʒu�擾Y���W
	float m_vv;//�f�[�^�X�V�p ���������ꍇ�͂��ꂪ�@�\����

	bool m_f = true;
	bool m_key_flag = true;
};
