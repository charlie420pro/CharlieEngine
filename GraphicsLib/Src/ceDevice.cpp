#include "ceDevice.h"
#include <d3d11.h>
//#include <d3dx11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	struct Device
	{
		ID3D11Device* m_D3DDevice;
		void Destroy() { m_D3DDevice->Release(); }
	};

	ceDevice::ceDevice()
	{
		m_pD = nullptr;
	}


	ceDevice::~ceDevice()
	{
		m_pD = nullptr;
	}

	void ceDevice::Init()
	{
		if (m_pD == nullptr)
			m_pD = new Device();
	}

	void ceDevice::Destroy()
	{
		if (m_pD != nullptr)
		{
			m_pD->Destroy();
			delete m_pD;
		}
	}

	void** ceDevice::GetDeviceData()
	{
		//! Regresa el Buffer que no cambia interpretado como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pD->m_D3DDevice);
	}
	void* ceDevice::GetDevice()
	{
		//! Regresa el Buffer que no cambia interpretado como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pD->m_D3DDevice);
	}
}