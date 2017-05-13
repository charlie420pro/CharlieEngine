#pragma once
#include "cePrerequisitesGraphics.h"
#include "ceBlob.h"


namespace ceEngineSDK
{
	struct PixelShader;

	class CE_GRAPHICS_EXPORT cePixelShader 
	{
	public:
		cePixelShader();
		~cePixelShader();

		PixelShader* m_pPS;

		void Init();
		void Destroy();
		void** GetPixelShaderData();
		void* GetPixelShader();
		void CreatePixelShader(void* pDevice, ceBlob* pBlob);
	};
}
