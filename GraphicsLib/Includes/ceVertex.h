#pragma once
#include "cePrerequisitesGraphics.h"
#include <ceVector3D.h>
#include <ceVector2D.h>

namespace ceEngineSDK
{
	class CE_GRAPHICS_EXPORT ceVertex
	{
	public:

		ceVertex(ceVector3D Position, ceVector2D TextCoord);
		~ceVertex();

		ceVector3D m_Position;
		ceVector2D m_TextCoord;
	
	};
}