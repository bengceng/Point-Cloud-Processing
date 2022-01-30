// Emre Satilmis 18.12.2021
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

	PointCloud pc1(3), pc2(4);

	pc1.SetPoints(0, p1);
	pc1.SetPoints(1, p2);
	pc1.SetPoints(2, p3);

	pc2.SetPoints(0, p4);
	pc2.SetPoints(1, p5);
	pc2.SetPoints(2, p6);
	pc2.SetPoints(3, p7);

	cout << "pc1 = {";

	for (int i = 0; i < pc1.GetPointNumber(); i++)
	{
		double x = 0, y = 0, z = 0;
		Point p = pc1.GetPoints(i);
		p.GetPoint(x, y, z);

		if (i == pc1.GetPointNumber() - 1)
			cout << "(" << x << ", " << y << ", " << z << ")}" << endl;
		else
			cout << "(" << x << ", " << y << ", " << z << "), ";
	}

	cout << "pc2 = {";

	for (int i = 0; i < pc2.GetPointNumber(); i++)
	{
		double x = 0, y = 0, z = 0;
		Point p = pc2.GetPoints(i);
		p.GetPoint(x, y, z);

		if (i == pc2.GetPointNumber() - 1)
			cout << "(" << x << ", " << y << ", " << z << ")}" << endl;
		else
			cout << "(" << x << ", " << y << ", " << z << "), ";
	}

	PointCloud pc3;
	pc3 = pc1 + pc2;
	cout << "pc3 = pc1 + pc2 = {";

	for (int i = 0; i < pc3.GetPointNumber(); i++)
	{
		double x = 0, y = 0, z = 0;
		Point p = pc3.GetPoints(i);
		p.GetPoint(x, y, z);

		if (i == pc3.GetPointNumber() - 1)
			cout << "(" << x << ", " << y << ", " << z << ")}" << endl;
		else
			cout << "(" << x << ", " << y << ", " << z << "), ";
	}

	pc1 = pc2;
	cout << "pc1 = pc2" << endl;
	cout << "pc1 = {";

	for (int i = 0; i < pc1.GetPointNumber(); i++)
	{
		double x = 0, y = 0, z = 0;
		Point p = pc1.GetPoints(i);
		p.GetPoint(x, y, z);

		if (i == pc1.GetPointNumber() - 1)
			cout << "(" << x << ", " << y << ", " << z << ")}" << endl;
		else
			cout << "(" << x << ", " << y << ", " << z << "), ";
	}

	pc3.SetPointNumber(10);
	Point p8, p9, p10;
	p8.SetPoint(11, 22, 33);
	p9.SetPoint(44, 55, 66);
	p10.SetPoint(77, 88, 99);
	pc3.SetPoints(7, p8);
	pc3.SetPoints(8, p9);
	pc3.SetPoints(9, p10);

	cout << "pc3 boyutu 10 yapildi ve 3 yeni nokta eklendi." << endl;
	cout << "pc3 = {";
	for (int i = 0; i < pc3.GetPointNumber(); i++)
	{
		double x = 0, y = 0, z = 0;
		Point p = pc3.GetPoints(i);
		p.GetPoint(x, y, z);

		if (i == pc3.GetPointNumber() - 1)
			cout << "(" << x << ", " << y << ", " << z << ")}" << endl;
		else
			cout << "(" << x << ", " << y << ", " << z << "), ";
	}

	pc1.DeletePoints();
	pc2.DeletePoints();
	pc3.DeletePoints();
}