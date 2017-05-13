#include "ceShaderResourceView.h"
#include <d3d11.h>
//#include <d3dx11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	struct ShaderResourceView
	{
		ID3D11ShaderResourceView* m_D3DTextureSRV;
		void Destroy() { m_D3DTextureSRV->Release(); }
	};
	ceShaderResourceView::ceShaderResourceView()
	{
		m_pTRV = nullptr;
	}


	ceShaderResourceView::~ceShaderResourceView()
	{
		m_pTRV = nullptr;
	}

	void ceEngineSDK::ceShaderResourceView::Init()
	{
		if (m_pTRV == nullptr)
			m_pTRV = new ShaderResourceView();
	}

	void ceEngineSDK::ceShaderResourceView::Destroy()
	{
		if (m_pTRV != nullptr)
		{
			m_pTRV->Destroy();
			delete m_pTRV;
		}
	}

	void ** ceShaderResourceView::GetShaderResourceViewData()
	{
		//! Regresa el Buffer que no cambia interpretado como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pTRV->m_D3DTextureSRV);
	}
	void * ceShaderResourceView::GetShaderResourceView()
	{
		//! Regresa el Buffer que no cambia interpretado como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pTRV->m_D3DTextureSRV);
	}
}