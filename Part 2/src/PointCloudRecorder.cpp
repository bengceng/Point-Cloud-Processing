/**
* @file PointCloudRecorder.cpp
* @Author Yigit Efe Cosgun (velavuella@gmail.com)
* @date January, 2021
* @brief Save fonksiyonu kullanılarak fileName.txt dosyasına nokta bulutundaki noktalar kaydedilir.
*/
#include "PointCloudRecorder.h"
#include <list>
#include <iterator>

//! PointCloudRecorder sınıfının yapıcı fonksiyonudur.
PointCloudRecorder::PointCloudRecorder()
{
	filename = "output.txt";
}
/*!
\return dosya adi gönder
*/
string PointCloudRecorder::getFileName()
{
	return filename;
}
/*!
\param:  String dosya adi
*/
void PointCloudRecorder::setFileName(string name)
{
	filename = name;
}
/*!
\param:  PointCloud pc
\return: bool
*/
bool PointCloudRecorder::save(PointCloud const& pc) {
	list<Point> pointList;
	pointList = pc.GetPoints();
	ofstream outputFile;
	outputFile.open(filename);

	list<Point>::iterator it;

	if (outputFile.is_open())
	{
		cout << "Cikti dosyasi basariyla acildi." << endl << endl;
		outputFile << fixed << showpoint;
		outputFile << setprecision(3);

		for (it = pointList.begin(); it != pointList.end(); it++)
		{
			outputFile << setw(9) << it->getX() << setw(9) << it->getY() << setw(9) << it->getZ() << endl;
		}
		outputFile.close();
		return true;
	}
	else
	{
		cout << "Cikti dosyasi acilamadi lutfen kontrol ediniz!" << endl;
	}

	return false;
}