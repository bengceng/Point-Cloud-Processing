/**
* @file Transform.h
* @Author Bengisu Sahin (sahin.bengisu00@gmail.com)
* @date December,2021
*/

//! Transform Sinifi
/*!
  Ýki koordinat duzleminin orijinleri arasindaki uzakligi ve rotasyon acilarini alir
  ve donusum matrisini olusturur.
  Nokta ya da nokta bulutunu bu donusume tabi tutarak donusturulmus
  nokta ya da nokta bulutunu dondurur.
*/

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Point.h"
#include "PointCloud.h"

class Transform {

private:

	double angles[3];
	double trans[3];
	double transMatrix[4][4];
	//double rotationMatrix[3][3];
public:

	//TRANSFORM CONSTRUCTOR
	Transform();


	//TRANSFORM DECONSTRUCTOR
	~Transform();


	//SETTERS

	void set_angles(double first_angle, double second_angle, double third_angle);
	/**
	* @brief			        : Aci degerlerini alarak transform nesnesinde set etmemizi saglar.
	* @parametre1  first_angle	:   1. aci
	* @parammetre2 second_angle	:   2. aci
	* @parammetre3 third_angle	:   3. aci
	*/

	void set_trans(double transX, double transY, double transZ);
	/**
*	@brief			        :	Transform nesnesi icin trans dizisi icerisine koordinant sisteminin orijininin base koordinant
*						        sisteminin orijinine olan uzakligini verilen degerler ile duzenleyen bir fonksiyon.
*	@parametre1	    transX	:	x ekseni icin donusum degeri.
*	@parammetre2	transY	:	y ekseni icin donusum degeri.
*	@parammetre3	transZ	:	z ekseni icin donusum degeri.
*/

	void setTranslation(double tr[3]);
	/*
	@brief			:Bu metot translation matrisini hesaplar.
	@parametre      :Translation degerlerini iceren 3x3 luk double tipinde matrix
	*/

	void setRotation(double ang[3]);
	/*
	@brief			: Bu metot ang matrixinde tutulan aci degerlerine
					  gore sin ve cos fonksiyonlariyla rotasyon matrisini olusturur.
	@parametre      : Aci degerlerini iceren 3x3 luk double tipinde matrix
	*/


	//GETTERS

	double* get_trans() const;
	/*
	@brief			: Bu metot donusum degerlerini iceren diziyi dondurur.
	*/
	double* get_angles() const;
	/*
	@brief			: Bu metot aci degerlerini iceren diziyi dondurur.
	*/
	void display_translation() const;
	/*
	@brief			: Bu metot translation matrisinin ciktisini verir.
	*/
	void display_rotation() const;
	/*
	@brief			: Bu metot rotation matrisinin ciktisini verir.
	*/
	//DO

	Point doTransform(Point p);
	/**
	* @brief			: Bu fonksiyon alinan nokta nesnesinin donusturulmesini saglar.
	* @parametre p		: Point sinifina ait bir nesne
	*/
	PointCloud doTransform(PointCloud &pc);
	/**
	* @brief			: Bu fonksiyon alinan nokta bulutu nesnesinin donusturulmesini saglar.
	* @parametre pc		: PointCloud sinifina ait bir nesne
	*/

};

#endif // !TRANSFORM_H