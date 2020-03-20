// 14_morph_erode_dilate_open_close.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	//读取本地的一张图片，将图像二值化，分别进行腐蚀、膨胀、开运算和闭运算,并显示出来!
	cv::Mat srcMat = imread("C:/Users/lenovo/Desktop/数图图片/coin.png");
	int height = srcMat.rows; //行数
	int width = srcMat.cols; //每行元素的总元素数量
	for (int j = 0; j<height; j++)
	{
		for (int i = 0; i<width; i++)
		{
			//-----------------开始处理每个像素-----------------
			uchar average = (srcMat.at<Vec3b>(j, i)[0] + srcMat.at<Vec3b>(j, i)[1] +
				srcMat.at<Vec3b>(j, i)[2]) / 3;
			uchar threshold = 80;
			average > threshold ? average = 255 : average = 0;
			srcMat.at<Vec3b>(j, i)[0] = srcMat.at<Vec3b>(j, i)[1] = srcMat.at<Vec3b>(j, i)[2] = average;

			//-------------结束像素处理------------------------
		} //单行处理结束
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
	//等待用户按键
	waitKey(0);
	return 0;
}

