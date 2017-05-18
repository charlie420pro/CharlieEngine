#include "ceVertex.h"

namespace ceEngineSDK
{

	/**
	 *	@brief
	 *	@param ceVector3D Position: Posicion del vertice
	 *	@param ceVector2D TextCoord: Coordenada de textura del vertice.
	 **/
	ceVertex::ceVertex(ceVector3D Position, ceVector2D TextCoord)
	{
		m_Position = Position;
		m_TextCoord = TextCoord;
	}

	/**
	 *	@brief Destructor default de la clase.
	 **/
	ceVertex::~ceVertex()
	{
	}
}