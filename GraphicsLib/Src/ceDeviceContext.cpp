#include "ceDeviceContext.h"
#include <d3d11.h>
//#include <d3dx11.h>
#include <d3dcompiler.h>


namespace ceEngineSDK
{
	struct DeviceContext
	{
		ID3D11DeviceContext* m_pD3DDeviceContext;
		void Destroy() { m_pD3DDeviceContext->Release(); }
	};

	ceDeviceContext::ceDeviceContext()
	{
		m_pDC = nullptr;
	}


	ceDeviceContext::~ceDeviceContext()
	{
		m_pDC = nullptr;
	}
	void ceDeviceContext::Init()
	{
		if (m_pDC == nullptr)
			m_pDC = new DeviceContext();

	}

	void ceDeviceContext::Destroy()
	{
		if (m_pDC != nullptr)
		{
			m_pDC->Destroy();
			delete m_pDC;
		}
	}
	void ** ceDeviceContext::GetDeviceContextData()
	{
		//! Regresa el Buffer que no cambia interpretado como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pDC->m_pD3DDeviceContext);
	}
	void * ceDeviceContext::GetDeviceContext()
	{
		//! Regresa el Buffer que no cambia interpretado como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pDC->m_pD3DDeviceContext);
	}
}