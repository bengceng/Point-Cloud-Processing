/**
 * @file PassThroughFilter.h
 * @Author Muhammet Eren SÖME (erensome1@gmail.com)
 * @date December, 2021
 * @brief PassThroughFilter icin header dosyasi.
 *
 * PassThroughFilter Sinifinin ve sinif uyelerinin olusturuldugu dosya.
 */

//! PassThroughFilter Sinifi
/*!
   Bu sinif nokta bulutunda filtreleme yapar. Filter fonksiyonu ile nokta bulutunu alir 
ve filtrelenmis halini dondurur. Bu filtreleme isleminde, noktanin x, y ve z degerlerinden en az birisi 
limitlerin disinda ise, bu nokta nokta bulutundan cikarilir.
*/
#ifndef PASS_THROUGH_FILTER_H
#define PASS_THROUGH_FILTER_H

#include"PointCloud.h"
class PassThroughFilter
{
private:
	double upperLimitX, lowerLimitX;
	double upperLimitY, lowerLimitY;
	double upperLimitZ, lowerLimitZ;

public:
	//! Yapici fonksiyon - (Constructor).
	PassThroughFilter();
	//! Yikici fonksiyon - (Destructor).
	~PassThroughFilter();
	//! Bu fonksiyon, Upper Limit X degerini atamaya yarar.
	void setULX(double);
	//! Bu fonksiyon, Lower Limit X degerini atamaya yarar.
	void setLLX(double);
	//! Bu fonksiyon, Upper Limit Y degerini atamaya yarar.
	void setULY(double);
	//! Bu fonksiyon, Lower Limit Y degerini atamaya yarar.
	void setLLY(double);
	//! Bu fonksiyon, Upper Limit Z degerini atamaya yarar.
	void setULZ(double);
	//! Bu fonksiyon, Lower Limit Z degerini atamaya yarar.
	void setLLZ(double);

	//! Bu fonksiyon, Upper Limit X degerini dondurur.
	double getULX() const;
	//! Bu fonksiyon, Upper Limit X degerini dondurur.
	double getLLX() const;
	//! Bu fonksiyon, Upper Limit Y degerini dondurur.
	double getULY() const;
	//! Bu fonksiyon, Lower Limit Y degerini dondurur.
	double getLLY() const;
	//! Bu fonksiyon, Upper Limit Z degerini dondurur.
	double getULZ() const;
	//! Bu fonksiyon, Lower Limit Z degerini dondurur.
	double getLLZ() const;

	//! Sinifa ait filtrelemenin yapildigi fonksiyon.
	void filter(PointCloud&);
};
#endif // !PASS_THROUGH_FILTER_H