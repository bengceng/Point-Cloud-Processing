/**
* @file PointCloudRecorder.h
* @Author Yigit Efe Cosgun (velavuella@gmail.com)
* @date January, 2021
* @brief Save fonksiyonu kullan�larak fileName.txt dosyas�na nokta bulutundaki noktalar kaydedilir.
*/
#ifndef POINT_CLOUD_RECORDER_H
#define POINT_CLOUD_RECORDER_H

#include "Point.h"
#include "PointCloud.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream> 
using namespace std;
class PointCloudRecorder
{
public:
	//! yapici fonskiyon
	PointCloudRecorder();
	//! fileName ismini g�nderir
	string getFileName();
	//! fileName ismini belirler
	void setFileName(string);
	//! dosyaya pointleri kaydeder
	bool save(const PointCloud&);
private:
	string filename;
};
#endif // !POINT_CLOUD_RECORDER_H
