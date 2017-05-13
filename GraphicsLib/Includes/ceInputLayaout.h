#pragma once
#include "cePrerequisitesGraphics.h"
#include "ceBlob.h"


namespace ceEngineSDK
{
	struct InputLayout;

	class CE_GRAPHICS_EXPORT ceInputLayaout
	{
	public:
		ceInputLayaout();
		~ceInputLayaout();

		InputLayout* m_pIL;

		void Init();
		void Destroy();
		void** GetInputLayoutData();
		void* GetInputLayout();
		void CreateILO(void* pDevice, ceBlob* pBlob);
	};
}
