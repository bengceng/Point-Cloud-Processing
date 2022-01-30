/**
 * @file PassThroughFilter.cpp
 * @Author Muhammet Eren SÖME (erensome1@gmail.com)
 * @date December, 2021
 */
#include "PassThroughFilter.h"
#include<iostream>
PassThroughFilter::PassThroughFilter()
{

}
PassThroughFilter::~PassThroughFilter()
{

}

/**
* @param x Atanmak istenen deger.
*/
void PassThroughFilter::setULX(double x) {
	upperLimitX = x;
}

/**
* @param x Atanmak istenen deger.
*/
void PassThroughFilter::setLLX(double x) {
	lowerLimitX = x;
}

/**
* @param y Atanmak istenen deger.
*/
void PassThroughFilter::setULY(double y) {
	upperLimitY = y;
}

/**
* @param y Atanmak istenen deger.
*/
void PassThroughFilter::setLLY(double y) {
	lowerLimitY = y;
}

/**
* @param z Atanmak istenen deger.
*/
void PassThroughFilter::setULZ(double z) {
	upperLimitZ = z;
}

/**
* @param z Atanmak istenen deger.
*/
void PassThroughFilter::setLLZ(double z) {
	lowerLimitZ = z;
}

/**
* @return Upper Limit X degeri
*/
double PassThroughFilter::getULX() const {
	return this->upperLimitX;
}

/**
* @return Upper Limit X degeri
*/
double PassThroughFilter::getLLX() const {
	return this->lowerLimitX;
}

/**
* @return Upper Limit Y degeri
*/
double PassThroughFilter::getULY() const {
	return this->upperLimitY;
}

/**
* @return Lower Limit Y degeri
*/
double PassThroughFilter::getLLY() const {
	return this->lowerLimitY;
}

/**
* @return Upper Limit Z degeri
*/
double PassThroughFilter::getULZ() const {
	return this->upperLimitZ;
}

/**
* @return Lower Limit Z degeri
*/
double PassThroughFilter::getLLZ() const {
	return this->lowerLimitZ;
}

/**
* @brief Bu fonksiyon nokta bulutunu alir ve nokta bulutunu filtereler. Filtreleme islemi su sekildedir:
Nokta bulutundaki her bir nokta icin tek tek islem yapilir. x, y ve z degerlerinden en az birisi
limitlerin disinda ise, bu nokta nokta bulutundan cikarilir.
* @param pc referans olarak atanmistir.
*/
void PassThroughFilter::filter(PointCloud& pc)
{
	Point temp;
	int flag = 0;
	for (int i = 0; i < pc.GetPointNumber(); i++)
	{
		temp = pc.GetPoints(i);
		if (temp.getX() > upperLimitX || temp.getX() < lowerLimitX || temp.getY() > upperLimitY || temp.getY() < lowerLimitY || temp.getZ() > upperLimitZ || temp.getZ() < lowerLimitZ)
		{
			//Limitlerin disina cikmis.
			for (int j = i; j > 0; j--)
			{
				pc.SetPoints(j, pc.GetPoints(j - 1));
			}
			flag++;
	
		}
	}

	int pointNo = pc.GetPointNumber();
	PointCloud newPC(pointNo - flag);

	for (int i = 0; i < newPC.GetPointNumber(); i++)
	{
		newPC.SetPoints(i, pc.GetPoints(i + flag));
	}

	pc = newPC;
	newPC.DeletePoints();
}