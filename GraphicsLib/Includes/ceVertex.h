#pragma once
#include "cePrerequisitesGraphics.h"
#include <ceVector3D.h>
#include <ceVector2D.h>

namespace ceEngineSDK
{
	class CE_GRAPHICS_EXPORT ceVertex
	{
	public:

		/************************************************************************/
		/*             Constructor y Destructor de la Clase						*/
		/************************************************************************/

		//! Constructor con parametros.
		ceVertex(ceVector3D Position, ceVector2D TextCoord);
		//! Destructor default.
		~ceVertex();

		/************************************************************************/
		/*           Variables miembro de la Clase								*/
		/************************************************************************/

		//! Vector 3D para la posicion del vertice.
		ceVector3D m_Position;
		//! Vector 2D para la coordenada de textura.
		ceVector2D m_TextCoord;
	
	};
}