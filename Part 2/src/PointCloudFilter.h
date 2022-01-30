/**
* @file PointCloudFilter.h
* @Author Muhammet Eren SÖME (erensome1@gmail.com)
* @date December, 2021
* @brief PointCloudFilter icin header dosyasi.
*
* PointCloudFilter abstract sinifinin ve sinif uyelerinin olusturuldugu dosya.
*/

//! PointCloudFilter sinifi
/*!
Filtrelerin altinda toplandigi Abstract bir siniftir.
*/
#ifndef POINT_CLOUD_FILTER_H
#define POINT_CLOUD_FILTER_H
#include "PointCloud.h"

class PointCloudFilter
{
public:
	//! Yapici fonksiyon - (Constructor).
	PointCloudFilter();
	//! Yikici fonksiyon - (Destructor).
	~PointCloudFilter();
	//! Pure virtual filter fonksiyonu.
	virtual void filter(PointCloud& pc) = 0;
};
#endif // !POINT_CLOUD_FILTER_H
