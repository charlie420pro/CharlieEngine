#include "cePixelShader.h"
#include <d3d11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	struct PixelShader
	{
		ID3D11PixelShader* m_D3DPixelShader;
		void Destroy() { m_D3DPixelShader->Release(); }
	};

	cePixelShader::cePixelShader()
	{
		m_pPS = nullptr;
	}


	cePixelShader::~cePixelShader()
	{
		m_pPS = nullptr;
	}

	void cePixelShader::Init()
	{
		if (m_pPS == nullptr)
			m_pPS = new PixelShader();
	}

	void cePixelShader::Destroy()
	{
		if (m_pPS != nullptr)
		{
			m_pPS->Destroy();
			delete m_pPS;
		}
	}

	void ** cePixelShader::GetPixelShaderData()
	{
		//! Regresa el Buffer que no cambia interpretado como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pPS->m_D3DPixelShader);
	}
	void* cePixelShader::GetPixelShader()
	{
		//! Regresa el Buffer que no cambia interpretado como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pPS->m_D3DPixelShader);
	}

	void cePixelShader::CreatePixelShader(void * pDevice, ceBlob * pBlob)
	{
		HRESULT hr = S_OK;
		ID3D11Device* pTempDevice = (ID3D11Device*)pDevice;
		ID3DBlob* pTempBlob = (ID3DBlob*)pBlob->GetBlob();

		// Create the pixel shader
		hr = pTempDevice->CreatePixelShader(pTempBlob->GetBufferPointer(),
			pTempBlob->GetBufferSize(), nullptr, &m_pPS->m_D3DPixelShader);


		pTempBlob->Release();
		if (FAILED(hr))
			std::cout << "Fallo al crear el PixelShader" << std::endl;
		
	}
}