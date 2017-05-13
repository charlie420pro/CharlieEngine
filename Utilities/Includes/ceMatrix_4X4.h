#pragma once
#include "ceMath.h"
#include "ceVector4D.h"

namespace ceEngineSDK
{
	class ceVector4D;
	class ceVector3D;

#pragma push(pack)
#pragma pack(16)
	class CE_UTILITY_EXPORT ceMatrix_4X4
	{
	public:

		/************************************************************************/
		/*                                                                      */
		/************************************************************************/
		union
		{
			struct
			{

				float X0, Y0, Z0, W0,
					X1, Y1, Z1, W1,
					X2, Y2, Z2, W2,
					X3, Y3, Z3, W3;
			}m;
			float MatrixLikeArray[16];
			float MatrixLikeMatrix[4][4];
		};
		/************************************************************************/
		/*                                                                      */
		/************************************************************************/
		 ceMatrix_4X4();
		 ~ceMatrix_4X4();
		 ceMatrix_4X4(	float fX0, float fY0, float fZ0, float fW0,
						float fX1, float fY1, float fZ1, float fW1,
						float fX2, float fY2, float fZ2, float fW2,
						float fX3, float fY3, float fZ3, float fW3);


		/************************************************************************/
		/*                                                                      */
		/************************************************************************/
		 ceMatrix_4X4 operator+(const ceMatrix_4X4& M);
		 ceMatrix_4X4 operator-(const ceMatrix_4X4& M);
		 ceMatrix_4X4 operator*(const ceMatrix_4X4& M);
		 ceMatrix_4X4 operator/(const ceMatrix_4X4& M);
		 ceMatrix_4X4 operator*(float Value);

		 ceVector4D operator*(const ceVector4D& V);
		 ceVector4D operator/(const ceVector4D& V);

		/************************************************************************/
		/*                                                                      */
		/************************************************************************/
		 ceMatrix_4X4& operator+=(const ceMatrix_4X4& M);
		 ceMatrix_4X4& operator-=(const ceMatrix_4X4& M);
		 ceMatrix_4X4& operator*=(const ceMatrix_4X4& M);
		 ceMatrix_4X4& operator/=(const ceMatrix_4X4& M);

		/************************************************************************/
		/*                                                                      */
		/************************************************************************/
		 
		 

		 ceMatrix_4X4 Transpose();
		 ceMatrix_4X4 Inverse(const ceMatrix_4X4& A); //! Falta la inversa

		 void Identity(void);
		 void Zero(void);
		 void PerspectiveFOVLH(float zNear, float zFar, float FOV, float AspectRatio);
		 void LookAtLeftH(const ceVector4D EyePos, const ceVector4D Target, const ceVector4D Up);

		/************************************************************************/
		/*                                                                      */
		/************************************************************************/
		 ceMatrix_4X4 Translation(const ceVector4D& V);
		 ceMatrix_4X4 Scaling(const ceVector4D& V);
		 ceMatrix_4X4 Rotate(const ceVector4D& V); //! Falta Rotate
		 ceMatrix_4X4 RotateX(float fvalue);
		 ceMatrix_4X4 RotateY(float fValue);
		 ceMatrix_4X4 RotateZ(float fvalue);

	};
#pragma pop(pack)
}