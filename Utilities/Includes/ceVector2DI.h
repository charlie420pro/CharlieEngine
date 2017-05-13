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
		/* Declaración de operadores aritméticos                                 												*/
		/************************************************************************************************************************/
		ceVector2DI operator+(const ceVector2DI& V) const;		//Suma
		ceVector2DI operator-(const ceVector2DI& V) const;		//Resta
		ceVector2DI operator*(float Scale) const;				//Multiplicación (escalar)
		ceVector2DI operator*(const ceVector2DI& V) const;		//Multiplicación (vector)
		ceVector2DI operator/(float Scale) const;							//División (escalar)
		ceVector2DI operator/(const ceVector2DI& V) const;					//División (vector)



		/************************************************************************************************************************/
		/* Declaración de operadores lógicos                                     												*/
		/************************************************************************************************************************/
		bool operator==(const ceVector2DI& V) const;						//Igual a
		bool operator!=(const ceVector2DI& V) const;						//Diferente a
		bool operator<(const ceVector2DI& Other) const;					//Menor que
		bool operator>(const ceVector2DI& Other) const;					//Mayor que
		bool operator<=(const ceVector2DI& Other) const;					//Menor o igual a
		bool operator>=(const ceVector2DI& Other) const;					//Mayor o igual a
		bool Equals(const ceVector2DI& V, int32 Tolerance) const;			//Compara si son "iguales" manejando una toleracia

	    /************************************************************************************************************************/
	    /* Declaración de operadores de asignación compuesta                    												*/
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
