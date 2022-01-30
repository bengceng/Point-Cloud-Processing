/**
* @file PointCloud.h
* @Author Emre Satilmis (emresatilmis42@gmail.com)
* @date December, 2021
* @brief Point nesnelerini bir listede tutan ve bu liste uzerinden islemler yaptiran bir sinif.
*/
#pragma once
#include "Point.h"
#include <list>
//! PointCloud sinifi.
/*!
  Point nesnelerini bir listede tutar. PointCloud'lari toplama ve iki PointCloud'i esitleme ozellikleri vardir.
*/
class PointCloud
{
public:
	//! PointCloud sinifi icin constructor.
	PointCloud();
	//! points listesine bir Point ekler.
	void InsertPoints(Point);
	//! points listesini gonderilen parametredeki listeyle degistirir.
	void SetPoints(std::list<Point>);
	//! points listesini dondurur.
	std::list<Point> GetPoints() const;
	//! points listesinin boyutunu dondurur.
	int GetPointNumber() const;
	//! PointCloud'lari birlestirir.
	PointCloud operator+(const PointCloud&);
	//! Bir PointCloud'i baskasina esitler.
	const PointCloud &operator=(const PointCloud&);

private:
	std::list<Point> points;
};

