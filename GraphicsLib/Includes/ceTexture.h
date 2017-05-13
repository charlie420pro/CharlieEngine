#pragma once
#include "cePrerequisitesGraphics.h"

namespace ceEngineSDK
{
	struct Texture;

	class CE_GRAPHICS_EXPORT ceTexture
	{
	public:
		ceTexture();
		~ceTexture();
		
		Texture* m_pBB;

		void Init();
		void Destroy();
		void** GetBackBufferData();
		void* GetBackBuffer();
		void SetBackBuffer(void* pBackBuffer);
	};
}

