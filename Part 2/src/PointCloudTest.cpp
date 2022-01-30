// Emre Satilmis 10.01.2022
#include <iostream>
#include "PointCloud.h"

using namespace std;

void PointCloudTest()
{
	cout << "\nPointCloud Test" << endl;
	cout << "---------------" << endl;

	Point p1, p2, p3, p4, p5, p6, p7;
	p2.SetPoint(1, 2, 3);
	p3.SetPoint(4, 5, 6);
	p4.SetPoint(7, 8, 9);
	p5.SetPoint(10, 11, 12);
	p6.SetPoint(13, 14, 15);
	p7.SetPoint(16, 17, 18);

	PointCloud pc1, pc2;

	pc1.InsertPoints(p1);
	pc1.InsertPoints(p2);
	pc1.InsertPoints(p3);

	pc2.InsertPoints(p4);
	pc2.InsertPoints(p5);
	pc2.InsertPoints(p6);
	pc2.InsertPoints(p7);

	std::list<Point> tempPoints;
	std::list<Point>::iterator iter;

	cout << "pc1 = {";

	tempPoints = pc1.GetPoints();
	for (iter = tempPoints.begin(); iter != tempPoints.end(); iter++)
	{
		double x = 0, y = 0, z = 0;
		Point p = *iter;
		p.GetPoint(x, y, z);

		if (*iter == pc1.GetPoints().back())
			cout << "(" << x << ", " << y << ", " << z << ")}" << endl;
		else
			cout << "(" << x << ", " << y << ", " << z << "), ";
	}

	cout << "pc2 = {";

	tempPoints = pc2.GetPoints();
	for (iter = tempPoints.begin(); iter != tempPoints.end(); iter++)
	{
		double x = 0, y = 0, z = 0;
		Point p = *iter;
		p.GetPoint(x, y, z);

		if (*iter == pc2.GetPoints().back())
			cout << "(" << x << ", " << y << ", " << z << ")}" << endl;
		else
			cout << "(" << x << ", " << y << ", " << z << "), ";
	}

	PointCloud pc3;
	pc3 = pc1 + pc2;
	cout << "pc3 = pc1 + pc2 = {";

	tempPoints = pc3.GetPoints();
	for (iter = tempPoints.begin(); iter != tempPoints.end(); iter++)
	{
		double x = 0, y = 0, z = 0;
		Point p = *iter;
		p.GetPoint(x, y, z);

		if (*iter == pc3.GetPoints().back())
			cout << "(" << x << ", " << y << ", " << z << ")}" << endl;
		else
			cout << "(" << x << ", " << y << ", " << z << "), ";
	}

	pc1 = pc2;
	cout << "pc1 = pc2" << endl;
	cout << "pc1 = {";

	tempPoints = pc1.GetPoints();
	for (iter = tempPoints.begin(); iter != tempPoints.end(); iter++)
	{
		double x = 0, y = 0, z = 0;
		Point p = *iter;
		p.GetPoint(x, y, z);

		if (*iter == pc1.GetPoints().back())
			cout << "(" << x << ", " << y << ", " << z << ")}" << endl;
		else
			cout << "(" << x << ", " << y << ", " << z << "), ";
	}

	std::list<Point> testPoints;
	Point p8, p9, p10;
	p8.SetPoint(22, 33, 44);
	p9.SetPoint(55, 66, 77);
	p10.SetPoint(88, 99, 111);
	testPoints.push_back(p8);
	testPoints.push_back(p9);
	testPoints.push_back(p10);

	cout << "testPoints listesi = {";

	for (iter = testPoints.begin(); iter != testPoints.end(); iter++)
	{
		double x = 0, y = 0, z = 0;
		Point p = *iter;
		p.GetPoint(x, y, z);

		if (*iter == testPoints.back())
			cout << "(" << x << ", " << y << ", " << z << ")}" << endl;
		else
			cout << "(" << x << ", " << y << ", " << z << "), ";
	}

	pc2.SetPoints(testPoints);
	cout << "pc2'nin points listesi testPoints listesi ile set edildi." << endl;
	cout << "pc2 = {";

	tempPoints = pc2.GetPoints();
	for (iter = tempPoints.begin(); iter != tempPoints.end(); iter++)
	{
		double x = 0, y = 0, z = 0;
		Point p = *iter;
		p.GetPoint(x, y, z);

		if (*iter == pc2.GetPoints().back())
			cout << "(" << x << ", " << y << ", " << z << ")}" << endl;
		else
			cout << "(" << x << ", " << y << ", " << z << "), ";
	}
}