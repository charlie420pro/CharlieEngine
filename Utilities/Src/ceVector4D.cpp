#include "ceVector4D.h"


namespace ceEngineSDK
{
	/************************************************************************************************************************/
	/* Implementación de funciones del vector                               												*/
	/************************************************************************************************************************/
	 ceVector4D::ceVector4D()
	{

	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector4D::ceVector4D(float InX, float InY, float InZ,float InW) : X(InX), Y(InY), Z(InZ), W(InW)
	{

	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	ceVector4D::~ceVector4D()
	{

	}

	/************************************************************************************************************************/
	/* Implementación de operadores aritméticos                             												*/
	/************************************************************************************************************************/

	 ceVector4D ceVector4D::operator+(const ceVector4D& V) const
	{
		return ceVector4D(X + V.X, Y + V.Y, Z + V.Z, W + V.W);
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector4D ceVector4D::operator-(const ceVector4D& V) const
	{
		return ceVector4D(X - V.X, Y - V.Y, Z - V.Z, W - V.W);
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector4D ceVector4D::operator*(float Scale) const
	{
		return ceVector4D(X * Scale, Y * Scale, Z * Scale, W * Scale);
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector4D ceVector4D::operator*(const ceVector4D& V) const
	{
		return ceVector4D(X * V.X, Y * V.Y, Z * V.Z, W *V.W);
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector4D ceVector4D::operator/(float Scale) const
	{
		const float RScale = 1.f / Scale;
		return ceVector4D(X * RScale, Y * RScale, Z * RScale, W * RScale);
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector4D ceVector4D::operator/(const ceVector4D& V) const
	{
		return ceVector4D(X / V.X, Y / V.Y, Z / V.Z, W/V.W);
	}



	/************************************************************************************************************************/
	/* Implementación de operadores lógicos                                 												*/
	/************************************************************************************************************************/
	 bool ceVector4D::operator==(const ceVector4D& V) const
	{
		return X == V.X && Y == V.Y && Z == V.Z && W == V.W;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 bool ceVector4D::operator!=(const ceVector4D& V) const
	{
		return X != V.X || Y != V.Y || Z != V.Z || W != V.W;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 bool ceVector4D::operator<(const ceVector4D& Other) const
	{
		return X < Other.X && Y < Other.Y && Z < Other.Z && W < Other.W;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 bool ceVector4D::operator>(const ceVector4D& Other) const
	{
		return X > Other.X && Y > Other.Y && Z > Other.Z && W > Other.W;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 bool ceVector4D::operator<=(const ceVector4D& Other) const
	{
		return X <= Other.X && Y <= Other.Y && Z <= Other.Z && W <= Other.W;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 bool ceVector4D::operator>=(const ceVector4D& Other) const
	{
		return X >= Other.X && Y >= Other.Y && Z >= Other.Z&& W >= Other.W;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 bool ceVector4D::Equals(const ceVector4D& V, float Tolerance) const
	{
		return ceMath::Abs(X - V.X) < Tolerance && ceMath::Abs(Y - V.Y) < Tolerance && ceMath::Abs(Z - V.Z) < Tolerance && ceMath::Abs(W-V.W) < Tolerance;
	}

	/************************************************************************************************************************/
	/* Implementación de operadores de asignación compuesta                 												*/
	/************************************************************************************************************************/
	 ceVector4D ceVector4D::operator+=(const ceVector4D& V)
	{
		X += V.X; Y += V.Y; Z += V.Z; W += V.W;
		return *this;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector4D ceVector4D::operator-=(const ceVector4D& V)
	{
		X -= V.X; Y -= V.Y; Z -= V.Z; W -= V.W;
		return *this;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector4D ceVector4D::operator*=(float Scale)
	{
		X *= Scale; Y *= Scale; Z *= Scale; W *= Scale;
		return *this;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector4D ceVector4D::operator/=(float V)
	{
		const float RV = 1.f / V;
		X *= RV; Y *= RV; Z *= RV; W *= RV;
		return *this;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector4D ceVector4D::operator*=(const ceVector4D& V)
	{
		X *= V.X; Y *= V.Y; Z *= V.Z; W *= V.W;
		return *this;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector4D ceVector4D::operator/=(const ceVector4D& V)
	{
		X /= V.X; Y /= V.Y; Z /= V.Z; W /= V.W;
		return *this;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 float ceVector4D::Magnitud(const ceVector4D & V)
	{
		return ceMath::Sqrt(ceMath::Pow(V.X, 2) + ceMath::Pow(V.Y, 2) + ceMath::Pow(V.Z, 2) + ceMath::Pow(V.W,2));
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector4D ceVector4D::Normalize(const ceVector4D & V)
	{
		return V / Magnitud(V);
	}

	/************************************************************************/
	/* Producto Punto                                                       */
	/************************************************************************/
	 float ceVector4D::operator|(const ceVector4D& V) const
	{
		return X*V.X + Y*V.Y + Z*V.Z + W*V.W;
	}

	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 float ceVector4D::operator^(const ceVector4D& V) const
	{
		 //TODO: Implementar el operador.
		return 0.0f;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 float ceVector4D::Dot(const ceVector4D& B)
	 {
		 float escalar = this->X * B.X + this->Y * B.Y + this->Z * B.Z + this->W * B.W;
		 if (escalar <= cePlatformMath::DELTA && escalar >= 0 - cePlatformMath::DELTA)
		 {
			 escalar = 0;
		 }
		 return escalar;
	 }

	 ceVector4D ceVector4D::Cross(const ceVector4D & V, const ceVector4D & B)
	{
		return ceVector4D((V.Y*B.Z - V.Z * B.Y), (V.Z * B.X - V.X * B.Z), (V.X * B.Y - V.Y * B.X),0);
	}

}