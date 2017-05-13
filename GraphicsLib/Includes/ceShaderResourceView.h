#pragma once
#include "cePrerequisitesGraphics.h"

namespace ceEngineSDK
{
	struct ShaderResourceView;

	class CE_GRAPHICS_EXPORT ceShaderResourceView
	{
	public:
		ceShaderResourceView();
		~ceShaderResourceView();

		ShaderResourceView* m_pTRV;

		void Init();
		void Destroy();
		void** GetShaderResourceViewData();
		void* GetShaderResourceView();
	};
}
