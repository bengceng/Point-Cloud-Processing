/**
* @file FilterPipe.cpp
* @Author Muhammet Eren SÖME (erensome1@gmail.com)
* @date December, 2021
* @brief Bu dosya FilterPipe sinifinin fonksiyonlarinin isleyisini icerir.
*/
#include "FilterPipe.h"
#include <iterator>

using namespace std;
FilterPipe::FilterPipe()
{
}

FilterPipe::~FilterPipe()
{
}

/**
* @brief bu fonksiyon farkli tip filtreler ya da farkli parametrelere sahip ayni tip filtreleri filters vectorune ekler.
* @param filter filters vectorune eklenecek PointCloudFilter objesini temsil eder.
*/
void FilterPipe::addFilter(PointCloudFilter* filter)
{
	filters.push_back(filter);
}

/**
* @brief bu fonksiyon nokta bulutunu ekleme sirasina gore filtrelerden gecirip sonuc nokta bulutunu dondurur.
* @param pc Filtreden gecirilecek PointCloud objesini temsil eder.
*/
void FilterPipe::filterOut(PointCloud& pc)
{
	vector<PointCloudFilter*>::iterator it;
	for (it = filters.begin(); it != filters.end(); it++)
	{
		(*it)->filter(pc);
	}
}
