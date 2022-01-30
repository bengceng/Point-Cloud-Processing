/**
* @file FilterPipeTest.cpp
* @Author Muhammet Eren SÖME (erensome1@gmail.com)
* @date January, 2022
* @brief Bu kod FilterPipe sinifini test eder.
*/
#include "FilterPipe.h"
#include "PassThroughFilter.h"
#include "RadiusOutlierFilter.h"
#include<iostream>

using namespace std;

//! FilterPipe sinifini test eden fonksiyon.
//! @see main.cpp
void FilterPipeTest()
{
	/*PTF.setLLX(1);
	PTF.setULX(10);
	PTF.setLLY(0);
	PTF.setULY(9);
	PTF.setLLZ(3);
	PTF.setULZ(18);*/
	cout << "------------------" << endl;
	cout << "|Filter Pipe Test|" << " Radius: 10, LLX: 1, ULX: 10, LLY: 0, ULY: 9, LLZ: 3, ULZ: 18 " << endl;
	cout << "------------------" << endl;

	int flag = 1;

	Point p1, p2, p3, p4, p5;
	p1.SetPoint(1, 2, 3); // normal
	p2.SetPoint(0, 3, 3); //lowerXten elensin
	p3.SetPoint(3, 10, 3); //upperYden elensin
	p4.SetPoint(3, 3, 2); //lowerZden elensin
	p5.SetPoint(10, 9, 18); //radiustan elensin

	PointCloud pc;
	pc.InsertPoints(p1);
	pc.InsertPoints(p2);
	pc.InsertPoints(p3);
	pc.InsertPoints(p4);
	pc.InsertPoints(p5);

	cout << "Before Filter Pipe Test" << endl;
	list<Point>firstList = pc.GetPoints();
	list<Point>::iterator firstIt;

	for (firstIt = firstList.begin(); firstIt != firstList.end(); firstIt++)
	{
		cout << flag++ << ".Point(X,Y,Z) = (" << firstIt->getX() << "," << firstIt->getY() << "," << firstIt->getZ() << ")" << endl;
	}

	FilterPipe FP;
	PassThroughFilter PTF;
	RadiusOutlierFilter ROF;

	PTF.setLLX(1);
	PTF.setULX(10);
	PTF.setLLY(0);
	PTF.setULY(9);
	PTF.setLLZ(3);
	PTF.setULZ(18);

	ROF.setRadius(10);

	FP.addFilter(&ROF);  //First RadiusOutlier filter.
	FP.addFilter(&PTF);  //Then PassThrough filter.
	
	FP.filterOut(pc);

	list<Point> lastList = pc.GetPoints();
	list<Point>::iterator lastIt;

	flag = 1;
	cout << "After Filter Pipe Test" << endl;
	for (lastIt = lastList.begin(); lastIt != lastList.end(); lastIt++)
	{
		cout << flag++ << ".Point(X,Y,Z) = (" << lastIt->getX() << "," << lastIt->getY() << "," << lastIt->getZ() << ")" << endl;
	}
}