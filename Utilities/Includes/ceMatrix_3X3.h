#pragma once
#include "ceMath.h"
#include "ceVector3D.h"

namespace ceEngineSDK
{
	class CE_UTILITY_EXPORT ceMatrix_3X3
	{
	public:

		/************************************************************************/
		/*                                                                      */
		/************************************************************************/
		union
		{
			struct 
			{
				float X0, Y0, Z0,
				X1, Y1, Z1,
				X2, Y2, Z2;
			}m;

			float MatrixLikeArray[9];
			float MatrixLikeMatrix[3][3];
		};
		/************************************************************************/
		/*                                                                      */
		/************************************************************************/
		 ceMatrix_3X3();
		 ~ceMatrix_3X3();
		 ceMatrix_3X3(float fX0, float fY0, float fZ0,
			float fX1, float fY1, float fZ1,
			float fX2, float fY2, float fZ2);
		

		/************************************************************************/
		/*                                                                      */
		/************************************************************************/
		 ceMatrix_3X3 operator+(const ceMatrix_3X3& M);
		 ceMatrix_3X3 operator-(const ceMatrix_3X3& M);
		 ceMatrix_3X3 operator*(const ceMatrix_3X3& M);
		 ceMatrix_3X3 operator/(const ceMatrix_3X3& M);

		 ceMatrix_3X3 operator*(float Value);
		
		 ceVector3D operator*(const ceVector3D& V);
		 ceVector3D operator/(const ceVector3D& V);

		/************************************************************************/
		/*                                                                      */
		/************************************************************************/
		ceMatrix_3X3& operator+=(const ceMatrix_3X3& M);
		ceMatrix_3X3& operator-=(const ceMatrix_3X3& M);
		ceMatrix_3X3& operator*=(const ceMatrix_3X3& M);
		ceMatrix_3X3& operator/=(const ceMatrix_3X3& M);

		/************************************************************************/
		/*                                                                      */
		/************************************************************************/
		ceMatrix_3X3 Zero(void);
		ceMatrix_3X3 Identity(void);
		ceMatrix_3X3 Transpose(const ceMatrix_3X3& A);
		ceMatrix_3X3 Inverse(const ceMatrix_3X3& A); //! Falta la inversa
		
		/************************************************************************/
		/*                                                                      */
		/************************************************************************/
		ceMatrix_3X3 Translation(const ceVector3D& V);
		ceMatrix_3X3 Scaling(const ceVector3D& V);
		ceMatrix_3X3 Rotate(const ceVector3D& V); //! Falta Rotate
		
	};
}

