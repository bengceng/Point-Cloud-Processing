/**
* @file Point.h
* @Author Emre Satilmis (emresatilmis42@gmail.com)
* @date December, 2021
* @brief 3 boyutlu duzlemde nokta nesnesi olusturmak icin bir sinif.
*/
#pragma once
//! Point sinifi.
/*!
  x, y, z koordinatlariyla 3 boyutlu duzlemde bir nokta olusturulmasini saglar.
  Noktaya ait koordinatlarin elde edilmesi, iki noktanin esitliginin kontrolu ve
  iki nokta arasindaki uzakligin hesaplanmasi gibi ozelliklere sahiptir.
*/
class Point
{
	double x, y, z;

public:
	//! Point sinifi icin constructor.
	Point();
	//! Noktaya koordinat atamasi yapar.
	void SetPoint(double, double, double);
	//! Noktadan koordinat degerlerini alýr.
	void GetPoint(double&, double&, double&) const;
	//! Iki noktanin ayni olup olmadigini karsilastirir.
	bool operator==(const Point&) const;
	//! Iki nokta arasindaki uzakligi hesaplar.
	double distance(const Point&) const;
	//! Noktanin x degerini dondurur.
	double getX() const;
	//! Noktanin y degerini dondurur.
	double getY() const;
	//! Noktanin z degerini dondurur.
	double getZ() const;
};

