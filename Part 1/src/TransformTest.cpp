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
	Point p, pp, a;

	p.SetPoint(150, 150, -50);
	a.SetPoint(2, 5, -1);
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

	PointCloud pc, B;
	pc.SetPointNumber(2);
	pc.SetPoints(0, p);
	pc.SetPoints(1, a);
	Point b;
	B = T.doTransform(pc);
	cout << "The Values of the Points of the Point Cloud After Transformation" << endl;
	cout << "---------------------------" << endl;

	for (int k = 0; k < 2; k++) {

		b = B.GetPoints(k);
		cout << "Point " << k << endl;
		cout << "X:" << b.getX() << endl << "Y:" << b.getY() << endl << "Z:" << b.getZ() << endl << endl;;
	}
	B.DeletePoints();
	pc.DeletePoints();
	
}