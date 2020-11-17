//STL�f�o�b�O�@�\��OFF�ɂ���B
#define _SECURE_SCL(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include"GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneMain.h"
#include"GameHead.h"
//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}
//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//�Q�[�����C�����������\�b�h
void CSceneMain::InitScene()
{
	//�O���O���t�B�b�N�ǂݍ���0��  �w�i
	Draw::LoadImage(L"�w�i(�g).png", 9, TEX_SIZE_512);

	Draw::LoadImage(L"�E�C���X(�g).png", 3, TEX_SIZE_512);

	Draw::LoadImageW(L"�G�e(�g).png", 5, TEX_SIZE_512);

	Draw::LoadImage(L"���ˊ�(�g).png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"�J�v�Z��.png", 2, TEX_SIZE_512);

	//Draw::LoadImage(L"��Q��.png",9, TEX_SIZE_512);

	Draw::LoadImage(L"�g�U�e��.png",6, TEX_SIZE_512);
	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^ �{�X�O���t�B�b�N��o�^
	Draw::LoadImage(L"Boss1(�g).png",4,TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();//��l���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_HERO, 10);//��l���I�u�W�F�N�g�}�l�[�W���[��o�^

	////block�I�u�W�F�N�g�쐬
	//CObjBlock* objb = new CObjBlock();
	//Objs::InsertObj(objb, OBJ_BLOCK, 9);

		//�N���A���w�i�I�u�W�F�N�g�쐬
	CObjSceneMain* back = new CObjSceneMain();
	Objs::InsertObj(back, OBJ_SCENE_MAIN, 9);

	//�^�C��������
	m_time = 0;

}

//�Q�[���V�[�����s�����\�b�h
void CSceneMain::Scene()
{
	m_time++;

	if (m_time == 30)
	{
		CObjEnemy* obj = new CObjEnemy(799.0f, 400);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);

		CObjAttackEnemy* obj1;
		obj1 = new CObjAttackEnemy(799, 230);
		Objs::InsertObj(obj1, OBJ_ATTACK_ENEMY, 50);

		CObjAttackEnemy* obj2;
		obj2 = new CObjAttackEnemy(799, 330);
		Objs::InsertObj(obj2, OBJ_ATTACK_ENEMY, 50);

		CObjEnemy* obj3 = new CObjEnemy(650.0f, 130);
		Objs::InsertObj(obj3, OBJ_ENEMY, 50);

		CObjEnemy* obj4 = new CObjEnemy(799.0f, 160);
		Objs::InsertObj(obj4, OBJ_ENEMY, 50);

	}
	else if (m_time == 40)
	{
		//block object create
	/*	CObjBlock* obj = new CObjBlock(799.0f, 0);
		Objs::InsertObj(obj, OBJ_BLOCK, 50);

		CObjBlock* obj1 = new CObjBlock(766, 0);
		Objs::InsertObj(obj1, OBJ_BLOCK, 50);

		CObjBlock* obj2 = new CObjBlock(733, 0);
		Objs::InsertObj(obj2, OBJ_BLOCK, 50);

		CObjBlock* obj3 = new CObjBlock(799.0f, 33);
		Objs::InsertObj(obj3, OBJ_BLOCK, 50);

		CObjBlock* obj4 = new CObjBlock(766,33);
		Objs::InsertObj(obj4, OBJ_BLOCK, 50);

		CObjBlock* obj5 = new CObjBlock(733,33);
		Objs::InsertObj(obj5, OBJ_BLOCK, 50);

		CObjBlock* obj6 = new CObjBlock (799.0f, 66);
		Objs::InsertObj(obj6, OBJ_BLOCK, 50);

		CObjBlock* obj7 = new CObjBlock(766, 66);
		Objs::InsertObj(obj7, OBJ_BLOCK, 50);

		CObjBlock* obj8 = new CObjBlock(733, 66);
		Objs::InsertObj(obj8, OBJ_BLOCK, 50);

		CObjBlock* obj9 = new CObjBlock (733, 566);
		Objs::InsertObj(obj9, OBJ_BLOCK, 50);

		CObjBlock* obj10 = new CObjBlock(766, 566);
		Objs::InsertObj(obj10, OBJ_BLOCK, 50);

		CObjBlock* obj11 = new CObjBlock(799.0f, 566);
		Objs::InsertObj(obj11, OBJ_BLOCK, 50);

		CObjBlock* obj12 = new CObjBlock(733, 533);
		Objs::InsertObj(obj12, OBJ_BLOCK, 50);

		CObjBlock* obj13 = new CObjBlock(766, 533);
		Objs::InsertObj(obj13, OBJ_BLOCK, 50);

		CObjBlock* obj14 = new CObjBlock(799.0f, 533);
		Objs::InsertObj(obj14, OBJ_BLOCK, 50);

		CObjBlock* obj15 = new CObjBlock(733, 500);
		Objs::InsertObj(obj15, OBJ_BLOCK, 50);

		CObjBlock* obj16 = new CObjBlock(766, 500);
		Objs::InsertObj(obj16, OBJ_BLOCK, 50);

		CObjBlock* obj17 = new CObjBlock(799.0f, 500);
		Objs::InsertObj(obj17, OBJ_BLOCK, 50);*/
	}

	else if (m_time == 110)
	{
		//CObjBlock* obj = new CObjBlock(799.0f, 0);
		//Objs::InsertObj(obj, OBJ_BLOCK, 50);

		//CObjBlock* obj1 = new CObjBlock(766, 0);
		//Objs::InsertObj(obj1, OBJ_BLOCK, 50);

		//CObjBlock* obj2 = new CObjBlock(733, 0);
		//Objs::InsertObj(obj2, OBJ_BLOCK, 50);

		//CObjBlock* obj3 = new CObjBlock(799.0f, 33);
		//Objs::InsertObj(obj3, OBJ_BLOCK, 50);

		//CObjBlock* obj4 = new CObjBlock(766, 33);
		//Objs::InsertObj(obj4, OBJ_BLOCK, 50);

		//CObjBlock* obj5 = new CObjBlock(733, 33);
		//Objs::InsertObj(obj5, OBJ_BLOCK, 50);

		//CObjBlock* obj6 = new CObjBlock(799.0f, 66);
		//Objs::InsertObj(obj6, OBJ_BLOCK, 50);

		//CObjBlock* obj7 = new CObjBlock(766, 66);
		//Objs::InsertObj(obj7, OBJ_BLOCK, 50);

		//CObjBlock* obj8 = new CObjBlock(733, 66);
		//Objs::InsertObj(obj8, OBJ_BLOCK, 50);

		//CObjBlock* obj9 = new CObjBlock(733, 566);
		//Objs::InsertObj(obj9, OBJ_BLOCK, 50);

		//CObjBlock* obj10 = new CObjBlock(766, 566);
		//Objs::InsertObj(obj10, OBJ_BLOCK, 50);

		//CObjBlock* obj11 = new CObjBlock(799.0f, 566);
		//Objs::InsertObj(obj11, OBJ_BLOCK, 50);

		//CObjBlock* obj12 = new CObjBlock(733, 533);
		//Objs::InsertObj(obj12, OBJ_BLOCK, 50);

		//CObjBlock* obj13 = new CObjBlock(766, 533);
		//Objs::InsertObj(obj13, OBJ_BLOCK, 50);

		//CObjBlock* obj14 = new CObjBlock(799.0f, 533);
		//Objs::InsertObj(obj14, OBJ_BLOCK, 50);

		//CObjBlock* obj15 = new CObjBlock(733, 500);
		//Objs::InsertObj(obj15, OBJ_BLOCK, 50);

		//CObjBlock* obj16 = new CObjBlock(766, 500);
		//Objs::InsertObj(obj16, OBJ_BLOCK, 50);

		//CObjBlock* obj17 = new CObjBlock(799.0f, 500);
		//Objs::InsertObj(obj17, OBJ_BLOCK, 50);
	}
	else if (m_time == 450)
	{
		CObjEnemy* obj;
		obj = new CObjEnemy(799.0f, 300);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
		obj = new CObjEnemy(799.0f, 350);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
		obj = new CObjEnemy(799.0f, 250);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);

		CObjAttackEnemy* obj2;
		obj2 = new CObjAttackEnemy(799.0f, 200);
		Objs::InsertObj(obj2, OBJ_ATTACK_ENEMY, 50);
		obj2 = new CObjAttackEnemy(799.0f, 400);
		Objs::InsertObj(obj2, OBJ_ATTACK_ENEMY, 50);
	}
	else if (m_time == 550)
	{
	//CObjBlock* obj = new CObjBlock(799.0f, 0);
	//Objs::InsertObj(obj, OBJ_BLOCK, 50);

	//CObjBlock* obj1 = new CObjBlock(766, 0);
	//Objs::InsertObj(obj1, OBJ_BLOCK, 50);

	//CObjBlock* obj2 = new CObjBlock(733, 0);
	//Objs::InsertObj(obj2, OBJ_BLOCK, 50);

	//CObjBlock* obj3 = new CObjBlock(799.0f, 33);
	//Objs::InsertObj(obj3, OBJ_BLOCK, 50);

	//CObjBlock* obj4 = new CObjBlock(766, 33);
	//Objs::InsertObj(obj4, OBJ_BLOCK, 50);

	//CObjBlock* obj5 = new CObjBlock(733, 33);
	//Objs::InsertObj(obj5, OBJ_BLOCK, 50);

	//CObjBlock* obj6 = new CObjBlock(799.0f, 66);
	//Objs::InsertObj(obj6, OBJ_BLOCK, 50);

	//CObjBlock* obj7 = new CObjBlock(766, 66);
	//Objs::InsertObj(obj7, OBJ_BLOCK, 50);

	//CObjBlock* obj8 = new CObjBlock(733, 66);
	//Objs::InsertObj(obj8, OBJ_BLOCK, 50);

	//CObjBlock* obj9 = new CObjBlock(733, 566);
	//Objs::InsertObj(obj9, OBJ_BLOCK, 50);

	//CObjBlock* obj10 = new CObjBlock(766, 566);
	//Objs::InsertObj(obj10, OBJ_BLOCK, 50);

	//CObjBlock* obj11 = new CObjBlock(799.0f, 566);
	//Objs::InsertObj(obj11, OBJ_BLOCK, 50);

	//CObjBlock* obj12 = new CObjBlock(733, 533);
	//Objs::InsertObj(obj12, OBJ_BLOCK, 50);

	//CObjBlock* obj13 = new CObjBlock(766, 533);
	//Objs::InsertObj(obj13, OBJ_BLOCK, 50);

	//CObjBlock* obj14 = new CObjBlock(799.0f, 533);
	//Objs::InsertObj(obj14, OBJ_BLOCK, 50);

	//CObjBlock* obj15 = new CObjBlock(733, 500);
	//Objs::InsertObj(obj15, OBJ_BLOCK, 50);

	//CObjBlock* obj16 = new CObjBlock(766, 500);
	//Objs::InsertObj(obj16, OBJ_BLOCK, 50);

	//CObjBlock* obj17 = new CObjBlock(799.0f, 500);
	//Objs::InsertObj(obj17, OBJ_BLOCK, 50);

	}
	else if (m_time == 780)
	{
	//CObjBlock* obj = new CObjBlock(799.0f, 300);
	//Objs::InsertObj(obj, OBJ_BLOCK, 50);
	//CObjBlock* obj2 = new CObjBlock(799.0f, 277);
	//Objs::InsertObj(obj2, OBJ_BLOCK, 50);
	//CObjBlock* obj3 = new CObjBlock(799.0f, 244);
	//Objs::InsertObj(obj3, OBJ_BLOCK, 50);
	//CObjBlock* obj4 = new CObjBlock(766.0f, 300);
	//Objs::InsertObj(obj4, OBJ_BLOCK, 50);
	//CObjBlock* obj5 = new CObjBlock(766.0f, 277);
	//Objs::InsertObj(obj5, OBJ_BLOCK, 50);
	//CObjBlock* obj5 = new CObjBlock(766.0f, 244);
	//Objs::InsertObj(obj5, OBJ_BLOCK, 50);
	//CObjBlock* obj6 = new CObjBlock(733.0f, 300);
	//Objs::InsertObj(obj6, OBJ_BLOCK, 50);
	//CObjBlock* obj7 = new CObjBlock(733.0f, 277);
	//Objs::InsertObj(obj7, OBJ_BLOCK, 50);
	//CObjBlock* obj8 = new CObjBlock(733.0f, 244);
	//Objs::InsertObj(obj8, OBJ_BLOCK, 50);


	}
	else if (m_time == 890)
	{
	CObjAttackEnemy* obj;
	obj = new CObjAttackEnemy(799.0f, 450);
	}
	else if (m_time == 850)
	{
	CObjEnemy* obj;
	obj = new CObjEnemy(799.0, 305);
	}
	else if (m_time == 1200)
	{
		//���y�`�F���W
		//Audio::Stop(0);//0�ȃX�g�b�v
		//Audio::Start(1);//1�ȖڃX�^�[�g

		CObjBoss* obj;
		obj = new CObjBoss(300, 250);
		Objs::InsertObj(obj, OBJ_BOSS_ENEMY, 50);
	}
}