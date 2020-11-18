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
    m_vx = 0.0f;
    m_vy = 0.0f;

    //�����蔻��pHitBox���쐬
    Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_HOMING_BULLET, 1);
}

//�A�N�V����
void CObjHomingEnemy::Action()
{
 //�ړ�����
    m_vx = -1.0f;
    m_vy = 0.0f;

    //�x�N�g���̒��������߂�B(�O�����̒藝�B)
    float r = 0.0f;
    r = m_vx * m_vx + m_vy * m_vy;
    r = sqrt(r);//r�����[�g�����߂�B

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
    src.m_left = 32.0f;
    src.m_right = 64.0f;
    src.m_bottom = 32.0f;

    //�\���ʒu�̐ݒ�
    dst.m_top = 0.0f + m_y;
    dst.m_left = 32.0f + m_x;
    dst.m_right = 0.0f + m_x;
    dst.m_bottom = 32.0f + m_y;

    //0�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������Ƃɕ`��
    Draw::Draw(3, &src, &dst, c, 0.0f);
}