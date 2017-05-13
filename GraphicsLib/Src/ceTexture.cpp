#include "ceTexture.h"
#include <d3d11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	struct Texture
	{
		ID3D11Texture2D* m_D3DBackBuffer;
		void Destroy() { m_D3DBackBuffer->Release(); }
	};

	ceTexture::ceTexture()
	{ 
		m_pBB = nullptr;
	}


	ceTexture::~ceTexture()
	{
		m_pBB = nullptr;
	}
	void ceTexture::Init()
	{
		if (m_pBB == nullptr)
			m_pBB = new Texture();
	}

	void ceTexture::Destroy()
	{
		if (m_pBB != nullptr)
		{
			m_pBB->Destroy();
			delete m_pBB;
		}
	}
	void ** ceTexture::GetBackBufferData()
	{
		//! Regresa el Buffer que no cambia interpretado como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pBB->m_D3DBackBuffer);
	}

	void * ceTexture::GetBackBuffer()
	{
		//! Regresa el Buffer que no cambia interpretado como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pBB->m_D3DBackBuffer);
	}

	void ceTexture::SetBackBuffer(void* pBackBuffer)
	{
		m_pBB->m_D3DBackBuffer = (ID3D11Texture2D*)pBackBuffer;
	}
}
