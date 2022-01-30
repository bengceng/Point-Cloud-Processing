/**
* @file RadiusOutlierFilter.cpp
* @Author Muhammet Eren SÖME (erensome1@gmail.com)
* @date December, 2021
* @brief Bu dosya RadiusOutlierFilter sinifinin fonksiyonlarinin isleyisini icerir.
*/
#include "RadiusOutlierFilter.h"
#include<iostream>
#include<list>
#include<iterator>

using namespace std;
RadiusOutlierFilter::RadiusOutlierFilter()
{
	this->radius = 25;
}
RadiusOutlierFilter::~RadiusOutlierFilter()
{

}

/**
* @param radius yaricap degerini belirtir.
*/
void RadiusOutlierFilter::setRadius(double radius)
{
	this->radius = radius;
}

/**
* @return yaricap degeri.
*/
double RadiusOutlierFilter::getRadius() const
{
	return this->radius;
}

/**
* @brief Bu fonksiyon nokta bulutunu alir ve nokta bulutunu filtereler. Filtreleme islemi su sekildedir:
Nokta bulutundaki her bir nokta icin tek tek islem yapilir. Noktaya, radius degerinden daha yakin baska bir nokta yok ise, bu nokta nokta bulutundan cikarilir.
* @param pc referans olarak atanmistir.
*/
void RadiusOutlierFilter::filter(PointCloud& pc)
{
	list<Point> oldPC, newPC;
	oldPC = pc.GetPoints();
	list<Point>::iterator it,it2;

	double distance;
	for (it = oldPC.begin(); it != oldPC.end(); it++)
	{
		for (it2 = oldPC.begin(); it2 != oldPC.end(); it2++)
		{
			distance = it->distance(*it2);
			if (distance < radius && it != it2) // yaricaptan daha yakini var ekle.
			{
				newPC.push_back(*it);
				break;
			}
		}
	}
	pc.SetPoints(newPC);
}