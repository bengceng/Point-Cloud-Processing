/**
* @file  : Transform.h
* @Author: Bengisu Sahin (sahin.bengisu00@gmail.com)
* @date  : 11.01.2022
*/

//! Transform Sinifi
/*!
  Iki koordinat duzleminin orijinleri arasindaki uzakligi ve rotasyon acilarini alir
  ve donusum matrisini olusturur.
  Nokta ya da nokta bulutunu bu donusume tabi tutarak donusturulmus
  nokta ya da nokta bulutunu dondurur.
*/

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Point.h"
#include "PointCloud.h"
#include<Eigen/Dense>
#include<iostream>
#include<iomanip>

using namespace std;

class Transform {

private:
	/*acilari tutan vector*/
	Eigen::Vector3d angles;
	/*dondurme degerlerini tutan vector*/
	Eigen::Vector3d trans;
	/*transformation matrixi*/
	Eigen::Matrix4d transMatrix;

public:

	//TRANSFORM CONSTRUCTOR
	Transform();


	//TRANSFORM DECONSTRUCTOR
	~Transform();


	//SETTERS

	void set_angles(double first_angle, double second_angle, double third_angle);
	/**
	* @brief			        :  Aci degerlerini alarak transform nesnesinde set etmemizi saglar.
	* @parametre1  first_angle	:  1. aci
	* @parammetre2 second_angle	:  2. aci
	* @parammetre3 third_angle	:  3. aci
	*/

	void set_trans(double transX, double transY, double transZ);
	/**
*	@brief			        :	Transform nesnesi icin trans dizisi icerisine koordinant
								sisteminin orijininin base koordinant  sisteminin
*						        orijinine olan uzakligini verilen degerler ile duzenleyen bir fonksiyon.
*	@parametre1	    transX	:	x ekseni icin donusum degeri.
*	@parammetre2	transY	:	y ekseni icin donusum degeri.
*	@parammetre3	transZ	:	z ekseni icin donusum degeri.
*/
	void setTranslation(Eigen::Vector3d tr);
	/*
	@brief			:Bu metot translation matrisini hesaplar.
	@parametre      :Translation degerlerini iceren vektör
	*/
	void setTranslation(double tr[3]);
	/*
	@brief			:Bu metot translation matrisini hesaplar.
	@parametre      :Translation degerlerini iceren double tipinde matrix
	*/
	void setRotation(Eigen::Vector3d ang);
	/*
	@brief			: Bu metot ang vectorunde tutulan aci degerlerine
					  gore sin ve cos fonksiyonlariyla rotasyon matrisini olusturur.
	@parametre      : Aci degerlerini iceren vector
	*/
	void setRotation(double ang[3]);
	/*
	@brief			: Bu metot ang matrixinde tutulan aci degerlerine
					  gore sin ve cos fonksiyonlariyla rotasyon matrisini olusturur.
	@parametre      : Aci degerlerini iceren double tipinde matrix
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
	list<Point> doTransform(list<Point> lp);
	/**
	* @brief			: Bu fonksiyon point list degiskeninin donusturulmesini saglar.
	* @parametre pc		: Point list degiskeni
	*/
	PointCloud doTransform(PointCloud &pc);
	/**
	* @brief			: Bu fonksiyon alinan nokta bulutu nesnesinin donusturulmesini saglar.
	* @parametre pc		: PointCloud sinifina ait bir nesne
	*/

};

#endif // !TRANSFORM_H