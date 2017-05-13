#include "ceSampler.h"
#include <d3d11.h>
//#include <d3dx11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	struct Sampler
	{
		ID3D11SamplerState* m_D3DSamplerLinear;
		void Destroy() { m_D3DSamplerLinear->Release(); }
	};

	ceSampler::ceSampler()
	{
		m_pS = nullptr;
	}


	ceSampler::~ceSampler()
	{
		m_pS = nullptr;
	}

	void ceEngineSDK::ceSampler::Init()
	{
		if (m_pS == nullptr)
			m_pS = new Sampler();
	}

	void ceEngineSDK::ceSampler::Destroy()
	{
		if (m_pS != nullptr)
		{
			m_pS->Destroy();
			delete m_pS;
		}
	}
	void ** ceSampler::GetSamplerData()
	{
		//! Regresa el Buffer que no cambia interpretado como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pS->m_D3DSamplerLinear);
	}
	void* ceSampler::GetSampler()
	{
		//! Regresa el Buffer que no cambia interpretado como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pS->m_D3DSamplerLinear);
	}

	void ceSampler::CreateSampler(void * pDevice)
	{
		HRESULT hr = S_OK;
		ID3D11Device* pTempDevice = (ID3D11Device*)pDevice;
		// Create the sample state
		D3D11_SAMPLER_DESC sampDesc;
		ZeroMemory(&sampDesc, sizeof(sampDesc));
		sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
		sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
		sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
		sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
		sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
		sampDesc.MinLOD = 0;
		sampDesc.MaxLOD = D3D11_FLOAT32_MAX;

		hr = pTempDevice->CreateSamplerState(&sampDesc, &m_pS->m_D3DSamplerLinear);

		if (FAILED(hr))
			std::cout << "Fallo al CrearSampler" << std::endl;
	}
}