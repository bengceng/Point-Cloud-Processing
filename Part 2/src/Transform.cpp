/**
* @file  : Transform.cpp
* @Author: Bengisu Sahin (sahin.bengisu00@gmail.com)
* @date  : 11.01.2022
*/
#include "Transform.h"
#include "Point.h"
#include "PointCloud.h"
#include<iostream>
#include<iomanip>
#include<cmath>
#include<Eigen/Dense>

Eigen::Matrix3d rotationMatrix;

using namespace std;

Transform::Transform()  //Constructor
{

}
Transform::~Transform()  //Destructor
{

}

void Transform::set_angles(double first_angle, double second_angle, double third_angle)
{
	using namespace Eigen;
	angles(0) = first_angle;
	angles(1) = second_angle;
	angles(2) = third_angle;

}

void Transform::set_trans(double transX, double transY, double transZ)
{
	using namespace Eigen;
	trans(0) = transX;
	trans(1) = transY;
	trans(2) = transZ;
}

void Transform::setTranslation(Eigen::Vector3d tr)
{
	using namespace Eigen;
	for (int i = 0; i < i; i++) {
		for (int j = 0; j < 3; j++) {
			this->transMatrix(i, j) = rotationMatrix(i, j);
		}
	}
	this->transMatrix(3, 0) = 0;
	this->transMatrix(3, 1) = 0;
	this->transMatrix(3, 2) = 0;
	this->transMatrix(3, 3) = 1;
	for (int k = 0; k < 3; k++)
	{
		transMatrix(k, 3) = tr(k);
	}
}
void Transform::setTranslation(double tr[3]) {
	//-------------Ornek Donusum Matrisi Gosterimi------------------------
  //|   Rotation matrix (3x3)   Bu kisima trans martixi gelecek yani iki
  //|   R       R          R    ayri koordinat sisteminin orijinleri 
  //|   R       R          R    arasindaki fark.
  //|   0       0          0                  1
	//--------------------------------------------------------------------

  /* Yukaridaki matrix duzeni bir P noktasinin B koordinat ekseninden
	 A koordinat eksenine gecmesi icin gereken donusum matrisidir.*/


	 //En alttaki yani son satirdaki 0 lari ve 1 i atadik.
	this->transMatrix(3, 0) = 0;
	this->transMatrix(3, 1) = 0;
	this->transMatrix(3, 2) = 0;
	this->transMatrix(3, 3) = 1;

	//Burda 3 e 3 luk rotasyon matrix ini transMatrix e yerlestircez.
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			transMatrix(i, j) = rotationMatrix(i, j);
		}
	}

	//Son olarak da trans matrixini son sutuna yerlestiriyoruz.
	for (int k = 0; k < 3; k++)
	{
		transMatrix(k, 3) = tr[k];
	}
}


void Transform::setRotation(Eigen::Vector3d ang)
{
	rotationMatrix(0, 0) = cos(ang(2))*cos(ang(1));
	rotationMatrix(0, 1) = (cos(ang(2))*sin(ang(1))*sin(ang(0))) - (sin(ang(2))*cos(ang(0)));
	rotationMatrix(0, 2) = (cos(ang(2))*sin(ang(1))*cos(ang(0))) + (sin(ang(2))*sin(ang(0)));
	rotationMatrix(1, 0) = sin(ang(2))*cos(ang(1));
	rotationMatrix(1, 1) = (sin(ang(2))*sin(ang(1))*sin(ang(0))) + (cos(ang(2))*cos(ang(0)));
	rotationMatrix(1, 2) = (sin(ang(2))*sin(ang(1))*cos(ang(0))) - (cos(ang(2))*sin(ang(0)));
	rotationMatrix(2, 0) = -sin(ang(1));
	rotationMatrix(2, 1) = cos(ang(1))*sin(ang(0));
	rotationMatrix(2, 2) = cos(ang(1))*cos(ang(0));
}

void Transform::setRotation(double ang[3])
{

	//alfa acisi -> angles[2] || beta acisi -> angles[1] || gama acisi -> angles[0] ta tutuluyor.
	//Odev yonergesindeki rotasyon matrix formulu uygulandi.

	rotationMatrix(0, 0) = cos(ang[2])*cos(ang[1]);
	rotationMatrix(0, 1) = (cos(ang[2])*sin(ang[1])*sin(ang[0])) - (sin(ang[2])*cos(ang[0]));
	rotationMatrix(0, 2) = (cos(ang[2])*sin(ang[1])*cos(ang[0])) + (sin(ang[2])*sin(ang[0]));
	rotationMatrix(1, 0) = sin(ang[2])*cos(ang[1]);
	rotationMatrix(1, 1) = (sin(ang[2])*sin(ang[1])*sin(ang[0])) + (cos(ang[2])*cos(ang[0]));
	rotationMatrix(1, 2) = (sin(ang[2])*sin(ang[1])*cos(ang[0])) - (cos(ang[2])*sin(ang[0]));
	rotationMatrix(2, 0) = -sin(ang[1]);
	rotationMatrix(2, 1) = cos(ang[1])*sin(ang[0]);
	rotationMatrix(2, 2) = cos(ang[1])*cos(ang[0]);

}

double* Transform::get_trans() const
{
	double* ptr_trans = new double[3];
	for (int i = 0; i < 3; i++)
	{
		ptr_trans[i] = trans(i);
	}
	return ptr_trans;
}

double* Transform::get_angles() const
{

	double* ptr_angles = new double[3];
	for (int i = 0; i < 3; ++i)
	{
		ptr_angles[i] = angles(i);
	}
	return ptr_angles;
}
void Transform::display_translation() const
{
	using namespace Eigen;
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			cout << setw(15) << right << transMatrix(i, j);
		}
		cout << endl;
	}
}

void Transform::display_rotation() const {
	using namespace Eigen;
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cout << setw(15) << right << rotationMatrix(i, j);
		}
		cout << endl;

	}
}


Point Transform::doTransform(Point p)
{
	Point new_point;

	double p_coord[3];

	p_coord[0] = p.getX();
	p_coord[1] = p.getY();
	p_coord[2] = p.getZ();
	using namespace Eigen;
	Vector4d point1, point2;
	point2(0) = p_coord[0];
	point2(1) = p_coord[1];
	point2(2) = p_coord[2];
	point2(3) = 1;

	//Donusum matrisiyle point in noktalarinin carpim islemi
	point1 = transMatrix * point2;

	//Donusturlmus noktanin koord set edilir.
	new_point.SetPoint(point1(0), point1(1), point1(2));

	return new_point;
}



list<Point> Transform::doTransform(list<Point> lp)
{
	std::list<Point> new_list;
	std::list<Point>::iterator iter;
	//list teki her bir pointe transform islemi uygulanir
	for (iter = lp.begin(); iter != lp.end(); iter++)
	{
		new_list.push_back(doTransform(*iter));
	}
	return new_list;


}

PointCloud Transform::doTransform(PointCloud& pc)
{
	PointCloud new_pointCloud;
	std::list<Point>pTemp;
	pTemp = pc.GetPoints();
	new_pointCloud.SetPoints(doTransform(pTemp));
	return new_pointCloud;
}