/**
* @file PointCloudGenerator.h
* @Author Fatih Yünsel (mrarchitect5454@gmail.com)
* @date January, 2022
* @brief txt dosyalarýndan koordinatlarý bir listeye aktarýp filtrelerden geçirerek döndüren sýnýf.
*/
#pragma once
#ifndef DEPHTCAMERA_H
#define DEPHTCAMERA_H
#include <iostream>
#include <fstream>
#include <string>
#include "PointCloud.h"
#include"PointCloudGenerator.h"
using namespace std;


class DepthCamera : public PointCloudGenerator
{
public:
	//! filename adlý dosyayý kapsülleme yoluyla public deðiþkene eþitler.
	void setFile(string);

	//! DephtCamera sinifi icin constructor.
	DepthCamera(string);

	//! DephtCamera sinifi icin destructor.
	~DepthCamera();

	//! filename dosyasýný döndürür.
	string getFile();

	//! filename adlý txt dosyasýný okuyup pointcloud nesnesine atar.
	PointCloud capture();

	//! filename adlý txt dosyasýný okuyup çeþitli filtrelerden geçirerek buluta atar ve bulutu döndürür.
	PointCloud captureFor();

private:

	string fileName;


};
#endif