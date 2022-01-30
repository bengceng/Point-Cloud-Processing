/**
* @file PointCloudGenerator.h
* @Author Fatih Y�nsel (mrarchitect5454@gmail.com)
* @date January, 2022
* @brief PointCloudGenerator alt�na DephtCamera class �n� alan bir abstract class.
*/
#pragma once
#ifndef POINTCLOUDGENERATOR_H
#define POINTCLOUDGENERATOR_H
#include<iostream>
#include"FilterPipe.h"
#include "Transform.h"

class PointCloudGenerator
{
public:
	//! PointCloudGenerator s�n�f� i�in constructor.
	PointCloudGenerator();
	//! PointCloudGenerator s�n�f� i�in destructor.
	~PointCloudGenerator();
	//! DephtCamera s�n�f� i�in virtual s�n�f.
	virtual PointCloud capture() = 0;
	//! DephtCamera s�n�f� i�in virtual s�n�f.
	virtual PointCloud captureFor() = 0;
	//! Private olan filterpipe nesnesini public olan nesneye e�itler.
	void setFilterpipe(FilterPipe* _filterPipe);

private:
	Transform transform;
	FilterPipe* filterPipe;

};
#endif // !1
