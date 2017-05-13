#pragma once
#include "ceMath.h"

namespace ceEngineSDK
{
	class CE_UTILITY_EXPORT ceVector3D
	{
	public:

		float X;
		float Y;
		float Z;

		/************************************************************************************************************************/
		/* Constructores   y Destructores                                                     									*/
		/************************************************************************************************************************/
		ceVector3D();
		ceVector3D(float InX, float InY, float InZ);

		~ceVector3D();

		/************************************************************************************************************************/
		/* Declaración de operadores aritméticos                                 												*/
		/************************************************************************************************************************/
		ceVector3D operator+(const ceVector3D& V) const;		//Suma
		ceVector3D operator-(const ceVector3D& V) const;		//Resta
		ceVector3D operator*(float Scale) const;				//Multiplicación (escalar)
		ceVector3D operator*(const ceVector3D& V) const;		//Multiplicación (vector)
		ceVector3D operator/(float Scale) const;							//División (escalar)
		ceVector3D operator/(const ceVector3D& V) const;					//División (vector)



		/************************************************************************************************************************/
		/* Declaración de operadores lógicos                                     												*/
		/************************************************************************************************************************/
		bool operator==(const ceVector3D& V) const;						//Igual a
		bool operator!=(const ceVector3D& V) const;						//Diferente a
		bool operator<(const ceVector3D& Other) const;					//Menor que
		bool operator>(const ceVector3D& Other) const;					//Mayor que
		bool operator<=(const ceVector3D& Other) const;					//Menor o igual a
		bool operator>=(const ceVector3D& Other) const;					//Mayor o igual a
		bool Equals(const ceVector3D& V, float Tolerance) const;			//Compara si son "iguales" manejando una toleracia

	    /************************************************************************************************************************/
	    /* Declaración de operadores de asignación compuesta                    												*/
	    /************************************************************************************************************************/
		ceVector3D operator+=(const ceVector3D& V);
		ceVector3D operator-=(const ceVector3D& V);
		ceVector3D operator*=(float Scale);
		ceVector3D operator/=(float Scale);
		ceVector3D operator*=(const ceVector3D& V);
		ceVector3D operator/=(const ceVector3D& V);

		float operator|(const ceVector3D& V) const;			//Dot Product
		float operator^(const ceVector3D& V) const;			//Cross Product

		float Magnitud(const ceVector3D& V);
		ceVector3D Normalize(const ceVector3D& V);
		float DotProduct(const ceVector3D& A, const ceVector3D& B);
		ceVector3D Cross3(const ceVector3D& V, const ceVector3D& B);

	};

}
