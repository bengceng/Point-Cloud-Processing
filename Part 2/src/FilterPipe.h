/**
* @file FilterPipe.h
* @Author Muhammet Eren SÖME (erensome1@gmail.com)
* @date December, 2021
* @brief FilterPipe icin header dosyasi.
*
* FilterPipe sinifinin ve sinif uyelerinin olusturuldugu dosya.
*/

//! FilterPipe Sinifi
/*!
Birden fazla filtreden gecmesi gereken nokta bulutunun filtreleme islemini yapacak siniftir.
*/
#ifndef FILTERPIPE_H
#define FILTERPIPE_H
#include <vector>
#include"PointCloudFilter.h"

class FilterPipe
{
public:
	//! Yapici fonksiyon - (Constructor).
	FilterPipe();
	//! Yikici fonksiyon - (Destructor).
	~FilterPipe();
	//! filters vectorune verilen filteri ekleyen fonksiyon.
	void addFilter(PointCloudFilter*);
	//! verilen PointCloud objesini filtrelerden geciren fonksiyon.
	void filterOut(PointCloud&);
private:
	std::vector<PointCloudFilter*> filters;
};
#endif // !FILTERPIPE_H

