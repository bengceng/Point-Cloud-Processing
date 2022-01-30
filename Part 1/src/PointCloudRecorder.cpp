//Yigit Efe Cosgun
#include "PointCloudRecorder.h"

//! PointCloudRecorder s�n�f�n�n yap�c� fonksiyonudur.
PointCloudRecorder::PointCloudRecorder()
{
}
/*!
\return dosya adi g�nder
*/
string PointCloudRecorder::getFileName()
{
	return filename;
}

void PointCloudRecorder::setFileName(string name)
{
	filename = name;
}
/*!
\param:  PointCloud pc
\return: bool
*/
bool PointCloudRecorder::save(const PointCloud& pc)
{
	ofstream outputFile;
	outputFile.open(filename);

	if (outputFile.is_open())
	{
		cout << "Cikti dosyasi basariyla acildi." << endl << endl;
		outputFile << fixed << showpoint;
		outputFile << setprecision(3);
		for (int i = 0; i < pc.GetPointNumber(); i++)
		{
			outputFile << setw(9) << pc.GetPoints(i).getX() << setw(9) << pc.GetPoints(i).getY() << setw(9) << pc.GetPoints(i).getZ() << endl;
		}
		outputFile.close();
		return true;
	}
	else
	{
		cout << "Cikti dosyasi acilamadi lutfen kontrol ediniz!" << endl;
	}

	return false;
}
