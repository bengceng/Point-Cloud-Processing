/**
* @file Transform.cpp
* @Author Bengisu �ahin (sahin.bengisu00@gmail.com)
* @date 18.12.2021
*/
#include "Transform.h"
#include "Point.h"
#include "PointCloud.h"
#include<iostream>
#include<iomanip>
#include<cmath>

double rotationMatrix[3][3];

using namespace std;

Transform::Transform()  //Constructor
{

}
Transform::~Transform()  //Destructor
{

}

void Transform::set_angles(double first_angle, double second_angle, double third_angle)
{
	angles[0] = first_angle;
	angles[1] = second_angle;
	angles[2] = third_angle;
}

void Transform::set_trans(double transX, double transY, double transZ)
{
	trans[0] = transX;
	trans[1] = transY;
	trans[2] = transZ;
}

void Transform::setTranslation(double tr[3])
{
	//-------------Ornek Donusum Matrisi Gosterimi------------------------
  //|   Rotation matrix (3x3)   Bu kisima trans martixi gelecek yani iki
  //|   R       R          R    ayri koordinat sisteminin orijinleri 
  //|   R       R          R    arasindaki fark.
  //|   0       0          0                  1
	//--------------------------------------------------------------------

  /* Yukaridaki matrix duzeni bir P noktasinin B koordinat ekseninden
	 A koordinat eksenine gecmesi icin gereken donusum matrisidir.*/


	 //En alttaki yani son satirdaki 0 lari ve 1 i atadik.
	transMatrix[3][0] = 0;
	transMatrix[3][1] = 0;
	transMatrix[3][2] = 0;
	transMatrix[3][3] = 1;

	//Burda 3 e 3 luk rotasyon matrix ini transMatrix e yerlestircez.
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			transMatrix[i][j] = rotationMatrix[i][j];
		}
	}

	//Son olarak da trans matrixini son sutuna yerlestiriyoruz.
	for (int k = 0; k < 3; k++)
	{
		transMatrix[k][3] = tr[k];
	}

}

void Transform::setRotation(double ang[3])
{

	//alfa acisi -> angles[2] || beta acisi -> angles[1] || gama acisi -> angles[0] ta tutuluyor.
	//Odev yonergesindeki rotasyon matrix formulu uygulandi.

	rotationMatrix[0][0] = cos(ang[2]) * cos(ang[1]);
	rotationMatrix[0][1] = (cos(ang[2]) * sin(ang[1]) * sin(ang[0])) - (sin(ang[2]) * cos(ang[0]));
	rotationMatrix[0][2] = (cos(ang[2]) * sin(ang[1])) * cos(ang[0]) + (sin(ang[2]) * sin(ang[0]));
	rotationMatrix[1][0] = sin(ang[2]) * cos(ang[1]);
	rotationMatrix[1][1] = (sin(ang[2]) * sin(ang[1]) * sin(ang[0])) + (cos(ang[2]) * cos(ang[0]));
	rotationMatrix[1][2] = (sin(ang[2]) * sin(ang[1]) * cos(ang[0])) - (cos(ang[2]) * sin(ang[0]));
	rotationMatrix[2][0] = -sin(ang[1]);
	rotationMatrix[2][1] = cos(ang[1]) * sin(ang[0]);
	rotationMatrix[2][2] = cos(ang[1]) * cos(ang[0]);

}

double* Transform::get_trans() const
{
	double* ptr_trans = new double[3];
	for (int i = 0; i < 3; i++)
	{
		ptr_trans[i] = this->trans[i];
	}
	return ptr_trans;
}

double* Transform::get_angles() const
{

	double* ptr_angles = new double[3];
	for (int i = 0; i < 3; ++i)
	{
		ptr_angles[i] = this->angles[i];
	}
	return ptr_angles;
}
void Transform::display_translation() const
{
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			cout << setw(15) << right << transMatrix[i][j];
		}
		cout << endl;
	}
}

void Transform::display_rotation() const {
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cout << setw(15) << right << rotationMatrix[i][j];
		}
		cout << endl;
	}
}

Point Transform::doTransform(Point p)
{
	Point new_point;
	//P noktasini (B koordinatina gore) A koordinatina 
	//gore bulmak istiyorsak yani donusum yapmak istiyorsak
	// transformation matrisi ile Pb yi carpmaliyiz.


	double new_coordinates[4] = { 0 };  //Carpim sonucunda 4x1 lik bir matris elde ederiz. 
	double p_coord[4];                 //Son satir liner cebirsel olarak her zaman 1 olur.

	//								   //ilk 3 satirsa bizim yeni pointimizin koordinatlarini verir.

	p_coord[0] = p.getX();
	p_coord[1] = p.getY();
	p_coord[2] = p.getZ();
	p_coord[3] = 1;

	//Donusum matrisiyle point in carpim islemi
	for (int i = 0; i < 4; i++) {

		for (int k = 0; k < 4; k++)
		{
			new_coordinates[i] += this->transMatrix[i][k] * p_coord[k];
		}

	}

	new_point.SetPoint(new_coordinates[0], new_coordinates[1], new_coordinates[2]);

	return new_point;
}

PointCloud Transform::doTransform(PointCloud& pc)
{
	PointCloud new_pointCloud;
	//Point *ptr;
	//ptr = new Point[pc.GetPointNumber()];
	int i, num = pc.GetPointNumber();
	new_pointCloud.SetPointNumber(pc.GetPointNumber());
	for (i = 0; i < num; i++) {
		new_pointCloud.SetPoints(i, doTransform(pc.GetPoints(i)));
	}

	return new_pointCloud;
}