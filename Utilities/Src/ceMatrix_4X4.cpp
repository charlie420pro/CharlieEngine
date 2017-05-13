#include "ceMatrix_4X4.h"


namespace ceEngineSDK
{
	/************************************************************************/
	/* Constructor Default													*/
	/************************************************************************/
	ceMatrix_4X4::ceMatrix_4X4()
	{
		m.X0 = 0, m.Y0 = 0, m.Z0 = 0, m.W0 = 0,
		m.X1 = 0, m.Y1 = 0, m.Z1 = 0, m.W1 = 0,
		m.X2 = 0, m.Y2 = 0, m.Z2 = 0, m.W2 = 0,
		m.X3 = 0, m.Y3 = 0, m.Z3 = 0, m.W3 = 0;
	}

	/************************************************************************/
	/* Constructor con Parametros											*/
	/************************************************************************/
	ceMatrix_4X4::ceMatrix_4X4(float fX0, float fY0, float fZ0,float fW0,
		float fX1, float fY1, float fZ1, float fW1,
		float fX2, float fY2, float fZ2, float fW2,
		float fX3, float fY3, float fZ3, float fW3)
	{
		fX0 = m.X0, fY0 = m.Y0, fZ0 = m.Z0, fW0 = m.W0,
		fX1 = m.X1, fY1 = m.Y1, fZ1 = m.Z1, fW1 = m.W1,
		fX2 = m.X2, fY2 = m.Y2, fZ2 = m.Z2, fW2 = m.W2,
		fX3 = m.X3, fY3 = m.Y3, fZ3 = m.Z3, fW3 = m.W3;
	}

	ceMatrix_4X4::~ceMatrix_4X4()
	{
	}

	/************************************************************************/
	/* Operador Suma														*/
	/************************************************************************/
	ceMatrix_4X4 ceMatrix_4X4::operator+(const ceMatrix_4X4& M)
	{
		return ceMatrix_4X4(m.X0 + M.m.X0, m.Y0 + M.m.Y0, m.Z0 + M.m.Z0, m.W0 + M.m.W0,
			m.X1 + M.m.X1, m.Y1 + M.m.Y1, m.Z1 + M.m.Z1, m.W1 + M.m.W1,
			m.X2 + M.m.X2, m.Y2 + M.m.Y2, m.Z2 + M.m.Z2, m.W2 + M.m.W2,
			m.X3 + M.m.X3, m.Y3 + M.m.Y3, m.Z3 + M.m.Z3, m.W3 + M.m.W3);
	}

	/************************************************************************/
	/* Operador Resta														*/
	/************************************************************************/
	ceMatrix_4X4 ceMatrix_4X4::operator-(const ceMatrix_4X4& M)
	{
		return ceMatrix_4X4(m.X0 - M.m.X0, m.Y0 - M.m.Y0, m.Z0 - M.m.Z0, m.W0 - M.m.W0,
							m.X1 - M.m.X1, m.Y1 - M.m.Y1, m.Z1 - M.m.Z1, m.W1 - M.m.W1,
							m.X2 - M.m.X2, m.Y2 - M.m.Y2, m.Z2 - M.m.Z2, m.W2 - M.m.W2,
							m.X3 - M.m.X3, m.Y3 - M.m.Y3, m.Z3 - M.m.Z3, m.W3 - M.m.W3);
	}

	/************************************************************************/
	/* Operador Multiplicación												*/
	/************************************************************************/
	ceMatrix_4X4 ceMatrix_4X4::operator*(const ceMatrix_4X4 & M)
	{
		return ceMatrix_4X4(m.X0 * M.m.X0, m.Y0 * M.m.X1, m.Z0 * M.m.X2, m.W0 * M.m.X3,
							m.X1 * M.m.Y0, m.Y1 * M.m.Y1, m.Z1 * M.m.Y2, m.W1 * M.m.Y3,
							m.X2 * M.m.Z0, m.Y2 * M.m.Z1, m.Z2 * M.m.Z2, m.W2 * M.m.Z3,
							m.X3 * M.m.W0, m.Y3 * M.m.W1, m.Z3 * M.m.W2, m.W3 * M.m.W3);
	}

	/************************************************************************/
	/* Operador Division													*/
	/************************************************************************/
	ceMatrix_4X4 ceMatrix_4X4::operator/(const ceMatrix_4X4 & M)
	{
		return ceMatrix_4X4(m.X0 / M.m.X0, m.Y0 / M.m.X1, m.Z0 / M.m.X2, m.W0 / M.m.X3,
							m.X1 / M.m.Y0, m.Y1 / M.m.Y1, m.Z1 / M.m.Y2, m.W1 / M.m.Y3,
							m.X2 / M.m.Z0, m.Y2 / M.m.Z1, m.Z2 / M.m.Z2, m.W2 / M.m.Z3,
							m.X3 / M.m.W0, m.Y3 / M.m.W1, m.Z3 / M.m.W2, m.W3 / M.m.W3);
	}

	/************************************************************************/
	/* Operador Multiplicación por un Escalar								*/
	/************************************************************************/
	ceMatrix_4X4 ceMatrix_4X4::operator*(float Value)
	{
		return ceMatrix_4X4(m.X0 * Value, m.Y0 * Value, m.Z0 * Value, m.W0 * Value,
							m.X1 * Value, m.Y1 * Value, m.Z1 * Value, m.W1 * Value,
							m.X2 * Value, m.Y2 * Value, m.Z2 * Value, m.W2 * Value,
							m.X3 * Value, m.Y3 * Value, m.Z3 * Value, m.W3 * Value);
	}
	/************************************************************************/
	/* Multiplicacion de Matriz por Vector                                  */
	/************************************************************************/
	ceVector4D ceMatrix_4X4::operator*(const ceVector4D& V)
	{
		return ceVector4D(	(m.X0 * V.X + m.Y0 * V.X + m.Z0 * V.X + m.W0 * V.W),
							(m.X1 * V.Y + m.Y1 * V.Y + m.Z1 * V.Y + m.W1 * V.W),
							(m.X2 * V.Z + m.Y2 * V.Z + m.Z2 * V.Z + m.W2 * V.W ),
							(m.X3 * V.Z + m.Y3 * V.Z + m.Z3 * V.Z + m.W3 * V.W));
	}

	ceVector4D ceMatrix_4X4::operator/(const ceVector4D& V)
	{
		return ceVector4D(	(m.X0 / V.X + m.Y0 / V.X + m.Z0 / V.X + m.W0 / V.W),
							(m.X1 / V.Y + m.Y1 / V.Y + m.Z1 / V.Y + m.W1 / V.W),
							(m.X2 / V.Z + m.Y2 / V.Z + m.Z2 / V.Z + m.W2 / V.W),
							(m.X3 / V.Z + m.Y3 / V.Z + m.Z3 / V.Z + m.W3 / V.W));
	}
	/************************************************************************/
	/* Operador Mas igual de matiz											*/
	/************************************************************************/
	ceMatrix_4X4& ceMatrix_4X4::operator+=(const ceMatrix_4X4 & M) 
	{
		m.X0 += M.m.X0; m.Y0 += M.m.Y0; m.Z0 += M.m.Z0; m.W0 += M.m.W0;
		m.X1 += M.m.X1; m.Y1 += M.m.Y1; m.Z1 += M.m.Z1; m.W1 += M.m.W1;
		m.X2 += M.m.X2; m.Y2 += M.m.Y2; m.Z2 += M.m.Z2; m.W2 += M.m.W2;
		m.X3 += M.m.X3; m.Y3 += M.m.Y3; m.Z3 += M.m.Z3; m.W3 += M.m.W3;
		return *this;
	}
	/************************************************************************/
	/* Operador menos igual de matriz										*/
	/************************************************************************/
	ceMatrix_4X4& ceMatrix_4X4::operator-=(const ceMatrix_4X4 & M) 
	{
		m.X0 -= M.m.X0; m.Y0 -= M.m.Y0; m.Z0 -= M.m.Z0; m.W0 -= M.m.W0;
		m.X1 -= M.m.X1; m.Y1 -= M.m.Y1; m.Z1 -= M.m.Z1; m.W1 -= M.m.W1;
		m.X2 -= M.m.X2; m.Y2 -= M.m.Y2; m.Z2 -= M.m.Z2; m.W2 -= M.m.W2;
		m.X3 -= M.m.X3; m.Y3 -= M.m.Y3; m.Z3 -= M.m.Z3; m.W3 -= M.m.W3;
		return *this;
	}
	/************************************************************************/
	/* Operador por igual de matriz											*/
	/************************************************************************/
	ceMatrix_4X4& ceMatrix_4X4::operator*=(const ceMatrix_4X4& M) 
	{
		m.X0 *= M.m.X0; m.Y0 *= M.m.Y0; m.Z0 *= M.m.Z0; m.W0 *= M.m.W0;
		m.X1 *= M.m.X1; m.Y1 *= M.m.Y1; m.Z1 *= M.m.Z1; m.W1 *= M.m.W1;
		m.X2 *= M.m.X2; m.Y2 *= M.m.Y2; m.Z2 *= M.m.Z2; m.W2 *= M.m.W2;
		m.X3 *= M.m.X3; m.Y3 *= M.m.Y3; m.Z3 *= M.m.Z3; m.W3 *= M.m.W3;
		return *this;
	}
	/************************************************************************/
	/* Operador entre igual de matriz                                       */
	/************************************************************************/
	ceMatrix_4X4& ceMatrix_4X4::operator/=(const ceMatrix_4X4 & M)
	{
		m.X0 /= M.m.X0; m.Y0 /= M.m.Y0; m.Z0 /= M.m.Z0; m.W0 /= M.m.W0;
		m.X1 /= M.m.X1; m.Y1 /= M.m.Y1; m.Z1 /= M.m.Z1; m.W1 /= M.m.W1;
		m.X2 /= M.m.X2; m.Y2 /= M.m.Y2; m.Z2 /= M.m.Z2; m.W2 /= M.m.W2;
		m.X3 /= M.m.X3; m.Y3 /= M.m.Y3; m.Z3 /= M.m.Z3; m.W3 /= M.m.W3;
		return *this;
	}
	/************************************************************************/
	/* Matriz Inicializada en 0                                             */
	/************************************************************************/
	void ceMatrix_4X4::Zero(void)
	{
		for (int i = 0; i < 16; i++)
			this->MatrixLikeArray[i] = 0;
	}
	/************************************************************************/
	/* Matriz identidad														*/
	/************************************************************************/
	void ceMatrix_4X4::Identity(void)
	{
		this->Zero();
		this->m.X0 = 1;
		this->m.Y1 = 1;
		this->m.Z2 = 1;
		this->m.W3 = 1;	
	}
	/************************************************************************/
	/* Transpuesta de una matriz											*/
	/************************************************************************/
	ceMatrix_4X4 ceMatrix_4X4::Transpose()
	{
		ceMatrix_4X4 MatTemp;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				MatTemp.MatrixLikeMatrix[j][i] = this->MatrixLikeMatrix[i][j];

		return MatTemp;
	}
	/************************************************************************/
	/*  Inversa de una matriz												*/
	/************************************************************************/
	ceMatrix_4X4 ceMatrix_4X4::Inverse(const ceMatrix_4X4 & A)
	{
		//TODO: Implementar la inversa.
		return ceMatrix_4X4();
	}

	void ceMatrix_4X4::PerspectiveFOVLH(float zNear, float zFar, float FOV, float AspectRatio)
	{
		float yScale = 1.0f / ceMath::Tan(FOV * 0.5f);
		float xScale = yScale / AspectRatio;
		
			this->m.X0 = xScale, this->m.Y0 = 0, this->m.Z0 = 0, this->m.W0 = 0,
			this->m.X1 = 0,	this->m.Y1 = yScale, this->m.Z1 = 0, this->m.W1 = 0,
			this->m.X2 = 0,	this->m.Y2 = 0,	this->m.Z2 = zFar*zNear / (zFar - zNear), this->m.W2 = 1,
			this->m.X3 = 0,	this->m.Y3 = 0,	this->m.Z3 = -zNear*zFar / (zFar - zNear), this->m.W3 = 0;


	}

	void ceMatrix_4X4::LookAtLeftH(const ceVector4D EyePos, const ceVector4D Target, const ceVector4D Up)
	{
		ceVector4D xDir, yDir, zDir;

		zDir = Target - EyePos;
		zDir = zDir.Normalize(zDir);

		xDir = xDir.Cross(Up, zDir);
		xDir = xDir.Normalize(xDir);

		yDir = zDir.Cross(zDir, xDir);
		yDir = yDir.Normalize(yDir);

		this->m.X0 = xDir.X, this->m.Y0 = yDir.X,this->m.Z0 = zDir.X, this->m.W0 = 0,
		this->m.X1 = xDir.Y, this->m.Y1 = yDir.Y,this->m.Z1 = zDir.Y, this->m.W1 = 0,
		this->m.X2 = xDir.Z, this->m.Y2 = yDir.Z,this->m.Z2 = zDir.Z, this->m.W2 = 0,
		this->m.X3 = -xDir.Dot(EyePos),this->m.Y3 = -yDir.Dot(EyePos), this->m.Z3 = -zDir.Dot(EyePos), this->m.W3 = 1;

	}


	/************************************************************************/
	/* Matriz de translacion												*/
	/************************************************************************/
	ceMatrix_4X4 ceMatrix_4X4::Translation(const ceVector4D & V)
	{
		return ceMatrix_4X4(1, 0, 0, 0,
							0, 1, 0, 0,
							0, 0, 1, 0,
							V.X, V.Y, V.Z,V.W);
	}
	/************************************************************************/
	/* Matriz de escalacion													*/
	/************************************************************************/
	ceMatrix_4X4 ceMatrix_4X4::Scaling(const ceVector4D & V)
	{
		return ceMatrix_4X4(V.X, 0, 0, 0,
							0, V.Y, 0, 0,
							0, 0, V.Z, 0,
							0, 0, 0, V.W);
	}
	/************************************************************************/
	/* Matriz de rotacion													*/
	/************************************************************************/
	ceMatrix_4X4 ceMatrix_4X4::Rotate(const ceVector4D & V)
	{
		//TODO: Implementar la funcion rotate.
		return ceMatrix_4X4();
	}

	ceMatrix_4X4 ceMatrix_4X4::RotateX(float fvalue)
	{
		return ceMatrix_4X4();
	}

	ceMatrix_4X4 ceMatrix_4X4::RotateY(float fValue)
	{
		return ceMatrix_4X4();
	}

	ceMatrix_4X4 ceMatrix_4X4::RotateZ(float fvalue)
	{
		return ceMatrix_4X4();
	}

}