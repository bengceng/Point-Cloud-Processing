/**
* @file PointCloudGenerator.h
* @Author Fatih Yünsel (mrarchitect5454@gmail.com)
* @date January, 2022
* @brief PointCloudGenerator altýna DephtCamera class ýný alan bir abstract class.
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
	//! PointCloudGenerator sýnýfý için constructor.
	PointCloudGenerator();
	//! PointCloudGenerator sýnýfý için destructor.
	~PointCloudGenerator();
	//! DephtCamera sýnýfý için virtual sýnýf.
	virtual PointCloud capture() = 0;
	//! DephtCamera sýnýfý için virtual sýnýf.
	virtual PointCloud captureFor() = 0;
	//! Private olan filterpipe nesnesini public olan nesneye eþitler.
	void setFilterpipe(FilterPipe* _filterPipe);

private:
	Transform transform;
	FilterPipe* filterPipe;

};
#endif // !1
