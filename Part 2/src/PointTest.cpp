// Emre Satilmis 16.12.2021
#include <iostream>
#include "Point.h"

using namespace std;

void PointTest()
{
	cout << "Point Test" << endl;
	cout << "----------" << endl;

	Point p1, p2, p3, p4;
	p2.SetPoint(5, 3, 0);
	p3.SetPoint(5, 3, 0);
	p4.SetPoint(8, 11, 4);

	double x = 0, y = 0, z = 0;
	p1.GetPoint(x, y, z);
	cout << "p1: (" << x << ", " << y << ", " << z << ")" << endl;
	p2.GetPoint(x, y, z);
	cout << "p2: (" << x << ", " << y << ", " << z << ")" << endl;

	if (p1 == p2)
		cout << "p1 = p2" << endl;
	else
		cout << "p1 != p2" << endl;

	cout << "p1 ve p2 arasindaki uzaklik: " << p1.distance(p2) << endl;

	p3.GetPoint(x, y, z);
	cout << "p3: (" << x << ", " << y << ", " << z << ")" << endl;

	if (p2 == p3)
		cout << "p2 = p3" << endl;
	else
		cout << "p2 != p3" << endl;

	cout << "p2 ve p3 arasindaki uzaklik: " << p2.distance(p3) << endl;

	p4.GetPoint(x, y, z);
	cout << "p4: (" << x << ", " << y << ", " << z << ")" << endl;

	if (p3 == p4)
		cout << "p3 = p4" << endl;
	else
		cout << "p3 != p4" << endl;

	cout << "p3 ve p4 arasindaki uzaklik: " << p3.distance(p4) << endl;
	cout << "p4'un z degeri = " << p4.getZ() << endl;
}