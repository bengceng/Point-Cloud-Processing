// Fatih Yünsel 16.01.2022
#include "DepthCamera.h"
#include "PointCloud.h"
#include "Point.h"
#include "Transform.h"
#include"PointCloudGenerator.h"
#include"FilterPipe.h"
#include"PassThroughFilter.h"
#include"RadiusOutlierFilter.h"
#include <fstream>
#include<list>







using namespace std;
/*!
\fileName adlý dosyayý kapsülleme yoluyla public deðiþkene eþitler.
\_fileName dosyasý kapsülleme yoluyla eþitlenmesi için konuldu.
*/
void DepthCamera::setFile(string _fileName) {

	fileName = _fileName;

}
/*!
\DephtCamera sinifi icin constructor.
\_fileName dosyasý kapsülleme yoluyla eþitlenmesi için konuldu.
*/
DepthCamera::DepthCamera(string _fileName)
{


	setFile(_fileName);


}
/*!
\DephtCamera sinifi icin destructor.
*/
DepthCamera::~DepthCamera()
{


}
/*!
\fileName dosyasýný döndürür.
*/
string DepthCamera::getFile()
{


	return fileName;

}
/*!
\fileName adlý txt dosyasýný okuyup pointcloud nesnesine atar.
*/
PointCloud DepthCamera::capture()
{
	int i, j;
	double** cloud;



	ifstream file(getFile());
	string line;
	int count = 0;
	while (getline(file, line))
		++count;
	PointCloud pc;

	ifstream files(getFile());


	cloud = (double**)calloc(count, sizeof(double));
	for (i = 0; i < count; i++)
	{
		cloud[i] = (double*)calloc(count, sizeof(double));
	}
	Point tmp;
	list<Point> a;
	for (i = 0; i < count; i++)
	{


		for (j = 0; j < 3; j++)
		{
			files >> cloud[i][j];
		}

		tmp.SetPoint(cloud[i][0], cloud[i][1], cloud[i][2]);
		a.push_back(tmp);

	}
	pc.SetPoints(a);

	files.close();

	for (i = 0; i < count; i++)
	{

		for (j = 0; j < 3; j++)
		{
			cloud[i][j] = 0;
		}
	}




	return pc;






}
/*!
\fileName adlý txt dosyasýný okuyup pointcloud nesnesine attýktan sonra çeþitli filtrelerden geçirip oluþan pointcloud nesnesini döndürür.
*/
PointCloud DepthCamera::captureFor()
{
	int i, j;
	double** cloud;
	RadiusOutlierFilter filter1;
	RadiusOutlierFilter filter2;
	PassThroughFilter filterpass1;
	PassThroughFilter filterpass2;
	FilterPipe fp1;
	FilterPipe fp2;
	Transform tf;
	PointCloud tempPC;



	ifstream file(getFile());
	string line;
	int count = 0;
	while (getline(file, line))
		++count;
	PointCloud pc;


	ifstream files(getFile());


	cloud = (double**)calloc(count, sizeof(double));
	for (i = 0; i < count; i++)
	{
		cloud[i] = (double*)calloc(count, sizeof(double));
	}
	Point tmp;
	list<Point> a;

	for (i = 0; i < count; i++)
	{


		for (j = 0; j < 3; j++)
		{
			files >> cloud[i][j];
		}

		tmp.SetPoint(cloud[i][0], cloud[i][1], cloud[i][2]);
		a.push_back(tmp);

	}


	if (getFile() == "camera1.txt")
	{
		pc.SetPoints(a);
		filter1.setRadius(25);
		filterpass1.setULX(400);
		filterpass1.setLLX(0);
		filterpass1.setULY(400);
		filterpass1.setLLY(0);
		filterpass1.setULZ(45);
		filterpass1.setLLZ(-45);
		fp2.addFilter(&filter1);
		fp1.addFilter(&filterpass1);
		fp1.filterOut(pc);
		tf.set_angles(0, 0, -90.0);
		tf.set_trans(100, 500, 50);
		tf.setRotation(tf.get_angles());
		tf.setTranslation(tf.get_trans());

	}
	if (getFile() == "camera2.txt")
	{
		pc.SetPoints(a);
		filter2.setRadius(25);
		filterpass2.setULX(500);
		filterpass2.setLLX(0);
		filterpass2.setULY(500);
		filterpass2.setLLY(0);
		filterpass2.setULZ(45);
		filterpass2.setLLZ(-45);
		fp2.addFilter(&filter2);
		fp2.addFilter(&filterpass2);
		fp2.filterOut(pc);
		tf.set_angles(0, 0, 90.0);
		tf.set_trans(550, 150, 50);
		tf.setRotation(tf.get_angles());
		tf.setTranslation(tf.get_trans());






	}




	pc = tf.doTransform(pc);
	for (i = 0; i < count; i++)
	{

		for (j = 0; j < 3; j++)
		{
			cloud[i][j] = 0;
		}
	}

	files.close();
	return pc;

}









