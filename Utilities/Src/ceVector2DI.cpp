#include "ceVector2DI.h"

namespace ceEngineSDK
{
	/************************************************************************************************************************/
	/* Implementación de funciones del vector                               												*/
	/************************************************************************************************************************/
	 ceVector2DI::ceVector2DI()
	{

	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector2DI::ceVector2DI(int32 InX, int32 InY) : X(InX), Y(InY)
	{

	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	ceVector2DI::~ceVector2DI()
	{

	}

	/************************************************************************************************************************/
	/* Implementación de operadores aritméticos                             												*/
	/************************************************************************************************************************/

	 ceVector2DI ceVector2DI::operator+(const ceVector2DI& V) const
	{
		return ceVector2DI(X + V.X, Y + V.Y);
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector2DI ceVector2DI::operator-(const ceVector2DI& V) const
	{
		return ceVector2DI(X - V.X, Y - V.Y);
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector2DI ceVector2DI::operator*(float Scale) const
	{
		return ceVector2DI(X * Scale, Y * Scale);
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector2DI ceVector2DI::operator*(const ceVector2DI& V) const
	{
		return ceVector2DI(X * V.X, Y * V.Y);
	}

	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector2DI ceVector2DI::operator/(float Scale) const
	{
		return ceVector2DI(X * Scale, Y * Scale);
	}

	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector2DI ceVector2DI::operator/(const ceVector2DI& V) const
	{
		return ceVector2DI(X / V.X, Y / V.Y);
	}



	/************************************************************************************************************************/
	/* Implementación de operadores lógicos                                 												*/
	/************************************************************************************************************************/
	 bool ceVector2DI::operator==(const ceVector2DI& V) const
	{
		return X == V.X && Y == V.Y;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 bool ceVector2DI::operator!=(const ceVector2DI& V) const
	{
		return X != V.X || Y != V.Y;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 bool ceVector2DI::operator<(const ceVector2DI& Other) const
	{
		return X < Other.X && Y < Other.Y;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 bool ceVector2DI::operator>(const ceVector2DI& Other) const
	{
		return X > Other.X && Y > Other.Y;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 bool ceVector2DI::operator<=(const ceVector2DI& Other) const
	{
		return X <= Other.X && Y <= Other.Y;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 bool ceVector2DI::operator>=(const ceVector2DI& Other) const
	{
		return X >= Other.X && Y >= Other.Y;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 bool ceVector2DI::Equals(const ceVector2DI& V, int32 Tolerance) const
	{
		return ceMath::Abs(X - V.X) < Tolerance && ceMath::Abs(Y - V.Y) < Tolerance;
	}

	/************************************************************************************************************************/
	/* Implementación de operadores de asignación compuesta                 												*/
	/************************************************************************************************************************/
	 ceVector2DI ceVector2DI::operator+=(const ceVector2DI& V)
	{
		X += V.X; Y += V.Y;
		return *this;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector2DI ceVector2DI::operator-=(const ceVector2DI& V)
	{
		X -= V.X; Y -= V.Y;
		return *this;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector2DI ceVector2DI::operator*=(int32 Scale)
	{
		X *= Scale; Y *= Scale;
		return *this;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector2DI ceVector2DI::operator/=(int32 V)
	{
		X *= V; Y *= V;
		return *this;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector2DI ceVector2DI::operator*=(const ceVector2DI& V)
	{
		X *= V.X; Y *= V.Y;
		return *this;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector2DI ceVector2DI::operator/=(const ceVector2DI& V)
	{
		X /= V.X; Y /= V.Y;
		return *this;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 float ceVector2DI::Magnitud(const ceVector2DI& V)
	{
		return (float)ceMath::Sqrt((float)ceMath::Pow((float)V.X, 2) + ceMath::Pow((float)V.Y, 2));
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 ceVector2DI ceVector2DI::Normalize(const ceVector2DI& V)
	{
		return V / Magnitud(V);
	}

	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 int32 ceVector2DI::operator|(const ceVector2DI& V) const
	{
		return X*V.X + Y*V.Y;
	}

	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 int32 ceVector2DI::operator^(const ceVector2DI& V) const
	{
		return X*V.Y - Y*V.X;
	}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	 int32 ceVector2DI::DotProduct(const ceVector2DI& A, const ceVector2DI& B)
	{
		return A | B;
	}

}
