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
#include"SceneMain5.h"
#include"GameHead.h"
//�R���X�g���N�^
CSceneMain5::CSceneMain5()
{

}
//�f�X�g���N�^
CSceneMain5::~CSceneMain5()
{

}

//�Q�[�����C�����������\�b�h
void CSceneMain5::InitScene()
{
	//�O���O���t�B�b�N�ǂݍ���0��  �w�i
	Draw::LoadImage(L"�w�i(�g).png", 9, TEX_SIZE_512);

	Draw::LoadImage(L"�E�C���X��.png", 3, TEX_SIZE_512);

	/*Draw::LoadImage(L"�E�C���X.png", 7, TEX_SIZE_512);*/

	Draw::LoadImage(L"�G�e(�g).png", 5, TEX_SIZE_512);

	Draw::LoadImage(L"���ˊ�.png", 0, TEX_SIZE_512);

	Draw::LoadImage(L"�J�v�Z��.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"��l���e�c.png", 11, TEX_SIZE_512);

	//Draw::LoadImage(L"��Q��.png",9, TEX_SIZE_512);
	Draw::LoadImage(L"���[�U�[.png", 10, TEX_SIZE_512);

	Draw::LoadImage(L"���[�U�[�c.png", 12, TEX_SIZE_512);

	Draw::LoadImage(L"�g�U�e��.png", 6, TEX_SIZE_512);
	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^ �{�X�O���t�B�b�N��o�^
	Draw::LoadImage(L"�{�X�T.png", 4, TEX_SIZE_512);

	Draw::LoadImage(L"��Q��.png", 29, TEX_SIZE_512);

	Draw::LoadImage(L"���C�t��.png", 31, TEX_SIZE_512);

	Draw::LoadImage(L"�{�X�G�t�F�N�g.png", 8, TEX_SIZE_512);

	Draw::LoadImage(L"BOSSYAZIRUSI.png", 33, TEX_SIZE_512);

	Draw::LoadImage(L"�G�i�W�[�`���[�W.png", 32, TEX_SIZE_512);
	//���y�ǂݍ���
	Audio::LoadAudio(2, L"�e1.wav", EFFECT);

	//���y�ǂݍ���
	Audio::LoadAudio(4, L"���[�U�[.wav", EFFECT);

	//���y�ǂݍ���
	Audio::LoadAudio(5, L"�g�U�e.wav", EFFECT);

	//���y�ǂݍ���
	Audio::LoadAudio(18, L"�G���S.wav", EFFECT);

	//���y�ǂݍ���
	Audio::LoadAudio(10, L"5��.wav", BACK_MUSIC);

	//���y�ǂݍ���
	Audio::LoadAudio(15, L"�{�X5.wav", BACK_MUSIC);

	//�A�C�e����BGM
	Audio::LoadAudio(19, L"HP.wav", EFFECT);

	Audio::LoadAudio(20, L"LK.wav", EFFECT);

	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((0.8 - v));

	//��l���I�u�W�F�N�g�쐬
	CObjHero5* obj = new CObjHero5();//��l���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_HERO, 10);//��l���I�u�W�F�N�g�}�l�[�W���[��o�^

	////block�I�u�W�F�N�g�쐬
	//CObjBlock* objb = new CObjBlock();
	//Objs::InsertObj(objb, OBJ_BLOCK, 9);

		//�w�i�I�u�W�F�N�g�쐬
	CObjSceneMain5* back = new CObjSceneMain5();
	Objs::InsertObj(back, OBJ_SCENE_MAIN5, 9);

	//�^�C��������
	m_time = 0;

	Audio::Start(10);

}

//�Q�[���V�[�����s�����\�b�h
void CSceneMain5::Scene()
{
	m_time++;
	////�A�C�e���z�u
	//if (m_time == 500)
	//{
	//	CObjMigiLifeItem* obj = new CObjMigiLifeItem(799.0f, 600);
	//	Objs::InsertObj(obj, OBJ_ITEM, 50);
	//}
	//if (m_time == 700)
	//{
	//	CObjHidariLifeItem* obj = new CObjHidariLifeItem(500.0f, 1);
	//	Objs::InsertObj(obj, OBJ_ITEM, 50);
	//}
	//if (m_time == 1000)
	//{
	//	CObjSitaLifeItem* obj = new CObjSitaLifeItem(1.0f, 300);
	//	Objs::InsertObj(obj, OBJ_ITEM, 50);
	//}
	//if (m_time == 1400)
	//{
	//	CObjItem* obj = new CObjItem(250.0f, 1);
	//	Objs::InsertObj(obj, OBJ_ITEM, 50);
	//}

	//if (m_time == 30)
	//{
	//	CObjEnemy2* obj = new CObjEnemy2(799.0f, 400);
	//	Objs::InsertObj(obj, OBJ_ENEMY2, 50);

	//	CObjAttackEnemy2* obj2;
	//	obj2 = new CObjAttackEnemy2(799, 330);
	//	Objs::InsertObj(obj2, OBJ_ATTACK_ENEMY2, 50);

	//	CObjEnemy2* obj3 = new CObjEnemy2(650.0f, 130);
	//	Objs::InsertObj(obj3, OBJ_ENEMY2, 50);

	//	CObjEnemy2* obj4 = new CObjEnemy2(799.0f, 160);
	//	Objs::InsertObj(obj4, OBJ_ENEMY2, 50);

	//}
	//else if (m_time == 40)
	//{
	//	//block object create
	//	CObjYokoKesen* obj = new CObjYokoKesen(799.0f, 0);
	//	Objs::InsertObj(obj, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj1 = new CObjYokoKesen(766, 0);
	//	Objs::InsertObj(obj1, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj2 = new CObjYokoKesen(733, 0);
	//	Objs::InsertObj(obj2, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj3 = new CObjYokoKesen(799.0f, 33);
	//	Objs::InsertObj(obj3, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj4 = new CObjYokoKesen(766, 33);
	//	Objs::InsertObj(obj4, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj5 = new CObjYokoKesen(733, 33);
	//	Objs::InsertObj(obj5, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj6 = new CObjYokoKesen(799.0f, 66);
	//	Objs::InsertObj(obj6, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj7 = new CObjYokoKesen(766, 66);
	//	Objs::InsertObj(obj7, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj8 = new CObjYokoKesen(733, 66);
	//	Objs::InsertObj(obj8, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj9 = new CObjYokoKesen(733, 566);
	//	Objs::InsertObj(obj9, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj10 = new CObjYokoKesen(766, 566);
	//	Objs::InsertObj(obj10, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj11 = new CObjYokoKesen(799.0f, 566);
	//	Objs::InsertObj(obj11, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj12 = new CObjYokoKesen(733, 533);
	//	Objs::InsertObj(obj12, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj13 = new CObjYokoKesen(766, 533);
	//	Objs::InsertObj(obj13, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj14 = new CObjYokoKesen(799.0f, 533);
	//	Objs::InsertObj(obj14, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj15 = new CObjYokoKesen(733, 500);
	//	Objs::InsertObj(obj15, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj16 = new CObjYokoKesen(766, 500);
	//	Objs::InsertObj(obj16, OBJ_YOKO_KESEN, 50);

	//	CObjYokoKesen* obj17 = new CObjYokoKesen(799.0f, 500);
	//	Objs::InsertObj(obj17, OBJ_YOKO_KESEN, 50);
	//}

	//else if (m_time == 300)
	//{
	//	CObjTateEnemy2* obj = new CObjTateEnemy2(10.0f, 1);
	//	Objs::InsertObj(obj, OBJ_TATE_ENEMY2, 50);

	//	CObjTateEnemy2* obj2 = new CObjTateEnemy2(70.0f, 1);
	//	Objs::InsertObj(obj2, OBJ_TATE_ENEMY2, 50);

	//	CObjTateEnemy2* obj3 = new CObjTateEnemy2(120.0f, 1);
	//	Objs::InsertObj(obj3, OBJ_TATE_ENEMY2, 50);

	//	CObjTateEnemy2* obj4 = new CObjTateEnemy2(170.0f, 1);
	//	Objs::InsertObj(obj4, OBJ_TATE_ENEMY2, 50);

	//	CObjTateEnemy2* obj5 = new CObjTateEnemy2(190.0f, 1);
	//	Objs::InsertObj(obj5, OBJ_TATE_ENEMY2, 50);
	//}

	//else if (m_time == 400)
	//{
	//	//block object create
	//	CObjEnemy2* obj = new CObjEnemy2(799.0f, 400);
	//	Objs::InsertObj(obj, OBJ_ENEMY2, 50);

	//	CObjEnemy2* obj2 = new CObjEnemy2(799.0f, 350);
	//	Objs::InsertObj(obj2, OBJ_ENEMY2, 50);

	//	CObjTateKesen* obj3 = new CObjTateKesen(10, -1);
	//	Objs::InsertObj(obj3, OBJ_TATEKESEN, 50);

	//	CObjSitaKesen* obj4 = new CObjSitaKesen(70, 550);
	//	Objs::InsertObj(obj4, OBJ_SITA_KESEN, 50);

	//	CObjTateKesen* obj5 = new CObjTateKesen(130, -1);
	//	Objs::InsertObj(obj5, OBJ_TATEKESEN, 50);

	//	CObjSitaKesen* obj6 = new CObjSitaKesen(180, 550);
	//	Objs::InsertObj(obj6, OBJ_SITA_KESEN, 50);

	//	CObjTateKesen* obj7 = new CObjTateKesen(230, -1);
	//	Objs::InsertObj(obj7, OBJ_TATEKESEN, 50);

	//	
	//}
	//else if (m_time == 450)
	//{
	//	CObjEnemy2* obj;
	//	obj = new CObjEnemy2(799.0f, 300);
	//	Objs::InsertObj(obj, OBJ_ENEMY2, 50);
	//	obj = new CObjEnemy2(799.0f, 350);
	//	Objs::InsertObj(obj, OBJ_ENEMY2, 50);
	//	obj = new CObjEnemy2(799.0f, 250);
	//	Objs::InsertObj(obj, OBJ_ENEMY2, 50);

	//	CObjAttackEnemy2* obj2;
	//	obj2 = new CObjAttackEnemy2(799.0f, 200);
	//	Objs::InsertObj(obj2, OBJ_ATTACK_ENEMY2, 50);
	//	obj2 = new CObjAttackEnemy2(799.0f, 400);
	//	Objs::InsertObj(obj2, OBJ_ATTACK_ENEMY2, 50);

	//}

	//else if (m_time == 550)
	//{
	//CObjEnemy2* obj = new CObjEnemy2(799.0f, 400);
	//Objs::InsertObj(obj, OBJ_ENEMY2, 50);

	//CObjTateEnemy2* obj3 = new CObjTateEnemy2(10.0f, 30);
	//Objs::InsertObj(obj3, OBJ_TATE_ENEMY2, 50);

	//CObjSitaEnemy2* obj4 = new CObjSitaEnemy2(10.0f, 500);
	//Objs::InsertObj(obj4, OBJ_SITA_ENEMY2, 50);

	//CObjTateEnemy2* obj5 = new CObjTateEnemy2(70.0f, 500);
	//Objs::InsertObj(obj5, OBJ_TATE_ENEMY2, 50);

	//CObjSitaEnemy2* obj6 = new CObjSitaEnemy2(70.0f, 500);
	//Objs::InsertObj(obj6, OBJ_SITA_ENEMY2, 50);
	//}

	//else if (m_time == 800)
	//{
	//CObjEnemy2* obj = new CObjEnemy2(550.0f, 400);
	//Objs::InsertObj(obj, OBJ_ENEMY2, 50);

	//CObjEnemy2* obj2 = new CObjEnemy2(550.0f, 400);
	//Objs::InsertObj(obj2, OBJ_ENEMY2, 50);

	//CObjSitaEnemy2* obj3 = new CObjSitaEnemy2(550.0f, 400);
	//Objs::InsertObj(obj3, OBJ_SITA_ENEMY2, 50);

	//CObjTateKesen* obj6 = new CObjTateKesen(280, -1);
	//Objs::InsertObj(obj6, OBJ_TATEKESEN, 50);

	//CObjSitaKesen* obj7 = new CObjSitaKesen(330, 550);
	//Objs::InsertObj(obj7, OBJ_SITA_KESEN, 50);

	//CObjTateKesen* obj8 = new CObjTateKesen(380, -1);
	//Objs::InsertObj(obj8, OBJ_TATEKESEN, 50);

	//CObjSitaKesen* obj4 = new CObjSitaKesen(430, 550);
	//Objs::InsertObj(obj4, OBJ_SITA_KESEN, 50);

	//CObjTateKesen* obj5 = new CObjTateKesen(480, -1);
	//Objs::InsertObj(obj5, OBJ_TATEKESEN, 50);
	//

	//}
	//else if (m_time == 1000)
	//{
	//CObjTateKesen* obj = new CObjTateKesen(10, -1);
	//Objs::InsertObj(obj, OBJ_TATEKESEN, 50);

	//CObjSitaKesen* obj2 = new CObjSitaKesen(70, 550);
	//Objs::InsertObj(obj2, OBJ_SITA_KESEN, 50);

	//CObjTateKesen* obj3 = new CObjTateKesen(130, -1);
	//Objs::InsertObj(obj3, OBJ_TATEKESEN, 50);

	//CObjSitaKesen* obj4 = new CObjSitaKesen(180, 550);
	//Objs::InsertObj(obj4, OBJ_SITA_KESEN, 50);

	//CObjTateKesen* obj5 = new CObjTateKesen(230, -1);
	//Objs::InsertObj(obj5, OBJ_TATEKESEN, 50);
	//}

	//else if (m_time == 1200)
	//{
	//CObjTateKesen* obj = new CObjTateKesen(280, -1);
	//Objs::InsertObj(obj, OBJ_TATEKESEN, 50);

	//CObjSitaKesen* obj2 = new CObjSitaKesen(330, 501);
	//Objs::InsertObj(obj2, OBJ_SITA_KESEN, 50);

	//CObjTateKesen* obj3 = new CObjTateKesen(380, -1);
	//Objs::InsertObj(obj3, OBJ_TATEKESEN, 50);

	//CObjSitaKesen* obj4 = new CObjSitaKesen(430, 501);
	//Objs::InsertObj(obj4, OBJ_SITA_KESEN, 50);
 //}

	//else if (m_time == 1500)
	//{
	//ObjBossEffect* obj;
	//obj = new  ObjBossEffect(733.0f, 177);
	//Objs::InsertObj(obj, OBJ_BOSS_EFFECT, 50);
	//}
	//if (m_time == 1600)
	//{
	//	ObjBossYazirusi5* obj;
	//	obj = new ObjBossYazirusi5(50, 100);
	//	Objs::InsertObj(obj, OBJ_BOSS_YAZIRUSI5, 50);
	//}

	/*else*/ 
		if (m_time == 20)
	{
		//���y�`�F���W
		Audio::Stop(10);//0�ȃX�g�b�v
		Audio::Start(15);//1�ȖڃX�^�[�g

		CObjMIXBoss* obj;
		obj = new CObjMIXBoss(450, 250);
		Objs::InsertObj(obj, OBJ_MIX_BOSS, 50);

		CObjTateKesen* obj2 = new CObjTateKesen(150, 10);
		Objs::InsertObj(obj2, OBJ_TATEKESEN, 50);

		CObjTateKesen* obj3 = new CObjTateKesen(200, 50);
		Objs::InsertObj(obj3, OBJ_TATEKESEN, 50);

		CObjTateKesen* obj5 = new CObjTateKesen(250, 100);
		Objs::InsertObj(obj5, OBJ_TATEKESEN, 50);

		CObjTateKesen* obj6 = new CObjTateKesen(300, 300);
		Objs::InsertObj(obj6, OBJ_TATEKESEN, 50);

		CObjTateKesen* obj7 = new CObjTateKesen(350, 200);
		Objs::InsertObj(obj7, OBJ_TATEKESEN, 50);

		/*CObjEnemyBossBullet4* obj8 = new CObjEnemyBossBullet4(800.0f, 500);
		Objs::InsertObj(obj8, OBJ_BOSS_BULLET_ENEMY, 50);*/


	}
}