/**
 * @file RadiusOutlierFilter.cpp
 * @Author Muhammet Eren SÖME (erensome1@gmail.com)
 * @date December, 2021
 */
#include "RadiusOutlierFilter.h"
#include<iostream>
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
	Point temp;
	Point comp;
	int flag = 0;
	bool isClose;
	int i, j, k;
	for (i = 0; i < pc.GetPointNumber(); i++)
	{
		isClose = false;
		temp = pc.GetPoints(i);
		for (j = 0; j < pc.GetPointNumber(); j++)
		{
			comp = pc.GetPoints(j);
			double distance = temp.distance(comp);
			if (distance < radius && i != j)
			{
				isClose = true;
				break;
			}
		}
		if (!isClose)
		{
			for (k = i;  k > 0;  k--)
			{
				pc.SetPoints(k, pc.GetPoints(k - 1));
				pc.GetPoints(k);
			}
			flag++;
		}
	}

	int pointNo = pc.GetPointNumber();
	PointCloud newPC(pointNo - flag);

	for (int x = 0; x < newPC.GetPointNumber(); x++)
	{
		newPC.SetPoints(x, pc.GetPoints(x+flag));
	}

	pc = newPC;
	newPC.DeletePoints();
}