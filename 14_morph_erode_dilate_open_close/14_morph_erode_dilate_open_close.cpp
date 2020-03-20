// 14_morph_erode_dilate_open_close.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	//��ȡ���ص�һ��ͼƬ����ͼ���ֵ�����ֱ���и�ʴ�����͡�������ͱ�����,����ʾ����!
	cv::Mat srcMat = imread("C:/Users/lenovo/Desktop/��ͼͼƬ/coin.png");
	int height = srcMat.rows; //����
	int width = srcMat.cols; //ÿ��Ԫ�ص���Ԫ������
	for (int j = 0; j<height; j++)
	{
		for (int i = 0; i<width; i++)
		{
			//-----------------��ʼ����ÿ������-----------------
			uchar average = (srcMat.at<Vec3b>(j, i)[0] + srcMat.at<Vec3b>(j, i)[1] +
				srcMat.at<Vec3b>(j, i)[2]) / 3;
			uchar threshold = 80;
			average > threshold ? average = 255 : average = 0;
			srcMat.at<Vec3b>(j, i)[0] = srcMat.at<Vec3b>(j, i)[1] = srcMat.at<Vec3b>(j, i)[2] = average;

			//-------------�������ش���------------------------
		} //���д������
	}
	cv::Mat erode, dilate, open, close;
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
	morphologyEx(srcMat, erode,0, element, Point(-1, -1));
	morphologyEx(srcMat, dilate, 1, element, Point(-1, -1) );
	morphologyEx(srcMat, open, 2, element, Point(-1, -1));
	morphologyEx(srcMat, close, 3, element, Point(-1, -1));
	imshow("erode", erode);
	imshow("dilate", dilate);
	imshow("open", open);
	imshow("close", close);
	imshow("src", srcMat);
	//�ȴ��û�����
	waitKey(0);
	return 0;
}

