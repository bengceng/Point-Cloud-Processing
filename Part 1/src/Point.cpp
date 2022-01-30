// Emre Satilmis 14.12.2021
#include "Point.h"
#include <math.h>

Point::Point()
{
	x = 0;
	y = 0;
	z = 0;
}
/*!
\param _x Noktaya atanacak x degeri.
\param _y Noktaya atanacak y degeri.
\param _z Noktaya atanacak z degeri.
*/
void Point::SetPoint(double _x = 0, double _y = 0, double _z = 0)
{
	x = _x;
	y = _y;
	z = _z;
}
/*!
\param _x Noktadan alinacak x degeri.
\param _y Noktadan alinacak y degeri.
\param _z Noktadan alinacak z degeri.
*/
void Point::GetPoint(double& _x, double& _y, double& _z) const
{
	_x = x;
	_y = y;
	_z = z;
}
/*!
\param p Karsilastirma yapilacak diger nokta.
\return Karsilastirma sonucu.
*/
bool Point::operator==(const Point& p) const
{
	if (x == p.x && y == p.y && z == p.z)
		return true;
	else
		return false;
}
/*!
\param p Aradaki uzakligi hesaplanacak diger nokta.
\return Iki nokta arasindaki uzaklik.
*/
double Point::distance(const Point& p) const
{
	double d;
	d = sqrt(pow(x - p.x, 2) + pow(y - p.y, 2) + pow(z - p.z, 2));
	return d;
}

double Point::getX() const
{
	return x;
}

double Point::getY() const
{
	return y;
}

double Point::getZ() const
{
	return z;
}