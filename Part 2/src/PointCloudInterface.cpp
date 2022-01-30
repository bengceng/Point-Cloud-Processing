// Emre Satilmis 17.01.2022
#include "PointCloudInterface.h"

PointCloudInterface::PointCloudInterface()
{
	recorder = NULL;
}
/*!
\param pcg PointCloudGenerator nesnesi.
*/
void PointCloudInterface::addGenerator(PointCloudGenerator* pcg)
{
	generators.push_back(pcg);
}
/*!
\param pcr PointCloudRecorder nesnesi.
*/
void PointCloudInterface::setRecorder(PointCloudRecorder* pcr)
{
	recorder = pcr;
}

bool PointCloudInterface::generate()
{
	// PointCloudGenerator nesnesi yok ya da eklenmemis.
	if (generators.empty())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < generators.size(); i++)
		{
			patch = generators[i]->captureFor();
			pointCloud = pointCloud + patch;
		}
		return true;
	}
}

bool PointCloudInterface::record()
{
	// PointCloudRecorder nesnesi yok ya da eklenmemis.
	if (recorder == NULL)
	{
		return false;
	}
	else
	{
		recorder->save(pointCloud);
		return true;
	}
}