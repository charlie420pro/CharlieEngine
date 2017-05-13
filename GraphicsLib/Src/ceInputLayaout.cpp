#include "ceInputLayaout.h"
#include <d3d11.h>
//#include <d3dx11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	struct InputLayout
	{
		ID3D11InputLayout* m_D3DImputLayout;
		void Destroy() { m_D3DImputLayout->Release(); }
	};

	ceInputLayaout::ceInputLayaout()
	{
		m_pIL = nullptr;
	}


	ceInputLayaout::~ceInputLayaout()
	{
		m_pIL = nullptr;
	}

	void ceEngineSDK::ceInputLayaout::Init()
	{
		if (m_pIL == nullptr)
			m_pIL = new InputLayout();
	}

	void ceEngineSDK::ceInputLayaout::Destroy()
	{
		if (m_pIL != nullptr)
		{
			m_pIL->Destroy();
			delete m_pIL;
		}
	}
	void ** ceInputLayaout::GetInputLayoutData()
	{
		//! Regresa el Buffer que no cambia interpretado como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pIL->m_D3DImputLayout);
	}
	void* ceInputLayaout::GetInputLayout()
	{
		//! Regresa el Buffer que no cambia interpretado como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pIL->m_D3DImputLayout);
	}

	void ceInputLayaout::CreateILO(void * pDevice, ceBlob * pBlob)
	{
		HRESULT hr = S_OK;

		ID3D11Device* pTempDevice = (ID3D11Device*)pDevice;
		
		// Define the input layout
		D3D11_INPUT_ELEMENT_DESC layout[] =
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
		};
		UINT numElements = ARRAYSIZE(layout);

		// Create the input layout
		hr = pTempDevice->CreateInputLayout(layout, numElements, pBlob->GetBufferPointer(),
			pBlob->GetBufferSize(), &m_pIL->m_D3DImputLayout);

		pBlob->Destroy();
		if (FAILED(hr))
			std::cout << "Fallo al Crear ImputLayout" << std::endl;
		
	}
}
