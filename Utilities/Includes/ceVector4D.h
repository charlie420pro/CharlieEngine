#pragma once
#include "ceMath.h"

namespace ceEngineSDK
{
	class CE_UTILITY_EXPORT ceVector4D
	{
	public:

		float X;
		float Y;
		float Z;
		float W;

		/************************************************************************************************************************/
		/* Constructores   y Destructores                                                     									*/
		/************************************************************************************************************************/
		ceVector4D();
		ceVector4D(float InX, float InY, float InZ, float InW);

		~ceVector4D();

		/************************************************************************************************************************/
		/* Declaración de operadores aritméticos                                 												*/
		/************************************************************************************************************************/
		ceVector4D operator+(const ceVector4D& V) const;		//Suma
		ceVector4D operator-(const ceVector4D& V) const;		//Resta
		ceVector4D operator*(float Scale) const;				//Multiplicación (escalar)
		ceVector4D operator*(const ceVector4D& V) const;		//Multiplicación (vector)
		ceVector4D operator/(float Scale) const;							//División (escalar)
		ceVector4D operator/(const ceVector4D& V) const;					//División (vector)



		/************************************************************************************************************************/
		/* Declaración de operadores lógicos                                     												*/
		/************************************************************************************************************************/
		bool operator==(const ceVector4D& V) const;						//Igual a
		bool operator!=(const ceVector4D& V) const;						//Diferente a
		bool operator<(const ceVector4D& Other) const;					//Menor que
		bool operator>(const ceVector4D& Other) const;					//Mayor que
		bool operator<=(const ceVector4D& Other) const;					//Menor o igual a
		bool operator>=(const ceVector4D& Other) const;					//Mayor o igual a
		bool Equals(const ceVector4D& V, float Tolerance) const;			//Compara si son "iguales" manejando una toleracia

		/************************************************************************************************************************/
		/* Declaración de operadores de asignación compuesta                    												*/
		/************************************************************************************************************************/
		ceVector4D operator+=(const ceVector4D& V);
		ceVector4D operator-=(const ceVector4D& V);
		ceVector4D operator*=(float Scale);
		ceVector4D operator/=(float Scale);
		ceVector4D operator*=(const ceVector4D& V);
		ceVector4D operator/=(const ceVector4D& V);

		float operator|(const ceVector4D& V) const;			//Dot Product
		float operator^(const ceVector4D& V) const;			//Cross Product

		float Magnitud(const ceVector4D& V);
		ceVector4D Normalize(const ceVector4D& V);
		float Dot(const ceVector4D& B);
		ceVector4D Cross(const ceVector4D& V, const ceVector4D& B);

	};

}

