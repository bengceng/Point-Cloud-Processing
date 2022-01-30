/**
* @file PointCloudGenerator.h
* @Author Fatih Y�nsel (mrarchitect5454@gmail.com)
* @date January, 2022
* @brief txt dosyalar�ndan koordinatlar� bir listeye aktar�p filtrelerden ge�irerek d�nd�ren s�n�f.
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
	//! filename adl� dosyay� kaps�lleme yoluyla public de�i�kene e�itler.
	void setFile(string);

	//! DephtCamera sinifi icin constructor.
	DepthCamera(string);

	//! DephtCamera sinifi icin destructor.
	~DepthCamera();

	//! filename dosyas�n� d�nd�r�r.
	string getFile();

	//! filename adl� txt dosyas�n� okuyup pointcloud nesnesine atar.
	PointCloud capture();

	//! filename adl� txt dosyas�n� okuyup �e�itli filtrelerden ge�irerek buluta atar ve bulutu d�nd�r�r.
	PointCloud captureFor();

private:

	string fileName;


};
#endif