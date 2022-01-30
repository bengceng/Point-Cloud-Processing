#include "DepthCamera.h"
#include "PointCloud.h"
#include "Point.h"
#include <fstream>




using namespace std;
/*!
\fileName adl� dosyay� kaps�lleme yoluyla public de�i�kene e�itler.
\_fileName dosyas� kaps�lleme yoluyla e�itlenmesi i�in konuldu.
*/
void DepthCamera::setFile(string _fileName) {

	fileName = _fileName;

}
/*!
\DephtCamera sinifi icin constructor.
\_fileName dosyas� kaps�lleme yoluyla e�itlenmesi i�in konuldu.
*/
DepthCamera::DepthCamera(string _fileName)
{


	setFile(_fileName);


}
/*!
\fileName dosyas�n� d�nd�r�r.
*/
string DepthCamera::getFile()
{


	return fileName;

}
/*!
\fileName adl� txt dosyas�n� okuyup pointcloud nesnesine atar.
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
	PointCloud pc(count);
	
	ifstream files(getFile());


	cloud = (double**)calloc(count, sizeof(double));
	for (i = 0; i < count; i++)
	{
		cloud[i] = (double*)calloc(count, sizeof(double));
	}


	for (i = 0; i < count; i++)
	{
		Point p;
		for (j = 0; j < 3; j++)
		{
			files >> cloud[i][j];
		}

		p.SetPoint(cloud[i][0], cloud[i][1], cloud[i][2]);

		pc.SetPoints(i, p);
	}
	for (i = 0; i < count; i++)
	{

		for (j = 0; j < 3; j++)
		{
			cloud[i][j] = 0;
		}
	}




	return pc;






}