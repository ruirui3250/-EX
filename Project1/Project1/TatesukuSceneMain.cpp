//STL�f�o�b�O�@�\��OFF�ɂ���B
#define _SECURE_SCL(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include"GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"TatesukuSceneMain.h"
#include"GameHead.h"
//�R���X�g���N�^
TatesukuSceneMain::~TatesukuSceneMain()
{

}
//�f�X�g���N�^
TatesukuSceneMain::TatesukuSceneMain()
{

}

//�Q�[�����C�����������\�b�h
void TatesukuSceneMain::InitScene()
{
	//�O���O���t�B�b�N�ǂݍ���0��  �w�i
	Draw::LoadImage(L"�w�i(�g).png", 5, TEX_SIZE_512);

	Draw::LoadImage(L"�G�e(�g).png", 2, TEX_SIZE_512);//�G�@�e��

	Draw::LoadImage(L"���ˊ�c.png", 0, TEX_SIZE_512);

	Draw::LoadImage(L"�g�U�e��.png", 6, TEX_SIZE_512);

	Draw::LoadImage(L"�E�C���X(�g).png", 7, TEX_SIZE_512);

	Draw::LoadImage(L"��Q��.png", 8, TEX_SIZE_512);

	Draw::LoadImage(L"Boss3(�g).png", 4, TEX_SIZE_512);

	Draw::LoadImage(L"���[�U�[.png", 10, TEX_SIZE_512);

	Draw::LoadImage(L"�G�e(�g).png", 11, TEX_SIZE_512);

	Draw::LoadImage(L"��l���e�c.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"���C�t��.png", 31, TEX_SIZE_512);

	Draw::LoadImage(L"�G�i�W�[�`���[�W.png", 32, TEX_SIZE_512);

	//Draw::LoadImage(L"�c���ˊ�(�g).png", 77, TEX_SIZE_512);//Objhero

		//���y�ǂݍ���
	Audio::LoadAudio(2, L"�e1.wav", EFFECT);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^ �{�X�O���t�B�b�N��o�^
	//Draw::LoadImage(L"BossBack.png",,TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	CObjTateHero* obj = new CObjTateHero();//��l���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_TATE_HERO, 10);//��l���I�u�W�F�N�g�}�l�[�W���[��o�^

		//�N���A���w�i�I�u�W�F�N�g�쐬
	CObjTatesukuSceneMain* back = new CObjTatesukuSceneMain();
	Objs::InsertObj(back, OBJ_TATESUKU_SCENE_MAIN, 5);

	//�^�C��������
	m_time = 0;

}

//�Q�[���V�[�����s�����\�b�h
void TatesukuSceneMain::Scene()
{
	m_time++;
	if (m_time == 30)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(200.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	/*-------------------------�񕜃A�C�e���o��---------------------------*/
	if (m_time == 800)
	{
		CObjLifeItem* obj = new CObjLifeItem(350.0f, 600);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1200)
	{
		CObjLifeItem* obj = new CObjLifeItem(350.0f, 300);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1800)
	{
		CObjLifeItem* obj = new CObjLifeItem(350.0f, 300);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1500)
	{
		CObjItem* obj = new CObjItem(799.0f, 400);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	///*-------------------------------�G�o���^�C�~���O�y�шʒu����R�[�h-----------------------------------------------*/
	if (m_time == 30)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(200.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 20)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(300.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 40)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(400.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 50)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(280.0f, 100);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 60)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(250.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}



	if (m_time == 80)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(600.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 90)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 70)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(550.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 40)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(650.0f, 100);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 50)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(450.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 60)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(550.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 70)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(600.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 30)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(550.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 50)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(500.0f, 100);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 60)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(450.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}



	if (m_time == 70)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(600.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 80)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(650.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 70)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(700.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 110)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(450.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 120)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(400.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 130)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(410.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 120)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(350.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 110)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(350.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 120)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 150)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(550.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	/*------------------�G�A��������P�h�q���C��-----------------*/
	if (m_time == 400)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(550.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 400)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 400)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(550.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 400)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(600.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 400)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(650.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 400)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(700.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}

	if (m_time == 400)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(550.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 400)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}

	/*--------------------�G�A��������Q�h�q���C��------------------------*/
	if (m_time == 700)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(100.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 700)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(200.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 700)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(300.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 700)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(400.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 700)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}	
	if (m_time == 700)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(600.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 700)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(700.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	/*------------------�G�A��������R�h�q���C��----------------------*/
	if (m_time == 1000)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(100.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1000)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(200.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1000)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(400.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1000)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1000)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(600.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1000)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(700.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	/*------------------------------------------------------------------------*/
	if (m_time == 1500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(100.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(200.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(300.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(400.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(600.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(650.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1500)
	{
		CObjTateAttackEnemy* obj = new CObjTateAttackEnemy(700.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	/*----------------------------��Q���o��------------------------------*/
	if (m_time == 300)
	{
		CObjTateKesen* obj = new CObjTateKesen(10.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 300)
	{
		CObjTateKesen* obj = new CObjTateKesen(150.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 300)
	{
		CObjTateKesen* obj = new CObjTateKesen(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 300)
	{
		CObjTateKesen* obj = new CObjTateKesen(700.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	/*------------------------------------------------------------*/
	if (m_time == 600)
	{
		CObjTateKesen* obj = new CObjTateKesen(10.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 600)
	{
		CObjTateKesen* obj = new CObjTateKesen(300.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 600)
	{
		CObjTateKesen* obj = new CObjTateKesen(700.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	/*---------------------------------------------------------*/
	if (m_time == 900)
	{
		CObjTateKesen* obj = new CObjTateKesen(450.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 900)
	{
		CObjTateKesen* obj = new CObjTateKesen(700.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 900)
	{
		CObjTateKesen* obj = new CObjTateKesen(10.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}

	if (m_time == 1200)																	//���̃^�C�~���O�ō����ɕ��ʂ̓G�@�o�������邱��
	{
		CObjTateKesen* obj = new CObjTateKesen(700.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1200)
	{
		CObjTateKesen* obj = new CObjTateKesen(300.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1200)
	{
		CObjTateKesen* obj = new CObjTateKesen(500.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	/*-------------------------�G�@�}��-----------------------*/
	if (m_time == 1200)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(100.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1150)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(200.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1210)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(150.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1220)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(50.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1200)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(120.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1150)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(180.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1210)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(270.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1220)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(230.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}

	if (m_time == 1200)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(10.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1150)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(20.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1210)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(30.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1220)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(40.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1200)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(50.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1150)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(250.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1210)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(300.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}
	if (m_time == 1220)
	{
		CObjTateEnemy* obj = new CObjTateEnemy(350.0f, 10);
		Objs::InsertObj(obj, OBJ_ITEM, 50);
	}


	if (m_time == 1500)
	{
		CObjTateKesen* obj = new CObjTateKesen(10.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 1500)
	{
		CObjTateKesen* obj = new CObjTateKesen(290.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}

	if (m_time == 1500)
	{
		CObjTateKesen* obj = new CObjTateKesen(800.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}

	if (m_time == 00)
	{
		CObjTateKesen* obj = new CObjTateKesen(.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 00)
	{
		CObjTateKesen* obj = new CObjTateKesen(.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 00)
	{
		CObjTateKesen* obj = new CObjTateKesen(.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 00)
	{
		CObjTateKesen* obj = new CObjTateKesen(.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 00)
	{
		CObjTateKesen* obj = new CObjTateKesen(.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 00)
	{
		CObjTateKesen* obj = new CObjTateKesen(.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 00)
	{
		CObjTateKesen* obj = new CObjTateKesen(.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	if (m_time == 00)
	{
		CObjTateKesen* obj = new CObjTateKesen(.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}

	/*-------------------------�{�X-------------------------------*/
	if (m_time == 2000)
	{
		CObjTateBoss* obj = new CObjTateBoss(200.0f, 10);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);

	}
	/*------------------------------�A�C�e������--------------------*/
	
}

//����
//��Q���͂P����ԍ��U�O�O����ԉE�Ƃ���