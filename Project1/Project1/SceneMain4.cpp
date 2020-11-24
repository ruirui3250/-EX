//STL�f�o�b�O�@�\��OFF�ɂ���B
#define _SECURE_SCL(o)
#define _HAS_ITERATOR_DEBUGGING(o)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneMain4.h"
#include"GameHead.h"
//�R���X�g���N�^
CSceneMain4::~CSceneMain4()
{

}
//�f�X�g���N�^
CSceneMain4::CSceneMain4()
{

}

//�Q�[�����C�����������\�b�h
void CSceneMain4::InitScene()
{
	//�O���O���t�B�b�N�ǂݍ���0��  �w�i
	Draw::LoadImage(L"�w�i(�g).png", 5, TEX_SIZE_512);

	Draw::LoadImage(L"�G�e(�g).png", 2, TEX_SIZE_512);//�G�@�e��

	Draw::LoadImage(L"���ˊ퉺.png", 0, TEX_SIZE_512);

	Draw::LoadImage(L"�g�U�e��.png", 6, TEX_SIZE_512);

	Draw::LoadImage(L"�E�C���X(�g).png", 7, TEX_SIZE_512);

	Draw::LoadImage(L"��Q��.png", 8, TEX_SIZE_512);

	Draw::LoadImage(L"�{�X4.png", 4, TEX_SIZE_512);

	Draw::LoadImage(L"���[�U�[�c.png", 10, TEX_SIZE_512);

	/*Draw::LoadImage(L"�G�e(�g).png", 11, TEX_SIZE_512);*/

	Draw::LoadImage(L"��l���e�c.png", 1, TEX_SIZE_512);//bulletHero

	//Draw::LoadImage(L"�c���ˊ�(�g).png", 77, TEX_SIZE_512);//Objhero


	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^ �{�X�O���t�B�b�N��o�^
	//Draw::LoadImage(L"BossBack.png",,TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	CObjSitaHero* obj = new CObjSitaHero();//��l���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_SITA_HERO, 10);//��l���I�u�W�F�N�g�}�l�[�W���[��o�^

		//�N���A���w�i�I�u�W�F�N�g�쐬
	CObjSceneMain4* back = new CObjSceneMain4();
	Objs::InsertObj(back, OBJ_SCENE_MAIN4, 5);

	//�^�C��������
	m_time = 0;

}

//�Q�[���V�[�����s�����\�b�h
void CSceneMain4::Scene()
{
	m_time++;
	if (m_time == 30)
	{
		CObjSitaAttackEnemy* obj = new CObjSitaAttackEnemy(200.0f, 500);
		Objs::InsertObj(obj, OBJ_SITA_ATTACK_ENEMY,50);
	}
	///*-------------------------�񕜃A�C�e���o��---------------------------*/

	/////*-------------------------------�G�o���^�C�~���O�y�шʒu����R�[�h-----------------------------------------------*/
	if (m_time == 30)
	{
		CObjSitaEnemy* obj = new CObjSitaEnemy(350.0f, 500);
		Objs::InsertObj(obj, OBJ_SITA_ENEMY, 50);
		CObjSitaEnemy* obj2 = new CObjSitaEnemy(390.0f, 500);
		Objs::InsertObj(obj2, OBJ_SITA_ENEMY, 50);
		CObjSitaAttackEnemy* obj3 = new CObjSitaAttackEnemy(450.0f, 500);
		Objs::InsertObj(obj3, OBJ_SITA_ATTACK_ENEMY, 50);
		CObjSitaAttackEnemy* obj4 = new CObjSitaAttackEnemy(300.0f, 440);
		Objs::InsertObj(obj4, OBJ_SITA_ATTACK_ENEMY, 50);

	}
	if (m_time == 60)
	{
		CObjSitaKesen* obj = new CObjSitaKesen(500.0f, 500);
		Objs::InsertObj(obj, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj2= new CObjSitaKesen(100.0f, 500);
		Objs::InsertObj(obj2, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj3 = new CObjSitaKesen(50.0f, 500);
		Objs::InsertObj(obj3, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj4 = new CObjSitaKesen(550.0f, 500);
		Objs::InsertObj(obj4, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj5 = new CObjSitaKesen(600.0f, 500);
		Objs::InsertObj(obj5, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj6 = new CObjSitaKesen(650.0f, 500);
		Objs::InsertObj(obj6, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj7 = new CObjSitaKesen(700.0f, 500);
		Objs::InsertObj(obj7, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj8 = new CObjSitaKesen(0.0f, 500);
		Objs::InsertObj(obj8, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj9 = new CObjSitaKesen(750.0f, 500);
		Objs::InsertObj(obj9, OBJ_SITA_KESEN, 50);
	}

	if (m_time == 80)
	{
		CObjSitaEnemy* obj = new CObjSitaEnemy(550.0f, 500);
		Objs::InsertObj(obj, OBJ_SITA_ENEMY, 50);
		CObjSitaAttackEnemy* obj2 = new CObjSitaAttackEnemy(100.0f, 350);
		Objs::InsertObj(obj2, OBJ_SITA_ATTACK_ENEMY, 50);
	}
	if (m_time == 200)
	{
		CObjSitaKesen* obj = new CObjSitaKesen(500.0f, 450);
		Objs::InsertObj(obj, OBJ_SITA_KESEN, 50);
		CObjSitaEnemy* obj2 = new CObjSitaEnemy(0.0f, 500);
		Objs::InsertObj(obj2, OBJ_SITA_ENEMY, 50);
		CObjSitaAttackEnemy* obj3 = new CObjSitaAttackEnemy(350.0f, 500);
		Objs::InsertObj(obj3, OBJ_SITA_ATTACK_ENEMY, 50);
		CObjSitaKesen* obj4 = new CObjSitaKesen(500.0f, 400);
		Objs::InsertObj(obj4, OBJ_SITA_KESEN, 50);
	}
	if (m_time == 300)
	{
		CObjSitaAttackEnemy* obj = new CObjSitaAttackEnemy(250.0f, 500);
		Objs::InsertObj(obj, OBJ_SITA_ATTACK_ENEMY, 50);
		CObjSitaEnemy* obj2 = new CObjSitaEnemy(0.0f, 500);
		Objs::InsertObj(obj2, OBJ_SITA_ENEMY, 50);
		CObjSitaAttackEnemy* obj3 = new CObjSitaAttackEnemy(350.0f, 500);
		Objs::InsertObj(obj3, OBJ_SITA_ATTACK_ENEMY, 50);

		CObjSitaAttackEnemy* obj4 = new CObjSitaAttackEnemy(400.0f, 500);
		Objs::InsertObj(obj4, OBJ_SITA_ATTACK_ENEMY, 50);

		CObjSitaAttackEnemy* obj5 = new CObjSitaAttackEnemy(500.0f, 500);
		Objs::InsertObj(obj5, OBJ_SITA_ATTACK_ENEMY, 50);
	}

	if (m_time == 500)
	{
		CObjSitaAttackEnemy* obj5 = new CObjSitaAttackEnemy(500.0f,435);
		Objs::InsertObj(obj5, OBJ_SITA_ATTACK_ENEMY, 50);
		CObjSitaAttackEnemy* obj6 = new CObjSitaAttackEnemy(450.0f, 500);
		Objs::InsertObj(obj6, OBJ_SITA_ATTACK_ENEMY, 50);

	}
	if (m_time == 600)
	{
		CObjSitaEnemy* obj2 = new CObjSitaEnemy(200.0f, 500);
		Objs::InsertObj(obj2, OBJ_SITA_ENEMY, 50);
		CObjSitaEnemy* obj3 = new CObjSitaEnemy(150.0f, 500);
		Objs::InsertObj(obj3, OBJ_SITA_ENEMY, 50);
	}

	if (m_time == 700)
	{
		CObjSitaKesen* obj = new CObjSitaKesen(500.0f, 450);
		Objs::InsertObj(obj, OBJ_SITA_KESEN, 50);
		CObjSitaEnemy* obj2 = new CObjSitaEnemy(450.0f, 500);
		Objs::InsertObj(obj2, OBJ_SITA_ENEMY, 50);
	}

	if(m_time==900)
	{
		CObjSitaKesen* obj = new CObjSitaKesen(500.0f, 450);
		Objs::InsertObj(obj, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj2 = new CObjSitaKesen(300.0f, 250);
		Objs::InsertObj(obj2, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj3 = new CObjSitaKesen(100.0f, 500);
		Objs::InsertObj(obj3, OBJ_SITA_KESEN, 50);
		CObjSitaEnemy* obj4 = new CObjSitaEnemy(150.0f, 500);
		Objs::InsertObj(obj4, OBJ_SITA_ENEMY, 50);
		CObjSitaEnemy* obj5 = new CObjSitaEnemy(100.0f, 400);
		Objs::InsertObj(obj5, OBJ_SITA_ENEMY, 50);
		CObjSitaAttackEnemy* obj6 = new CObjSitaAttackEnemy(450.0f, 500);
		Objs::InsertObj(obj6, OBJ_SITA_ATTACK_ENEMY, 50);
		CObjSitaAttackEnemy* obj7 = new CObjSitaAttackEnemy(250.0f, 300);
		Objs::InsertObj(obj7, OBJ_SITA_ATTACK_ENEMY, 50);
	}
	if (m_time == 1000)
	{
		CObjEnemyBossBullet4* obj = new CObjEnemyBossBullet4(800.0f, 500);
		Objs::InsertObj(obj, OBJ_BOSS_BULLET_ENEMY, 50);
	}
	if (m_time == 1200)
	{
		CObjSitaAttackEnemy* obj = new CObjSitaAttackEnemy(150.0f, 500);
		Objs::InsertObj(obj, OBJ_SITA_ATTACK_ENEMY, 50);

		CObjSitaAttackEnemy* obj2 = new CObjSitaAttackEnemy(350.0f, 500);
		Objs::InsertObj(obj2, OBJ_SITA_ATTACK_ENEMY, 50);

		CObjSitaEnemy* obj3 = new CObjSitaEnemy(450.0f, 400);
		Objs::InsertObj(obj3, OBJ_SITA_ATTACK_ENEMY, 50);

		CObjSitaEnemy* obj4 = new CObjSitaEnemy(250.0f, 500);
		Objs::InsertObj(obj4, OBJ_SITA_ATTACK_ENEMY, 50);

		CObjSitaAttackEnemy* obj5 = new CObjSitaAttackEnemy(350.0f, 300);
		Objs::InsertObj(obj5, OBJ_SITA_ATTACK_ENEMY, 50);


		CObjSitaKesen* obj6 = new CObjSitaKesen(750.0f, 500);
		Objs::InsertObj(obj6, OBJ_SITA_KESEN, 50);


		CObjSitaKesen* obj7 = new CObjSitaKesen(0.0f, 500);
		Objs::InsertObj(obj7, OBJ_SITA_KESEN, 50);

		CObjSitaAttackEnemy* obj8 = new CObjSitaAttackEnemy(600.0f, 500);
		Objs::InsertObj(obj8, OBJ_SITA_ATTACK_ENEMY, 50);

		CObjSitaAttackEnemy* obj9 = new CObjSitaAttackEnemy(350.0f, 300);
		Objs::InsertObj(obj9, OBJ_SITA_ATTACK_ENEMY, 50);

		CObjSitaEnemy* obj10 = new CObjSitaEnemy(350.0f, 300);
		Objs::InsertObj(obj10, OBJ_SITA_ATTACK_ENEMY, 50);

		CObjSitaAttackEnemy* obj11 = new CObjSitaAttackEnemy(750.0f, 500);
		Objs::InsertObj(obj11, OBJ_SITA_ATTACK_ENEMY, 50);

		CObjSitaAttackEnemy* obj12 = new CObjSitaAttackEnemy(50.0f, 500);
		Objs::InsertObj(obj12, OBJ_SITA_ATTACK_ENEMY, 50);

	}

	if (m_time == 1400)
	{
		CObjSitaKesen* obj1 = new CObjSitaKesen(750.0f, 500);
		Objs::InsertObj(obj1, OBJ_SITA_KESEN, 50);
		CObjSitaKesen* obj2 = new CObjSitaKesen(150.0f, 500);
		Objs::InsertObj(obj2, OBJ_SITA_KESEN, 50);
	}

	if (m_time == 1600)
	{
		CObjEnemyBossBullet4* obj = new CObjEnemyBossBullet4(0.0f, 500);
		Objs::InsertObj(obj, OBJ_BOSS_BULLET_ENEMY, 50);
		CObjEnemyBossBullet4* obj2 = new CObjEnemyBossBullet4(800.0f, 500);
		Objs::InsertObj(obj2, OBJ_BOSS_BULLET_ENEMY, 50);
	}


	///*-------------------------�{�X-------------------------------*/
	if (m_time == 2000)
	{
		CObjEnemyBoss4* obj = new CObjEnemyBoss4(250,500);
		Objs::InsertObj(obj, OBJ_BOSS_ENEMY4, 100);

	}

}

//����
//��Q���͂P����ԍ��U�O�O����ԉE�Ƃ���