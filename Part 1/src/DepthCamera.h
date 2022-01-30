#ifndef DEPHTCAMERA_H
#define DEPHTCAMERA_H
#include <iostream>
#include <fstream>
#include <string>
#include "PointCloud.h"
using namespace std;


class DepthCamera
{
public:
	//! filename adlý dosyayý kapsülleme yoluyla public deðiþkene eþitler.
	void setFile(string);

	//! DephtCamera sinifi icin constructor.
	DepthCamera(string);

	//! filename dosyasýný döndürür.
	string getFile();

	//! filename adlý txt dosyasýný okuyup pointcloud nesnesine atar.
	PointCloud capture();

private:

	string fileName;


};
#endif