#pragma once
#include "cePrerequisitesGraphics.h"

namespace ceEngineSDK
{
	struct BlobDX;

	class CE_GRAPHICS_EXPORT ceBlob
	{
	public:

		ceBlob();
		~ceBlob();

		void Init();
		void Destroy();
		void* GetBlob();
		void** GetBlobData();
		const void* GetBufferPointer();

		SIZE_T GetBufferSize();

		BlobDX* m_pBlob;
	};
}