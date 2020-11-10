#include"Kaiten.h"
#include<math.h>

void rotate(int* rx, int* ry, int x, int y, double xOffset, double yOffset, double rotation)
{
	//一旦doubleにしよう(fは浮動小数点)
	double xf = static_cast<double>(x);
	double yf = static_cast<double>(y);
	//添え字から座標に転換
	xf += 0.5;
	yf += 0.5;
	//原点ずらして画像中心が中心になるようにする。
	xf -= xOffset;
	yf -= yOffset;
	//コサインとサインを求める。
	double sine = sin(rotation);
	double cosine = cos(rotation);
	//上の式をそのまま当てはめる(一回一時変数に入れる。)
	double tmpXf = cosine * xf - sine * yf;
	double tmpYf = sine * xf + cosine * yf;
	//原点を元に戻す。
	xf += xOffset;
	yf += yOffset;
	//添え字に変換
	xf -= 0.5f;
	yf -= 0.5f;
	//四捨五入して整数にし格納。
	*rx = round(xf);
	*ry = round(yf);
}

//この関数使用コード
//for(int y=0;y<height;++y)
//{
//for(int x=0;x<width;++x)
//{
//int rx,ry;
//rotate(&rx,&ry,x,y,2.0,2.0,45.0);
//範囲内の場合
//if(rx>=0&&rx<width&&ry>=0&&ry<height)
//{
//unsigned p=image->pixcel(x,y);
//dst[ry*width+rx]=p;
//}
//}
//}