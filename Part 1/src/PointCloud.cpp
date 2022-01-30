// Emre Satilmis 18.12.2021
#include "PointCloud.h"

/*!
\param _pointNumber points dizisinin boyutunu belirler.
*/
PointCloud::PointCloud(int _pointNumber)
{
	pointNumber = (_pointNumber > 0 ? _pointNumber : 0);
	points = new Point[_pointNumber];
}
/*!
\param i Dizinin indeksi.
\param p Diziye eklenecek nokta.
*/
void PointCloud::SetPoints(int i, Point p)
{
	points[i] = p;
}
/*!
\param i Dizinin indeksi.
*/
Point PointCloud::GetPoints(int i) const
{
	return points[i];
}
/*!
\param num points dizisinin boyutu.
*/
void PointCloud::SetPointNumber(int num)
{
	Point* tmppoints = new Point[num];
	for (int i = 0; i < pointNumber; i++)
	{
		tmppoints[i] = points[i];
	}
	delete[] points;

	int oldPointNumber = pointNumber;
	pointNumber = num;
	points = new Point[pointNumber];
	for (int i = 0; i < oldPointNumber; i++)
	{
		points[i] = tmppoints[i];
	}
	delete[] tmppoints;
}

int PointCloud::GetPointNumber() const
{
	return pointNumber;
}
/*!
\param pc toplama yapilacak diger PointCloud.
*/
PointCloud PointCloud::operator+(const PointCloud& pc)
{
	int sumPointNumber = pointNumber + pc.GetPointNumber();
	PointCloud sumPC(sumPointNumber);

	for (int i = 0; i < pointNumber; i++)
	{
		sumPC.SetPoints(i, points[i]);
	}

	for (int i = 0; i < pc.GetPointNumber(); i++)
	{
		Point p = pc.GetPoints(i);
		sumPC.SetPoints(pointNumber + i, p);
	}

	return sumPC;
}
/*!
\param pc esitleme yapilacak diger PointCloud.
*/
const PointCloud &PointCloud::operator=(const PointCloud& pc)
{
	if (&pc != this)
	{
		if (pointNumber != pc.GetPointNumber())
		{
			delete[] points;
			pointNumber = pc.GetPointNumber();
			points = new Point[pointNumber];
		}

		for (int i = 0; i < pointNumber; i++)
		{
			Point p = pc.GetPoints(i);
			this->SetPoints(i, p);
		}
	}

	return *this;
}

void PointCloud::DeletePoints()
{
	delete[] points;
}