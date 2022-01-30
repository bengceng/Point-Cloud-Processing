// Emre Satilmis 10.01.2022
#include "PointCloud.h"

PointCloud::PointCloud()
{
	
}
/*!
\param p Listeye eklenecek nokta.
*/
void PointCloud::InsertPoints(Point p)
{
	points.push_back(p);
}
/*!
\param plist Yeni liste.
*/
void PointCloud::SetPoints(std::list<Point> plist)
{
	points.clear();
	points = plist;
}

std::list<Point> PointCloud::GetPoints() const
{
	return points;
}

int PointCloud::GetPointNumber() const
{
	return points.size();
}
/*!
\param pc toplama yapilacak diger PointCloud.
*/
PointCloud PointCloud::operator+(const PointCloud& pc)
{
	PointCloud sumPC;
	sumPC = *this;

	std::list<Point> temp = pc.GetPoints();
	for (int i = 0; i < pc.GetPointNumber(); i++)
	{
		sumPC.InsertPoints(temp.front());
		temp.pop_front();
	}

	return sumPC;
}
/*!
\param pc esitleme yapilacak diger PointCloud.
*/
const PointCloud &PointCloud::operator=(const PointCloud& pc)
{
	std::list<Point> temp = pc.GetPoints();

	if (&pc != this)
	{
		points.clear();
		for (int i = 0; i < pc.GetPointNumber(); i++)
		{
			this->InsertPoints(temp.front());
			temp.pop_front();
		}
	}

	return *this;
}