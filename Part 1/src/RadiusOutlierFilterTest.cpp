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
	PointCloud pc(7);
	pc.SetPoints(0, p1);
	pc.SetPoints(1, p2);
	pc.SetPoints(2, p3);
	pc.SetPoints(3, p4);
	pc.SetPoints(4, p5);
	pc.SetPoints(5, p6);
	pc.SetPoints(6, p7);

	//Filtreleme isleminden once PointCloud icindeki Point uye sayisini ve Pointleri yazdir.
	int no;
	no = pc.GetPointNumber();
	cout << "Number of points before filtering: " << no << endl;
	Point temp;
	for (int i = 0; i < no; i++)
	{
		temp = pc.GetPoints(i);
		cout << i << ".Element's points: (X,Y,Z) = (" << temp.getX() << ", " << temp.getY() << ", " << temp.getZ() << ")" << endl;
	}
	cout << endl;

	//Filtreleme islemi.
	rof.filter(pc);

	//Filtreleme isleminden sonra PointCloud icindeki Point uye sayisini ve Pointleri yazdir.
	no = pc.GetPointNumber();
	cout << "Number of points after filtering: " << no << endl;
	for (int i = 0; i < no; i++)
	{
		temp = pc.GetPoints(i);
		cout << i << ".Element's points: (X,Y,Z) = (" << temp.getX() << ", " << temp.getY() << ", " << temp.getZ() << ")" << endl;
	}
	cout << endl;
}