#include "ceVertexShader.h"
#include <d3d11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	struct VertexShader
	{
		ID3D11VertexShader* m_D3DVertexShader;
		void Destroy() { m_D3DVertexShader->Release(); }
	};

	ceVertexShader::ceVertexShader()
	{
		m_pVS = nullptr;
	}


	ceVertexShader::~ceVertexShader()
	{
		m_pVS = nullptr;
	}

	void ceVertexShader::Init()
	{
		if (m_pVS == nullptr)
			m_pVS = new VertexShader();
	}

	void ceVertexShader::Destroy()
	{
		if (m_pVS != nullptr)
		{
			m_pVS->Destroy();
			delete m_pVS;
		}
	}
	void ** ceVertexShader::GetVertexShaderData()
	{
		//! Regresa el Buffer que no cambia interpretado como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pVS->m_D3DVertexShader);
	}
	void * ceVertexShader::GetVertexShader()
	{
		//! Regresa el Buffer que no cambia interpretado como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pVS->m_D3DVertexShader);
	}

	void ceVertexShader::CreateVertexShader(void * pDevice, ceBlob * pBlob)
	{
		ID3D11Device* pTempDevice = (ID3D11Device*)pDevice;
		ID3DBlob* pTempBlob = (ID3DBlob*)pBlob->GetBlob();

		HRESULT hr = S_OK;
		// Create the vertex shader
		hr = pTempDevice->CreateVertexShader(pTempBlob->GetBufferPointer(),pTempBlob->GetBufferSize(),
											nullptr, &m_pVS->m_D3DVertexShader);
		if (FAILED(hr))
		{
			pTempBlob->Release();
			std::cout << "Fallo al crear el Vertex Shader" << std::endl;
		}

	}
}