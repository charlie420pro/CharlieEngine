#pragma once
#include "cePrerequisitesGraphics.h"
#include "ceVertex.h"
 

namespace ceEngineSDK
{
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	class CE_GRAPHICS_EXPORT ceModel
	{
	public:
		//! Constructor default.
		ceModel();
		//! Destructor default.
		~ceModel();


		//************************************************************************/
		/*                  Variables miembro de la Clase						*/
		/************************************************************************/

		//! Puntero para almacenar el numero de vertices del mesh.
		ceVertex* m_pVertex;
		//! Entero para almacenar el numero de indices del mesh.
		uint32* m_pIndices;

	
	};

}
