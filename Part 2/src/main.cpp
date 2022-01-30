#include <iostream>
#include "Point.h"
#include "PointCloud.h"
#include "Transform.h"
#include "DepthCamera.h"
#include "PointCloudRecorder.h"
#include "PassThroughFilter.h"
#include "RadiusOutlierFilter.h"
#include "PointCloudInterface.h"
#include "FilterPipe.h"
using namespace std;

//! Point sinifinin uye fonksiyonlarini test eder.
void PointTest();
//! PointCloud sinifinin uye fonksiyonlarini test eder.
void PointCloudTest();
//! Transform sinifini test eder.
void TransformTest();
//! PassThroughFilter sinifini test eder.
void PassThroughFilterTest();
//! RadiusOutlierFilter sinifini test eder.
void RadiusOutlierFilterTest();
//! DephtCamera sinifini test eder.
void DephtCameraTest();
//! PointCloudRecorder sinifini test eder.
void PointCloudRecorderTest();
//! PointCloudInterface sinifini test eder.
void PointCloudInterfaceTest();
//! FilterPipe sinifini test eder.
void FilterPipeTest();
int main()
{
#if 0
	PointTest();
	PointCloudTest();
	TransformTest();
	PassThroughFilterTest();
	RadiusOutlierFilterTest();
	DephtCameraTest();
	PointCloudRecorderTest();
	PointCloudInterfaceTest();
	FilterPipeTest();
#elif 1
	PointCloudRecorder PCR;

	DepthCamera DC1("camera1.txt");
	DepthCamera DC2("camera2.txt");

	PointCloudInterface PCI;

	PCI.addGenerator(&DC1);
	PCI.addGenerator(&DC2);

	PCI.setRecorder(&PCR);

	PCI.generate();
	if (PCI.record())
	{
		cout << "Program basariyla sonlandirildi. Ciktilar icin 'output.txt' dosyasini kontrol ediniz." << endl;
	}
	else
	{
		cout << "Program bir hatayla karsilasti. Lutfen input dosyalarinin eksik olmadigini teyit ediniz!" << endl;
	}
	return 0;
#endif
}