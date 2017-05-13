#pragma once

#include "ceMath.h"

namespace ceEngineSDK
{
	class CE_UTILITY_EXPORT ceVector2D
	{
	public:

		float X;
		float Y;

		/************************************************************************************************************************/
		/* Constructores   y Destructores                                                     									*/
		/************************************************************************************************************************/
		 ceVector2D();
		 ceVector2D(float InX, float InY);

		 ~ceVector2D();

		/************************************************************************************************************************/
		/* Declaración de operadores aritméticos                                 												*/
		/************************************************************************************************************************/
		ceVector2D operator+(const ceVector2D& V) const;		//Suma
		ceVector2D operator-(const ceVector2D& V) const;		//Resta
		ceVector2D operator*(float Scale) const;				//Multiplicación (escalar)
		ceVector2D operator*(const ceVector2D& V) const;		//Multiplicación (vector)
		ceVector2D operator/(float Scale) const;							//División (escalar)
		ceVector2D operator/(const ceVector2D& V) const;					//División (vector)
		
		

		/************************************************************************************************************************/
		/* Declaración de operadores lógicos                                     												*/
		/************************************************************************************************************************/
		bool operator==(const ceVector2D& V) const;						//Igual a
		bool operator!=(const ceVector2D& V) const;						//Diferente a
		bool operator<(const ceVector2D& Other) const;					//Menor que
		bool operator>(const ceVector2D& Other) const;					//Mayor que
		bool operator<=(const ceVector2D& Other) const;					//Menor o igual a
		bool operator>=(const ceVector2D& Other) const;					//Mayor o igual a
		bool Equals(const ceVector2D& V, float Tolerance) const;			//Compara si son "iguales" manejando una toleracia

		/************************************************************************************************************************/
		/* Declaración de operadores de asignación compuesta                    												*/
		/************************************************************************************************************************/
		ceVector2D& operator+=(const ceVector2D& V);
		ceVector2D& operator-=(const ceVector2D& V);
		ceVector2D& operator*=(float Scale);
		ceVector2D& operator/=(float Scale);
		ceVector2D& operator*=(const ceVector2D& V);
		ceVector2D& operator/=(const ceVector2D& V);

		float operator|(const ceVector2D& V) const;			//Dot Product
		float operator^(const ceVector2D& V) const;			//Cross Product

		float Magnitud(const ceVector2D& V);
		ceVector2D Normalize(const ceVector2D& V);
		float DotProduct(const ceVector2D& A, const ceVector2D& B);

		
	};

}