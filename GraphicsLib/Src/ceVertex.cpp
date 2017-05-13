#include "ceVertex.h"

namespace ceEngineSDK
{
	

	ceVertex::ceVertex(ceVector3D Position, ceVector2D TextCoord)
	{
		m_Position = Position;
		m_TextCoord = TextCoord;
	}

	ceVertex::~ceVertex()
	{
	}
}