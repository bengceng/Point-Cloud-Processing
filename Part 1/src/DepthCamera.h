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
	//! filename adl� dosyay� kaps�lleme yoluyla public de�i�kene e�itler.
	void setFile(string);

	//! DephtCamera sinifi icin constructor.
	DepthCamera(string);

	//! filename dosyas�n� d�nd�r�r.
	string getFile();

	//! filename adl� txt dosyas�n� okuyup pointcloud nesnesine atar.
	PointCloud capture();

private:

	string fileName;


};
#endif