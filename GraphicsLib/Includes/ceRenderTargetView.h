#pragma once
#include "cePrerequisitesGraphics.h"
#include "ceTexture.h"

namespace ceEngineSDK
{
	struct RTV;
	class CE_GRAPHICS_EXPORT ceRenderTargetView
	{
	public:
		ceRenderTargetView();
		~ceRenderTargetView();

		RTV* m_pRTV;

		void Init();
		void Destroy();
		void** GetRenderTargetViewData();
		void* GetRenderTargetView();
		void CreateRTV(void* pSwapChain, void* pDevice, ceTexture* ppTexture);

	};
}
