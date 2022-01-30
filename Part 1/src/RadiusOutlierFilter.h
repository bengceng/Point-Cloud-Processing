/**
 * @file RadiusOutlierFilter.h
 * @Author Muhammet Eren SÖME (erensome1@gmail.com)
 * @date December, 2021
 * @brief RadiusOutlierFilter icin header dosyasi.
 *
 * RadiusOutlierFilter sinifinin ve sinif uyelerinin olusturuldugu dosya.
 */

//! RadiusOutlierFilter Sinifi
/*!
Bu sinif nokta bulutunda filtreleme yapar. Filter fonksiyonu ile nokta bulutunu alir 
ve filtrelenmis halini dondurur. Bu filtreleme isleminin algoritmasi su sekildedir. Nokta bulutundaki her bir 
nokta icin tek tek islem yapilir. Noktaya, radius degerinden daha yakin baska bir nokta yok ise, bu nokta 
nokta bulutundan cikarilir. 
 */
#ifndef RADIOUS_OUTLIER_FILTER_H
#define RADIOUS_OUTLIER_FILTER_H

#include "PointCloud.h"
class RadiusOutlierFilter
{
public:
	//! Yapici fonksiyon - (Constructor).
	RadiusOutlierFilter();
	//! Yikici fonksiyon - (Destructor).
	~RadiusOutlierFilter();
	//! Bu fonksiyon yaricap degerini atamayi saglar.
	void setRadius(double);
	//! Bu fonksyion yaricap degerini geri dondurmeyi saglar.
	double getRadius() const;
	//! Sinifa ait filtrelemenin yapildigi fonksiyon.
	void filter(PointCloud&);
private:
	double radius;
};
#endif // !RADIOUS_OUTLIER_FILTER_H