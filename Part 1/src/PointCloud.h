/**
* @file PointCloud.h
* @Author Emre Satilmis (emresatilmis42@gmail.com)
* @date December, 2021
* @brief Point nesnelerini bir dizide tutan ve bu dizi uzerinden islemler yaptiran bir sinif.
*/
#pragma once
#include "Point.h"
//! PointCloud sinifi.
/*!
  Point nesnelerini bir dizide tutar. PointCloud'lari toplama ve iki PointCloud'i esitleme ozellikleri vardir.
*/
class PointCloud
{
public:
	//! PointCloud sinifi icin constructor.
	PointCloud(int = 0);
	//! PointCloud'a bir Point ekler.
	void SetPoints(int, Point);
	//! points dizisinden bir Point dondurur.
	Point GetPoints(int) const;
	//! points dizisinin boyutunu belirler.
	void SetPointNumber(int);
	//! points dizisinin boyutunu dondurur.
	int GetPointNumber() const;
	//! PointCloud'lari birlestirir.
	PointCloud operator+(const PointCloud&);
	//! Bir PointCloud'i baskasina esitler.
	const PointCloud &operator=(const PointCloud&);
	//! points dizisini siler.
	void DeletePoints();

private:
	Point* points;
	int pointNumber;
};

