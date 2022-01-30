#include <iostream>
#include "Point.h"
#include "PointCloud.h"
#include "Transform.h"
#include "DepthCamera.h"
#include "PointCloudRecorder.h"
#include "PassThroughFilter.h"
#include "RadiusOutlierFilter.h"
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

#elif 1
	PointCloud pc1;
	PointCloud pc2;

	DepthCamera c1("camera1.txt");
	/*DepthCamera c2("camera2.txt");*/
	pc1 = c1.capture();
	c1.setFile("camera2.txt");
	pc2 = c1.capture();

	RadiusOutlierFilter rof;
	rof.setRadius(25);
	rof.filter(pc1);
	rof.filter(pc2);

	PassThroughFilter ptf;
	ptf.setLLX(0);
	ptf.setULX(400);
	ptf.setLLY(0);
	ptf.setULY(400);
	ptf.setLLZ(-45);
	ptf.setULZ(45);
	ptf.filter(pc1);

	ptf.setLLX(0);
	ptf.setULX(500);
	ptf.setLLY(0);
	ptf.setULY(500);
	ptf.setLLZ(-45);
	ptf.setULZ(45);
	ptf.filter(pc2);

	Transform tf;
	tf.set_trans(100, 500, 50);
	tf.set_angles(0, 0, -90.0);
	tf.setRotation(tf.get_angles());
	tf.setTranslation(tf.get_trans());
	PointCloud tempPC;
	tempPC = tf.doTransform(pc1);

	tf.set_trans(550, 150, 50);
	tf.set_angles(0, 0, 90.0);
	tf.setRotation(tf.get_angles());
	tf.setTranslation(tf.get_trans());
	PointCloud tempPC2;
	tempPC2 = tf.doTransform(pc2);

	PointCloud pc3;
	pc3 = tempPC + tempPC2;


	string fName;
	cout << "Lutfen olusturalacak cikti dosyasinin ismini uzantisiyla birlikte giriniz: ";
	cin >> fName;

	PointCloudRecorder pcr;
	pcr.setFileName(fName);
	pcr.save(pc3);

	cout << "Program basariyla sonlandirildi. Ciktilar icin '" << fName << "' dosyasini kontrol ediniz." << endl;

	return 0;
#endif
}