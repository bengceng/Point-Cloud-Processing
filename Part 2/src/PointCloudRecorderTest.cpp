/**
* @file PointCloudRecorderTest.cpp
* @Author Yigit Efe Cosgun(velavuella@gmail.com)
* @date December, 2021
* @brief Bu kod PointCloudRecorder sinifini test eder.
*/

#include"PointCloudRecorder.h"

using namespace std;

void PointCloudRecorderTest()
{
	cout << "Point Cloud Recorder Test" << endl;

	PointCloudRecorder PCR;

	Point p1, p2, p3;
	p1.SetPoint(1, 2, 3);
	p2.SetPoint(3, 23, 32);
	p3.SetPoint(4, 6, 53);
	PointCloud pc;
	pc.InsertPoints(p1);
	pc.InsertPoints(p2);
	pc.InsertPoints(p3);

	PCR.setFileName("output.txt");
	PCR.save(pc);
	cout << "TEST Fonksiyonu bitti" << endl;
	cout << "---------------------" << endl;
}