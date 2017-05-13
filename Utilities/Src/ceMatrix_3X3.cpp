#include "ceMatrix_3X3.h"


namespace ceEngineSDK
{
	/************************************************************************/
	/* Constructor Default													*/
	/************************************************************************/
	ceMatrix_3X3::ceMatrix_3X3()
	{
		
	}

	/************************************************************************/
	/* Constructor con Parametros											*/
	/************************************************************************/
	ceMatrix_3X3::ceMatrix_3X3(float fX0, float fY0, float fZ0,
		float fX1, float fY1, float fZ1,
		float fX2, float fY2, float fZ2)
	{
		fX0 = m.X0, fY0 = m.Y0, fZ0 = m.Z0,
		fX1 = m.X1, fY1 = m.Y1, fZ1 = m.Z1,
		fX2 = m.X2, fY2 = m.Y2, fZ2 = m.Z2;
	}

	ceMatrix_3X3::~ceMatrix_3X3()
	{
	}

	/************************************************************************/
	/* Operador Suma														*/
	/************************************************************************/
	ceMatrix_3X3 ceMatrix_3X3::operator+(const ceMatrix_3X3& M)
	{
		return ceMatrix_3X3(m.X0 + M.m.X0, m.Y0 + M.m.Y0, m.Z0 + M.m.Z0,
							m.X1 + M.m.X1, m.Y1 + M.m.Y1, m.Z1 + M.m.Z1,
							m.X2 + M.m.X2, m.Y2 + M.m.Y2, m.Z2 + M.m.Z2);
	}

	/************************************************************************/
	/* Operador Resta														*/
	/************************************************************************/
	ceMatrix_3X3 ceMatrix_3X3::operator-(const ceMatrix_3X3& M)
	{
		return ceMatrix_3X3(m.X0 - M.m.X0, m.Y0 - M.m.Y0, m.Z0 - M.m.Z0,
							m.X1 - M.m.X1, m.Y1 - M.m.Y1, m.Z1 - M.m.Z1,
							m.X2 - M.m.X2, m.Y2 - M.m.Y2, m.Z2 - M.m.Z2);
	}

	/************************************************************************/
	/* Operador Multiplicación												*/
	/************************************************************************/
	ceMatrix_3X3 ceMatrix_3X3::operator*(const ceMatrix_3X3 & M)
	{
		return ceMatrix_3X3(m.X0 * M.m.X0, m.Y0 * M.m.X1, m.Z0 * M.m.X2,
							m.X1 * M.m.Y0, m.Y1 * M.m.Y1, m.Z1 * M.m.Y2,
							m.X2 * M.m.Z0, m.Y2 * M.m.Z1, m.Z2 * M.m.Z2);
	}

	/************************************************************************/
	/* Operador Division													*/
	/************************************************************************/
	ceMatrix_3X3 ceMatrix_3X3::operator/(const ceMatrix_3X3 & M)
	{
		return ceMatrix_3X3(m.X0 / M.m.X0, m.Y0 / M.m.X1, m.Z0 / M.m.X2,
							m.X1 / M.m.Y0, m.Y1 / M.m.Y1, m.Z1 / M.m.Y2,
							m.X2 / M.m.Z0, m.Y2 / M.m.Z1, m.Z2 / M.m.Z2);
	}

	/************************************************************************/
	/* Operador Multiplicación por un Escalar								*/
	/************************************************************************/
	ceMatrix_3X3 ceMatrix_3X3::operator*(float Value)
	{
		return ceMatrix_3X3(m.X0 * Value, m.Y0 *Value, m.Z0 * Value,
							m.X1 * Value, m.Y1 *Value, m.Z1 * Value,
							m.X2 * Value, m.Y2 *Value, m.Z2 * Value);
	}
	/************************************************************************/
	/* Multiplicacion de Matriz por Vector                                  */
	/************************************************************************/
	ceVector3D ceMatrix_3X3::operator*(const ceVector3D & V)
	{
		return ceVector3D((	 m.X0 * V.X + m.Y0  *V.X + m.Z0 * V.X),
							(m.X1 * V.Y + m.Y1  *V.Y + m.Z1 * V.Y),
							(m.X2 * V.Z + m.Y2  *V.Z + m.Z2 * V.Z));
	}

	ceVector3D ceMatrix_3X3::operator/(const ceVector3D & V)
	{
		return ceVector3D(	(m.X0 / V.X + m.Y0 / V.X + m.Z0 / V.X),
							(m.X1 / V.Y + m.Y1 / V.Y + m.Z1 / V.Y),
							(m.X2 / V.Z + m.Y2 / V.Z + m.Z2 / V.Z));
	}
	/************************************************************************/
	/* Operador Mas igual de matiz											*/
	/************************************************************************/
	ceMatrix_3X3& ceMatrix_3X3::operator+=(const ceMatrix_3X3 & M)
	{
		m.X0 += M.m.X0;	m.Y0 += M.m.Y0; m.Z0 += M.m.Z0;
		m.X1 += M.m.X1; m.Y1 += M.m.Y1; m.Z1 += M.m.Z1;
		m.X2 += M.m.X2;	m.Y2 += M.m.Y2; m.Z2 += M.m.Z2;

		return *this;
	}
	/************************************************************************/
	/* Operador menos igual de matriz										*/
	/************************************************************************/
	ceMatrix_3X3& ceMatrix_3X3::operator-=(const ceMatrix_3X3 & M)
	{
		m.X0 -= M.m.X0;	m.Y0 -= M.m.Y0; m.Z0 -= M.m.Z0;
		m.X1 -= M.m.X1; m.Y1 -= M.m.Y1; m.Z1 -= M.m.Z1;
		m.X2 -= M.m.X2;	m.Y2 -= M.m.Y2; m.Z2 -= M.m.Z2;

		return *this;
	}
	/************************************************************************/
	/* Operador por igual de matriz											*/
	/************************************************************************/
	ceMatrix_3X3& ceMatrix_3X3::operator*=(const ceMatrix_3X3& M)
	{
		m.X0 *= M.m.X0;	m.Y0 *= M.m.Y0; m.Z0 *= M.m.Z0;
		m.X1 *= M.m.X1; m.Y1 *= M.m.Y1; m.Z1 *= M.m.Z1;
		m.X2 *= M.m.X2;	m.Y2 *= M.m.Y2; m.Z2 *= M.m.Z2;

		return *this;
	}
	/************************************************************************/
	/* Operador entre igual de matriz                                       */
	/************************************************************************/
	ceMatrix_3X3& ceMatrix_3X3::operator/=(const ceMatrix_3X3 & M)
	{
		m.X0 /= M.m.X0;	m.Y0 /= M.m.Y0; m.Z0 /= M.m.Z0;
		m.X1 /= M.m.X1; m.Y1 /= M.m.Y1; m.Z1 /= M.m.Z1;
		m.X2 /= M.m.X2;	m.Y2 /= M.m.Y2; m.Z2 /= M.m.Z2;

		return *this;
	}
	/************************************************************************/
	/* Matriz Inicializada en 0                                             */
	/************************************************************************/
	ceMatrix_3X3 ceMatrix_3X3::Zero(void)
	{
		ceMatrix_3X3 Result;
		for (int i = 0; i < 9; i++)
			Result.MatrixLikeArray[i] = 0;
		return Result;
	}
	/************************************************************************/
	/* Matriz identidad														*/
	/************************************************************************/
	ceMatrix_3X3 ceMatrix_3X3::Identity(void)
	{
		ceMatrix_3X3 identity = Zero();
		identity.m.X0 = 1;
		identity.m.Y1 = 1;
		identity.m.Z2 = 1;
		return identity;
	}
	/************************************************************************/
	/* Transpuesta de una matriz											*/
	/************************************************************************/
	ceMatrix_3X3 ceMatrix_3X3::Transpose(const ceMatrix_3X3 & A)
	{
		ceMatrix_3X3 MatTemp;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				MatTemp.MatrixLikeMatrix[j][i] = A.MatrixLikeMatrix[i][j];
		return MatTemp;
	}
	/************************************************************************/
	/*  Inversa de una matriz												*/
	/************************************************************************/
	ceMatrix_3X3 ceMatrix_3X3::Inverse(const ceMatrix_3X3 & A)
	{
		//TODO: Agregar implementacion
		return ceMatrix_3X3();
	}
	/************************************************************************/
	/* Matriz de translacion												*/
	/************************************************************************/
	ceMatrix_3X3 ceMatrix_3X3::Translation(const ceVector3D & V)
	{
		return ceMatrix_3X3(1, 0, 0,
							0, 1, 0,
							V.X, V.Y, V.Z);
	}
	/************************************************************************/
	/* Matriz de escalacion													*/
	/************************************************************************/
	ceMatrix_3X3 ceMatrix_3X3::Scaling(const ceVector3D & V)
	{
		return ceMatrix_3X3(V.X, 0, 0,
							0, V.Y, 0,
							0, 0, V.Z);
	}
	/************************************************************************/
	/* Matriz de rotacion													*/
	/************************************************************************/
	ceMatrix_3X3 ceMatrix_3X3::Rotate(const ceVector3D & V)
	{
		//TODO: Agregar implementacion de Rotate
		return ceMatrix_3X3();
	}	

}