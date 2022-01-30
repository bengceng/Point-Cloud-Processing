/**
* @file PassThroughFilterTest.cpp
* @Author Muhammet Eren SÖME (erensome1@gmail.com)
* @date December, 2021
* @brief Bu kod PassThroughFilter sinifini test eder.
*/
#include"PassThroughFilter.h"
#include<iostream>
using namespace std;

//! PassThroughFilter sinifini test eden fonksiyon.
//! @see main.cpp
void PassThroughFilterTest()
{
	cout << "--------------------------" << endl;
	cout << "|Pass Through Filter Test|" << endl;
	cout << "--------------------------" << endl;

	//Degerli set et.
	PassThroughFilter ptf1;
	ptf1.setLLX(0); // X 0'in altýndaysa çýkar
	ptf1.setULX(6); // X 6'nin üstündeyse çýkar
	ptf1.setLLY(1); // Y 1'in üstündeyse çýkar
	ptf1.setULY(4); // Y 4'un üstündeyse çýkar
	ptf1.setLLZ(2); // Z 2'nýn üstündeyse çýkar
	ptf1.setULZ(7); // Z 7'nýn üstündeyse çýkar

	cout << "Lower Limit for (X,Y,Z) = (" << ptf1.getLLX() << ", " << ptf1.getLLY() << ", " << ptf1.getLLZ() << ")" << endl;
	cout << "Upper Limit for (X,Y,Z) = (" << ptf1.getULX() << ", " << ptf1.getULY() << ", " << ptf1.getULZ() << ")" << endl << endl;
	//0,1,2
	//6,4,7
	
	//Pointleri olustur.
	Point p1, p2, p3, p4, p5, p6, p7;
	p1.SetPoint(0, 4, 5);
	p2.SetPoint(8, 3, 5); // X uymuyor.
	p3.SetPoint(4, 0, 9); // Y ve Z uymuyor.
	p4.SetPoint(7, 5, 1); // X, Y ve Z uymuyor.
	p5.SetPoint(5.35, -1, 3.12); // Y uymuyor.
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
	ptf1.filter(pc);

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