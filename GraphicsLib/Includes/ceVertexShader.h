#pragma once
#include "cePrerequisitesGraphics.h"
#include "ceBlob.h"

namespace ceEngineSDK
{
	struct VertexShader;

	class CE_GRAPHICS_EXPORT ceVertexShader
	{
	public:
		ceVertexShader();
		~ceVertexShader();

		VertexShader* m_pVS;

		void Init();
		void Destroy();
		void** GetVertexShaderData();
		void* GetVertexShader();
		void CreateVertexShader(void* pDevice, ceBlob* pBlob);

	};
}
