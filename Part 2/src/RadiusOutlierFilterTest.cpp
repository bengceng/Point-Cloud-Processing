/**
* @file RadiusOutlierFilterTest.cpp
* @Author Muhammet Eren SÖME (erensome1@gmail.com)
* @date December, 2021
* @brief Bu kod RadiusOutlierFilter sinifini test eder.
*/
#include"RadiusOutlierFilter.h"
#include<iostream>
using namespace std;

//! RadiusOutlierFilter sinifini test eden fonksiyon.
//! @see main.cpp
void RadiusOutlierFilterTest()
{
	RadiusOutlierFilter rof;
	cout << "-----------------------------" << endl;
	cout << "|Radius Outlier Filter Test|  [Radius value is "<< rof.getRadius()<<"]" << endl;
	cout << "-----------------------------" << endl;
	
	//Pointleri olustur.
	Point p1, p2, p3, p4, p5, p6, p7;
	p1.SetPoint(0, 0, 0);
	p2.SetPoint(50, 50, 50); // X uymuyor.
	p3.SetPoint(10, 10, 10); // Y ve Z uymuyor.
	p4.SetPoint(7, 5, 1); // X, Y ve Z uymuyor.
	p5.SetPoint(200, 100, 500); // Y uymuyor.
	p6.SetPoint(6, 2, -5.32); // Z uymuyor.
	p7.SetPoint(5, 3, 6.78);

	//Pointleri PointCloud icine koy.
	PointCloud pc;
	pc.InsertPoints(p1);
	pc.InsertPoints(p2);
	pc.InsertPoints(p3);
	pc.InsertPoints(p4);
	pc.InsertPoints(p5);
	pc.InsertPoints(p6);
	pc.InsertPoints(p7);
	

	//Filtreleme isleminden once PointCloud icindeki Point uye sayisini ve Pointleri yazdir.
	list<Point>::iterator it;
	list<Point> listOfPC;
	listOfPC = pc.GetPoints();
	
	cout << "Number of points before filtering: " << pc.GetPointNumber() << endl;
	for (it = listOfPC.begin(); it!= listOfPC.end(); it++)
	{
		cout << "Element's points: (X,Y,Z) = (" << it->getX() << ", " << it->getY() << ", " << it->getZ() << ")" << endl;
	}
	cout << endl;

	//Filtreleme islemi.
	rof.filter(pc);

	//Filtreleme isleminden sonra PointCloud icindeki Point uye sayisini ve Pointleri yazdir.
	listOfPC = pc.GetPoints();

	cout << "Number of points after filtering: " << pc.GetPointNumber() << endl;
	for (it = listOfPC.begin(); it != listOfPC.end(); it++)
	{
		cout << "Element's points: (X,Y,Z) = (" << it->getX() << ", " << it->getY() << ", " << it->getZ() << ")" << endl;
	}
	cout << endl;
}