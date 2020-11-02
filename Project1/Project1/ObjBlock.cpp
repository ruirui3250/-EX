//使用するヘッダーファイル(リソース)
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameHead.h"

//使用するヘッダーファイル（作成物）
#include "ObjBlock.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBlock::Init()
{
	//マップ情報
	int block_data[10][10] =
	{
		{0,0,0,0,0,0,1,1,1,0},
		{0,0,0,0,0,0,1,1,1,0},
		{0,0,0,0,0,0,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,0},
		{0,0,0,0,0,0,1,1,1,0},
		{0,0,0,0,0,0,1,1,1,0},
	};
	//マップデータをコピー
	memcpy(m_map, block_data, sizeof(int) * (10 * 10));
}
//アクション
void CObjBlock::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//m_mapの全要素のアクセス。
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (m_map[i][j] > 0)
			{
				//要素番号を座標に変更
				float x = j * 64.0f;
				float y = i * 64.0f;

				//ブロックの当たり判定
				if ((hx+64.0f>x)&&(hx<x+64.0f)&&(hy+64.0f>y)&&(hy<y+64.0f))
				{
					//上下左右判定
					float vx = hx - x;
					float vy = hy - y;

					//長さを求める
					float len = sqrt(vx * vx + vy * vy);

					//角度を求める
					float r = atan2(vy, vx);
					r = r * 180.0f/3.14f;

					if (r <= 0.0)
						//続きはここ
						r = abs(r);
					else
						r = 360.0f - abs(r);
					//角度が当たっている場合
					if (45 && r > 0 || r > 315)
					{
						//右
					}
					if (r > 45 && r < 135)
					{
						//上
						hero->SetY(y - 64.0f);//blockの位置 主人公の幅
					}
					if (r > 225 && r < 315)
					{
						//下
					}




					//当たっている場合
					hero->SetX(hx);
					hero->SetY(0.0f);
				}
			}
		}
	}
}
//ドロー
void CObjBlock::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画先切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (m_map[i][j] > 0)
			{
				//表示位置の設定
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;
				//描画
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
		}
	}

}