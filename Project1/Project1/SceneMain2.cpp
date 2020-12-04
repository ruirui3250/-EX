//STL�f�o�b�O�@�\��OFF�ɂ���B
#define _SECURE_SCL(o)
#define _HAS_ITERATOR_DEBUGGING(o)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include"GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneMain2.h"
#include"GameHead.h"
//�R���X�g���N�^
CSceneMain2::CSceneMain2()
{

}
//�f�X�g���N�^
CSceneMain2::~CSceneMain2()
{

}

//�Q�[�����C�����������\�b�h
void CSceneMain2::InitScene()
{
	//�O���O���t�B�b�N�ǂݍ���0��  �w�i
	Draw::LoadImage(L"�w�i(�g).png", 9, TEX_SIZE_512);

	Draw::LoadImage(L"�E�C���X(�g).png", 3, TEX_SIZE_512);

	Draw::LoadImageW(L"�G�e(�g).png", 5, TEX_SIZE_512);

	Draw::LoadImage(L"���ˊ�.png", 0, TEX_SIZE_512);

	Draw::LoadImage(L"�J�v�Z��.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"��Q��.png",8, TEX_SIZE_512);

	Draw::LoadImage(L"�g�U�e��.png", 6, TEX_SIZE_512);
	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^ �{�X�O���t�B�b�N��o�^
	Draw::LoadImage(L"�{�X2.png", 4, TEX_SIZE_512);

	Draw::LoadImage(L"���[�U�[.png", 10, TEX_SIZE_512);

	//���y�ǂݍ���
	Audio::LoadAudio(2, L"�e1.wav", EFFECT);

	//���y�ǂݍ���
	Audio::LoadAudio(4, L"���[�U�[.wav", EFFECT);

	//���y�ǂݍ���
	Audio::LoadAudio(5, L"�g�U�e.wav", EFFECT);

	//��l���I�u�W�F�N�g�쐬
	CObjHero2* obj = new CObjHero2();//��l���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_HERO, 10);//��l���I�u�W�F�N�g�}�l�[�W���[��o�^

	////block�I�u�W�F�N�g�쐬
	//CObjBlock* objb = new CObjBlock();
	//Objs::InsertObj(objb, OBJ_BLOCK, 9);

		//�w�i�I�u�W�F�N�g�쐬
	CObjSceneMain2* back = new CObjSceneMain2();
	Objs::InsertObj(back, OBJ_SCENE_MAIN2, 9);

	//�^�C��������
	m_time = 0;

}

//�Q�[���V�[�����s�����\�b�h
void CSceneMain2::Scene()
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
		CObjYokoKesen* obj = new CObjYokoKesen(799.0f, 0);
		Objs::InsertObj(obj, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj1 = new CObjYokoKesen(766, 0);
		Objs::InsertObj(obj1, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj2 = new CObjYokoKesen(733, 0);
		Objs::InsertObj(obj2, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj3 = new CObjYokoKesen(799.0f, 33);
		Objs::InsertObj(obj3, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj4 = new CObjYokoKesen(766, 33);
		Objs::InsertObj(obj4, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj5 = new CObjYokoKesen(733, 33);
		Objs::InsertObj(obj5, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj6 = new CObjYokoKesen(799.0f, 66);
		Objs::InsertObj(obj6, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj7 = new CObjYokoKesen(766, 66);
		Objs::InsertObj(obj7, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj8 = new CObjYokoKesen(733, 66);
		Objs::InsertObj(obj8, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj9 = new CObjYokoKesen(733, 566);
		Objs::InsertObj(obj9, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj10 = new CObjYokoKesen(766, 566);
		Objs::InsertObj(obj10, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj11 = new CObjYokoKesen(799.0f, 566);
		Objs::InsertObj(obj11, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj12 = new CObjYokoKesen(733, 533);
		Objs::InsertObj(obj12, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj13 = new CObjYokoKesen(766, 533);
		Objs::InsertObj(obj13, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj14 = new CObjYokoKesen(799.0f, 533);
		Objs::InsertObj(obj14, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj15 = new CObjYokoKesen(733, 500);
		Objs::InsertObj(obj15, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj16 = new CObjYokoKesen(766, 500);
		Objs::InsertObj(obj16, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj17 = new CObjYokoKesen(799.0f, 500);
		Objs::InsertObj(obj17, OBJ_YOKO_KESEN, 50);

	}

	else if (m_time == 110)
	{
		//block object create
		CObjYokoKesen* obj = new CObjYokoKesen(799.0f, 0);
		Objs::InsertObj(obj, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj1 = new CObjYokoKesen(766, 0);
		Objs::InsertObj(obj1, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj2 = new CObjYokoKesen(733, 0);
		Objs::InsertObj(obj2, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj3 = new CObjYokoKesen(799.0f, 33);
		Objs::InsertObj(obj3, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj4 = new CObjYokoKesen(766, 33);
		Objs::InsertObj(obj4, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj5 = new CObjYokoKesen(733, 33);
		Objs::InsertObj(obj5, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj6 = new CObjYokoKesen(799.0f, 66);
		Objs::InsertObj(obj6, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj7 = new CObjYokoKesen(766, 66);
		Objs::InsertObj(obj7, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj8 = new CObjYokoKesen(733, 66);
		Objs::InsertObj(obj8, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj9 = new CObjYokoKesen(733, 566);
		Objs::InsertObj(obj9, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj10 = new CObjYokoKesen(766, 566);
		Objs::InsertObj(obj10, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj11 = new CObjYokoKesen(799.0f, 566);
		Objs::InsertObj(obj11, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj12 = new CObjYokoKesen(733, 533);
		Objs::InsertObj(obj12, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj13 = new CObjYokoKesen(766, 533);
		Objs::InsertObj(obj13, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj14 = new CObjYokoKesen(799.0f, 533);
		Objs::InsertObj(obj14, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj15 = new CObjYokoKesen(733, 500);
		Objs::InsertObj(obj15, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj16 = new CObjYokoKesen(766, 500);
		Objs::InsertObj(obj16, OBJ_YOKO_KESEN, 50);

		CObjYokoKesen* obj17 = new CObjYokoKesen(799.0f, 500);
		Objs::InsertObj(obj17, OBJ_YOKO_KESEN, 50);

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
	//block object create
	CObjYokoKesen* obj = new CObjYokoKesen(799.0f, 0);
	Objs::InsertObj(obj, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj1 = new CObjYokoKesen(766, 0);
	Objs::InsertObj(obj1, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj2 = new CObjYokoKesen(733, 0);
	Objs::InsertObj(obj2, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj3 = new CObjYokoKesen(799.0f, 33);
	Objs::InsertObj(obj3, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj4 = new CObjYokoKesen(766, 33);
	Objs::InsertObj(obj4, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj5 = new CObjYokoKesen(733, 33);
	Objs::InsertObj(obj5, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj6 = new CObjYokoKesen(799.0f, 66);
	Objs::InsertObj(obj6, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj7 = new CObjYokoKesen(766, 66);
	Objs::InsertObj(obj7, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj8 = new CObjYokoKesen(733, 66);
	Objs::InsertObj(obj8, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj9 = new CObjYokoKesen(733, 566);
	Objs::InsertObj(obj9, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj10 = new CObjYokoKesen(766, 566);
	Objs::InsertObj(obj10, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj11 = new CObjYokoKesen(799.0f, 566);
	Objs::InsertObj(obj11, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj12 = new CObjYokoKesen(733, 533);
	Objs::InsertObj(obj12, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj13 = new CObjYokoKesen(766, 533);
	Objs::InsertObj(obj13, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj14 = new CObjYokoKesen(799.0f, 533);
	Objs::InsertObj(obj14, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj15 = new CObjYokoKesen(733, 500);
	Objs::InsertObj(obj15, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj16 = new CObjYokoKesen(766, 500);
	Objs::InsertObj(obj16, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj17 = new CObjYokoKesen(799.0f, 500);
	Objs::InsertObj(obj17, OBJ_YOKO_KESEN, 50);

	}
	else if (m_time == 600)
	{
	CObjYokoKesen* obj = new CObjYokoKesen(799.0f, 300);
	Objs::InsertObj(obj, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj2 = new CObjYokoKesen(799.0f, 277);
	Objs::InsertObj(obj2, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj3 = new CObjYokoKesen(799.0f, 244);
	Objs::InsertObj(obj3, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj4 = new CObjYokoKesen(766.0f, 300);
	Objs::InsertObj(obj4, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj5 = new CObjYokoKesen(766.0f, 277);
	Objs::InsertObj(obj5, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj1 = new CObjYokoKesen(766.0f, 244);
	Objs::InsertObj(obj1, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj6 = new CObjYokoKesen(733.0f, 300);
	Objs::InsertObj(obj6, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj7 = new CObjYokoKesen(733.0f, 277);
	Objs::InsertObj(obj7, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj8 = new CObjYokoKesen(733.0f, 244);
	Objs::InsertObj(obj8, OBJ_YOKO_KESEN, 50);
	}
	else if (m_time == 631)
	{
	CObjEnemy* obj;
	obj = new CObjEnemy(799.0f, 150);
	Objs::InsertObj(obj, OBJ_ENEMY, 50);

	CObjEnemy* obj2;
	obj2 = new CObjEnemy(799.0f,10 );
	Objs::InsertObj(obj2, OBJ_ENEMY, 50);

	CObjAttackEnemy* obj3;
	obj3 = new CObjAttackEnemy(799.0f, 394);
	Objs::InsertObj(obj3, OBJ_ATTACK_ENEMY, 50);

	CObjAttackEnemy* obj4;
	obj4 = new CObjAttackEnemy(799.0f, 450);
	Objs::InsertObj(obj4, OBJ_ATTACK_ENEMY, 50);

 }
	else if (m_time == 666)
	{
	CObjYokoKesen* obj = new CObjYokoKesen(799.0f, 300);
	Objs::InsertObj(obj, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj2 = new CObjYokoKesen(799.0f, 277);
	Objs::InsertObj(obj2, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj3 = new CObjYokoKesen(799.0f, 244);
	Objs::InsertObj(obj3, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj4 = new CObjYokoKesen(766.0f, 300);
	Objs::InsertObj(obj4, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj5 = new CObjYokoKesen(766.0f, 277);
	Objs::InsertObj(obj5, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj1 = new CObjYokoKesen(766.0f, 244);
	Objs::InsertObj(obj1, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj6 = new CObjYokoKesen(733.0f, 300);
	Objs::InsertObj(obj6, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj7 = new CObjYokoKesen(733.0f, 277);
	Objs::InsertObj(obj7, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj8 = new CObjYokoKesen(733.0f, 244);
	Objs::InsertObj(obj8, OBJ_YOKO_KESEN, 50);

	CObjAttackEnemy* obj9;
	obj9 = new CObjAttackEnemy(799.0f, 150);
	Objs::InsertObj(obj9, OBJ_ATTACK_ENEMY, 50);

	CObjEnemy* obj10;
	obj10 = new CObjEnemy(799.0f, 10);
	Objs::InsertObj(obj10, OBJ_ENEMY, 50);

	CObjEnemy* obj11;
	obj11 = new CObjEnemy(799.0f, 180);
	Objs::InsertObj(obj11, OBJ_ENEMY, 50);

	CObjAttackEnemy* obj12;
	obj12 = new CObjAttackEnemy(799.0f, 450);
	Objs::InsertObj(obj12, OBJ_ATTACK_ENEMY, 50);

	CObjAttackEnemy* obj13;
	obj13 = new CObjAttackEnemy(799.0f, 350);
	Objs::InsertObj(obj13, OBJ_ATTACK_ENEMY, 50);
 }

	else if (m_time == 732)
	{
	CObjYokoKesen* obj = new CObjYokoKesen(799.0f, 300);
	Objs::InsertObj(obj, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj2 = new CObjYokoKesen(799.0f, 277);
	Objs::InsertObj(obj2, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj3 = new CObjYokoKesen(799.0f, 244);
	Objs::InsertObj(obj3, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj4 = new CObjYokoKesen(766.0f, 300);
	Objs::InsertObj(obj4, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj5 = new CObjYokoKesen(766.0f, 277);
	Objs::InsertObj(obj5, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj1 = new CObjYokoKesen(766.0f, 244);
	Objs::InsertObj(obj1, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj6 = new CObjYokoKesen(733.0f, 300);
	Objs::InsertObj(obj6, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj7 = new CObjYokoKesen(733.0f, 277);
	Objs::InsertObj(obj7, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj8 = new CObjYokoKesen(733.0f, 244);
	Objs::InsertObj(obj8, OBJ_YOKO_KESEN, 50);
 }

	else if (m_time == 798)
	{
	CObjYokoKesen* obj = new CObjYokoKesen(799.0f, 300);
	Objs::InsertObj(obj, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj2 = new CObjYokoKesen(799.0f, 277);
	Objs::InsertObj(obj2, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj3 = new CObjYokoKesen(799.0f, 244);
	Objs::InsertObj(obj3, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj4 = new CObjYokoKesen(766.0f, 300);
	Objs::InsertObj(obj4, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj5 = new CObjYokoKesen(766.0f, 277);
	Objs::InsertObj(obj5, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj1 = new CObjYokoKesen(766.0f, 244);
	Objs::InsertObj(obj1, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj6 = new CObjYokoKesen(733.0f, 300);
	Objs::InsertObj(obj6, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj7 = new CObjYokoKesen(733.0f, 277);
	Objs::InsertObj(obj7, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj8 = new CObjYokoKesen(733.0f, 244);
	Objs::InsertObj(obj8, OBJ_YOKO_KESEN, 50);
 }

	else if (m_time == 864)
	{
	CObjYokoKesen* obj = new CObjYokoKesen(799.0f, 300);
	Objs::InsertObj(obj, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj2 = new CObjYokoKesen(799.0f, 277);
	Objs::InsertObj(obj2, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj3 = new CObjYokoKesen(799.0f, 244);
	Objs::InsertObj(obj3, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj4 = new CObjYokoKesen(766.0f, 300);
	Objs::InsertObj(obj4, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj5 = new CObjYokoKesen(766.0f, 277);
	Objs::InsertObj(obj5, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj1 = new CObjYokoKesen(766.0f, 244);
	Objs::InsertObj(obj1, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj6 = new CObjYokoKesen(733.0f, 300);
	Objs::InsertObj(obj6, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj7 = new CObjYokoKesen(733.0f, 277);
	Objs::InsertObj(obj7, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj8 = new CObjYokoKesen(733.0f, 244);
	Objs::InsertObj(obj8, OBJ_YOKO_KESEN, 50);
 }
	else if (m_time == 930)
	{
	CObjYokoKesen* obj = new CObjYokoKesen(799.0f, 300);
	Objs::InsertObj(obj, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj2 = new CObjYokoKesen(799.0f, 277);
	Objs::InsertObj(obj2, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj3 = new CObjYokoKesen(799.0f, 244);
	Objs::InsertObj(obj3, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj4 = new CObjYokoKesen(766.0f, 300);
	Objs::InsertObj(obj4, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj5 = new CObjYokoKesen(766.0f, 277);
	Objs::InsertObj(obj5, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj1 = new CObjYokoKesen(766.0f, 244);
	Objs::InsertObj(obj1, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj6 = new CObjYokoKesen(733.0f, 300);
	Objs::InsertObj(obj6, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj7 = new CObjYokoKesen(733.0f, 277);
	Objs::InsertObj(obj7, OBJ_YOKO_KESEN, 50);

	CObjYokoKesen* obj8 = new CObjYokoKesen(733.0f, 244);
	Objs::InsertObj(obj8, OBJ_YOKO_KESEN, 50);
 }

	else if (m_time == 1500)
	{
		//���y�`�F���W
		//Audio::Stop(0);//0�ȃX�g�b�v
		//Audio::Start(1);//1�ȖڃX�^�[�g

		CObjBoss2* obj;
		obj = new CObjBoss2(350, 150);
		Objs::InsertObj(obj, OBJ_BOSS_ENEMY2, 50);
	}
}