/**
* @file  : TransformTest.cpp
* @Author: Bengisu Sahin (sahin.bengisu00@gmail.com)
* @date  : 11.01.2022
* @brief : Transform sinifini test eder.
*/

#include<iostream>
#include<iomanip>
#include "Transform.h"
#include "Point.h"
#include "PointCloud.h"

using namespace std;

void TransformTest()
{
	Transform T;
	T.set_angles(0, 0, -90.0);
	T.set_trans(100, 500, 50);
	Point p, pp, a, list_point;
	PointCloud pc, tst;

	p.SetPoint(150, 150, -50);
	a.SetPoint(2, 5, 1);
	double *ang, *tr;
	ang = T.get_angles();
	tr = T.get_trans();
	cout << "ANGLES" << endl;;
	cout << "---------------------------" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "angle " << i + 1 << ":"
			<< *(ang + i) << endl;
	}
	cout << "---------------------------" << endl;
	cout << "TRANS" << endl;
	cout << "---------------------------" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "value " << i + 1 << ":"
			<< *(tr + i) << endl;
	}
	cout << "---------------------------" << endl;

	T.setRotation(T.get_angles());
	cout << "ROTATION MATRIX" << endl;
	cout << "---------------------------" << endl;
	T.display_rotation();
	cout << "---------------------------" << endl;
	cout << "TRANSLATION MATRIX" << endl;
	cout << "---------------------------" << endl;
	T.setTranslation(T.get_trans());
	T.display_translation();
	cout << "---------------------------" << endl;
	pp = T.doTransform(p);
	cout << "New Values of Point p After Transformation" << endl
		<< "---------------------------" << endl
		<< endl << "X:" << pp.getX() << endl << "Y:" << pp.getY() << endl << "Z:" << pp.getZ() << endl;
	cout << "---------------------------" << endl;

	list<Point>test, lp;
	list<Point>::iterator it;
	pc.InsertPoints(p);
	pc.InsertPoints(a);
	tst = T.doTransform(pc);
	lp = tst.GetPoints();
	int k = 1;
	cout << "The Values of the Points of the Point Cloud After Transformation" << endl;
	cout << "---------------------------" << endl;
	for (it = lp.begin(); it != lp.end(); ++it) {
		list_point = *it;
		cout << "Point " << k << endl;
		cout << "X:" << list_point.getX() << endl << "Y:"
			<< list_point.getY() << endl << "Z:" << list_point.getZ() << endl << endl;
		k++;
	}
}