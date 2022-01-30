/**
* @file DephtCameraTest.cpp
* @Author Farih Yünsel (mrarchitect5454@gmail.com)
* @date January,2022
* @brief bu kod DephtCamera sýnýfýný test eder.
*/
#include <iostream>
#include"DepthCamera.h"
#include "Point.h"
#include "PointCloud.h"
#include<list>
using namespace std;

void DephtCameraTest()
{
	cout << "DephtCamera sinifi testi" << endl;
	cout << "-----------------------------------" << endl;
	DepthCamera DC1("camera1.txt");
	DepthCamera DC2("camera2.txt");
	PointCloud PC1;
	PointCloud PC2;
	list<Point> P1;
	list<Point> P2;
	list<Point>::iterator iter1;
	list<Point>::iterator iter2;
	PC1 = DC1.captureFor();
	PC2 = DC2.captureFor();

	P1 = PC1.GetPoints();
	P2 = PC2.GetPoints();

	for (iter1 = P1.begin(); iter1 != P1.end(); iter1++)
		cout << iter1->getX() << " " << iter1->getY() << " " << iter1->getZ() << endl;

	for (iter2 = P2.begin(); iter2 != P2.end(); iter2++)
		cout << iter2->getX() << " " << iter2->getY() << " " << iter2->getZ() << endl;


}