//�g�p����w�b�_�[�t�@�C��
#include "GameL/\DrawTexture.h"
#include "GameL/\HitBoxManager.h"

#include "GameHead.h"
#include "CObjHomingEnemy.h"
#include "UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�R���X�^���X�^
CObjHomingEnemy::CObjHomingEnemy(float x, float y)
{
    m_x = x;
    m_y = y;
}

//�C�j�V�����C�Y
void CObjHomingEnemy::Init()
{
	m_eff.m_top = 32;
	m_eff.m_left = 0;
	m_eff.m_right = 32;
	m_eff.m_bottom = 64;
	m_ani = 0;
	m_ani_time = 0;
	m_del = false;

	m_vx = 1.0f;
	m_vy = 0.0f;
	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);
    

    //�����蔻��pHitBox���쐬
    Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_HOMING_BULLET, 1);
}

//�A�N�V����
void CObjHomingEnemy::Action()
{

	//��l���@�ƗU���e�ۂŊp�x�����
	float ar = 170.0f;

	//�e�ۂƌ��݂̌����Ă�����������B
	float br = 180.0f;

	float r = 3.14 / 180.0f;//�p�x1

	if (ar < br)
	{
		//�ړ�������1������B
		m_vx = m_vx * cos(r) - m_vy * sin(r);
		m_vy = m_vy * cos(r) + m_vx * sin(r);
	}
	else
	{
		//�ړ�������-1������B
		m_vx = m_vx * cos(-r) - m_vy * sin(-r);
		m_vy = m_vy * cos(-r) + m_vx * sin(-r);
	}
	UnitVec(&m_vx, &m_vy);
	m_x = m_vx * 5.0f;
	m_y = m_vy * 5.0f;

	//�U���e�ۂ�HitBox�̍X�V�p�|�C���^�[�l��
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);//HitBox�̈ʒu���X�V

	//�U���e�ۂ̊��S�ɗ̈�O�ɏo���ꍇ�U���e�ۂ�j��
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, -800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);//���M�ɍ폜���ߏo��
		Hits::DeleteHitBox(this);//�U���e�ۃI�u�W�F�N�gHITBO���폜
	}
    //������0���ǂ������ׂ�B
    if (r == 0.0f)
    {
        ;//0�Ȃ牽�����Ȃ��B
    }
    else
    {
        //���K��������
        m_vx = 1.0f / r * m_vx;
        m_vy = 1.0f / r * m_vy;
    }
    //���x��t����
    m_vx *= 1.5f;
    m_vy *= 1.5f;

    //�ړ��x�N�g�������W�ɕϊ�����B
    m_x += m_vx;
    m_y += m_vy;

    //HitBox�̓��e���X�V�B
    CHitBox* hit = Hits::GetHitBox(this);
    hit->SetPos(m_x, m_y);

    //�z�[�~���O�G�@�����S�ɗ̈�O�ł���j������B
    if (m_x < 32.0f)
    {
        this->SetStatus(false);//���M�ɍ폜����
        Hits::DeleteHitBox(this);//�z�[�~���O�G�@�����L����HitBox
    }
    //�e�ۂ��ڐG���Ă��邩���ׂ�B
    if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
    {
        this->SetStatus(false);
        Hits::DeleteHitBox(this);
    }
    //�@�̂��ڐG���Ă��邩���ׂ�B
    if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
    {
        this->SetStatus(false);
        Hits::DeleteHitBox(this);
    }
}

//�h���[
void CObjHomingEnemy::Draw()
{
    //�`��J���[���@R=RED�@G=GREEN�@B=BLUE�@A=ALPHA�i���ߏ��j
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };

    RECT_F src;//�`�挳�؂���ʒu
    RECT_F dst;//�`���\���ʒu

    //�؂���ʒu�̐ݒ�
    src.m_top = 0.0f;
    src.m_left = 0.0f;
    src.m_right = 32.0f;
    src.m_bottom = 32.0f;

    //�\���ʒu�̐ݒ�
    dst.m_top = 0.0f + m_y;
    dst.m_left = 0.0f + m_x;
    dst.m_right = 32.0f + m_x;
    dst.m_bottom = 32.0f + m_y;

	float r = 0.0f;

	//��l���@�ƗU���e�ۂŊp�x�����
    CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//��l���@�����݂���ꍇ�A�U���p�x�̌v�Z����
	if (obj != nullptr)
	{
		float x = obj->GetX() - m_x;
		float y = obj->GetY() - m_y;
		r = GetAtan2Angle(x, -y);


    //0�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������Ƃɕ`��
    Draw::Draw(3, &src, &dst, c, 0.0f);
}