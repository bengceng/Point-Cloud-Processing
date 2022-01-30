/**
* @file PointCloudInterface.h
* @Author Emre Satilmis (emresatilmis42@gmail.com)
* @date January, 2022
* @brief Girdi/cikti islemlerini kolaylastiran bir sinif.
*/
#pragma once
#include "PointCloud.h"
#include "PointCloudGenerator.h"
#include "PointCloudRecorder.h"
#include <vector>
//! PointCloudInterface sinifi.
/*!
  PointCloudGenerators nesnelerini bir vectorde tutar ve her biri icin captureFor metodunu uyguladiktan sonra donen nokta bulutunu
  pointCloud uyesinde birlestirir. Yapilan degisikliklerden sonra olusan pointCloud nesnesini PointCloudRecorder araciligiyla
  yeni bir dosyaya kaydeder.
*/
class PointCloudInterface
{
	PointCloud pointCloud;
	PointCloud patch;
	std::vector<PointCloudGenerator*> generators;
	PointCloudRecorder* recorder;

public:
	//! PointCloudInterface sinifi icin constructor.
	PointCloudInterface();
	//! generators uyesine yeni bir PointCloudGenerator nesnesi ekler.
	void addGenerator(PointCloudGenerator*);
	//! recorder uyesine bir PointCloudRecorder nesnesi atar.
	void setRecorder(PointCloudRecorder*);
	//! generators uyesinde bulunan her bir nesne icin captureFor metodunu uygular ve donen nokta bulutunu pointCloud uyesine ekler.
	bool generate();
	//! pointCloud uyesinde tanimlanan nokta bulutunu recorder uyesi uzerinden yeni bir dosyaya kaydeder.
	bool record();
};