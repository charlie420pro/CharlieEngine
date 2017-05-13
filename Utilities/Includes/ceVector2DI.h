#pragma once

#include "ceMath.h"

namespace ceEngineSDK
{
	class CE_UTILITY_EXPORT ceVector2DI
	{
	public:

		int32 X;
		int32 Y;

		/************************************************************************************************************************/
		/* Constructores   y Destructores                                                     									*/
		/************************************************************************************************************************/
		ceVector2DI();
		ceVector2DI(int32 InX, int32 InY);

		~ceVector2DI();

		/************************************************************************************************************************/
		/* Declaraci�n de operadores aritm�ticos                                 												*/
		/************************************************************************************************************************/
		ceVector2DI operator+(const ceVector2DI& V) const;		//Suma
		ceVector2DI operator-(const ceVector2DI& V) const;		//Resta
		ceVector2DI operator*(float Scale) const;				//Multiplicaci�n (escalar)
		ceVector2DI operator*(const ceVector2DI& V) const;		//Multiplicaci�n (vector)
		ceVector2DI operator/(float Scale) const;							//Divisi�n (escalar)
		ceVector2DI operator/(const ceVector2DI& V) const;					//Divisi�n (vector)



		/************************************************************************************************************************/
		/* Declaraci�n de operadores l�gicos                                     												*/
		/************************************************************************************************************************/
		bool operator==(const ceVector2DI& V) const;						//Igual a
		bool operator!=(const ceVector2DI& V) const;						//Diferente a
		bool operator<(const ceVector2DI& Other) const;					//Menor que
		bool operator>(const ceVector2DI& Other) const;					//Mayor que
		bool operator<=(const ceVector2DI& Other) const;					//Menor o igual a
		bool operator>=(const ceVector2DI& Other) const;					//Mayor o igual a
		bool Equals(const ceVector2DI& V, int32 Tolerance) const;			//Compara si son "iguales" manejando una toleracia

	    /************************************************************************************************************************/
	    /* Declaraci�n de operadores de asignaci�n compuesta                    												*/
	    /************************************************************************************************************************/
		ceVector2DI operator+=(const ceVector2DI& V);
		ceVector2DI operator-=(const ceVector2DI& V);
		ceVector2DI operator*=(int32 Scale);
		ceVector2DI operator/=(int32 Scale);
		ceVector2DI operator*=(const ceVector2DI& V);
		ceVector2DI operator/=(const ceVector2DI& V);

		int32 operator|(const ceVector2DI& V) const;			//Dot Product
		int32 operator^(const ceVector2DI& V) const;			//Cross Product

		float Magnitud(const ceVector2DI& V);
		ceVector2DI Normalize(const ceVector2DI& V);
		int32 DotProduct(const ceVector2DI& A, const ceVector2DI& B);


	};

}
