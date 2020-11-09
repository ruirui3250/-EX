#include"Kaiten.h"
#include<math.h>

void rotate(int* rx, int* ry, int x, int y, double xOffset, double yOffset, double rotation)
{
	//��Udouble�ɂ��悤(f�͕��������_)
	double xf = static_cast<double>(x);
	double yf = static_cast<double>(y);
	//�Y����������W�ɓ]��
	xf += 0.5;
	yf += 0.5;
	//���_���炵�ĉ摜���S�����S�ɂȂ�悤�ɂ���B
	xf -= xOffset;
	yf -= yOffset;
	//�R�T�C���ƃT�C�������߂�B
	double sine = sin(rotation);
	double cosine = cos(rotation);
	//��̎������̂܂ܓ��Ă͂߂�(���ꎞ�ϐ��ɓ����B)
	double tmpXf = cosine * xf - sine * yf;
	double tmpYf = sine * xf + cosine * yf;
	//���_�����ɖ߂��B
	xf += xOffset;
	yf += yOffset;
	//�Y�����ɕϊ�
	xf -= 0.5f;
	yf -= 0.5f;
	//�l�̌ܓ����Đ����ɂ��i�[�B
	*rx = round(xf);
	*ry = round(yf);
}

//���̊֐��g�p�R�[�h
//for(int y=0;y<height;++y)
//{
//for(int x=0;x<width;++x)
//{
//int rx,ry;
//rotate(&rx,&ry,x,y,2.0,2.0,45.0);
//�͈͓��̏ꍇ
//if(rx>=0&&rx<width&&ry>=0&&ry<height)
//{
//unsigned p=image->pixcel(x,y);
//dst[ry*width+rx]=p;
//}
//}
//}