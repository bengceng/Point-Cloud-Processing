// Emre Satilmis 17.01.2022
#include "PointCloudInterface.h"
#include "DepthCamera.h"
#include <iostream>

using namespace std;

void PointCloudInterfaceTest()
{
	cout << "\nPointCloudInterface Test" << endl;
	cout << "------------------------" << endl;

	PointCloudInterface pci;
	PointCloudGenerator* pcg1, * pcg2;
	PointCloudRecorder* pcr = new PointCloudRecorder();
	DepthCamera dc1("camera1.txt"), dc2("camera2.txt");

	cout << "camera1.txt ve camera2.txt dosyalarindan dc1 ve dc2 DepthCamera nesneleri olusturuldu." << endl;

	pcg1 = &dc1;
	pcg2 = &dc2;
	pci.addGenerator(pcg1);
	pci.addGenerator(pcg2);

	cout << "dc1 ve dc2 nesnelerine bagli olan pcg1 ve pcg2 PointCloudGenerator nesneleri generators uyesine eklendi." << endl;

	if (pci.generate())
		cout << "pointCloud olusturuldu." << endl;
	else
		cout << "PointCloudGenerator nesnesi bulunamadi!" << endl;
	
	pcr->setFileName("output.txt");
	pci.setRecorder(pcr);

	if (pci.record())
		cout << "pointCloud output.txt dosyasina yazildi." << endl;
	else
		cout << "pointCloud nesnesi bulunamadi!" << endl;
}