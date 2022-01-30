/**
* @file PassThroughFilter.cpp
* @Author Muhammet Eren SÖME (erensome1@gmail.com)
* @date December, 2021
* @brief Bu dosya PassThroughFilter sinifinin fonksiyonlarinin isleyisini icerir.
*/
#include "PassThroughFilter.h"
#include<iostream>
#include<list>
#include<iterator>

using namespace std;
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
	list<Point> oldPC, newPC;
	oldPC = pc.GetPoints();
	list<Point>::iterator it;
	int flag = 0;
	for (it=oldPC.begin(); it!=oldPC.end(); it++)
	{
		if (it->getX() >= lowerLimitX && it->getX() <= upperLimitX && it->getY() >= lowerLimitY && it->getY() <= upperLimitY && it->getZ() >= lowerLimitZ && it->getZ() <= upperLimitZ)
		{
			newPC.push_back(*it);
			flag++;
		}
	}
	pc.SetPoints(newPC);
}