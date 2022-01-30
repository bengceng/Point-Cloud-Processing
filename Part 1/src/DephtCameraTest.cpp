#include <iostream>
#include"DepthCamera.h"
#include "Point.h"
#include "PointCloud.h"
using namespace std;

void DephtCameraTest()
{
	PointCloud pc1, pc2;
	cout << "DephtCamera Test" << endl;
	cout << "---------------" << endl;
	DepthCamera dc("camera1.txt");	
	pc1 = dc.capture();
	pc1.GetPoints(0);
	pc1.GetPoints(1);
	pc1.GetPoints(2);
	pc1.GetPoints(3);
	DepthCamera cd("camera2.txt");
	pc2 = cd.capture();
}