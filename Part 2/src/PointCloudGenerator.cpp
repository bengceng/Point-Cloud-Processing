// Fatih Y�nsel 16.01.2022
#include "DepthCamera.h"
#include "PointCloud.h"
#include "Point.h"
#include "Transform.h"
#include "FilterPipe.h"
#include <fstream>
#include <algorithm>
#include <sstream>


using namespace std;

/*!
\PointCloudGenerator s�n�f� i�in constructor.
*/
PointCloudGenerator::PointCloudGenerator()
{
	filterPipe = new FilterPipe();

}
/*!
\PointCloudGenerator s�n�f� i�in destructor.
*/
PointCloudGenerator::~PointCloudGenerator()
{

}
/*!
\private olan filterpipe nesnesini public pointera atar.
*/
void PointCloudGenerator::setFilterpipe(FilterPipe* _filterPipe)
{
	filterPipe = _filterPipe;
}

	Transform transform;
	FilterPipe* filterPipe;


