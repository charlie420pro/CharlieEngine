#pragma once
#include "cePrerequisitesGraphics.h"

namespace ceEngineSDK
{
	struct Sampler;

	class CE_GRAPHICS_EXPORT ceSampler
	{
	public:
		ceSampler();
		~ceSampler();

		Sampler* m_pS;

		void Init();
		void Destroy();
		void** GetSamplerData();
		void* GetSampler();
		void CreateSampler(void* pDevice);
	};

}