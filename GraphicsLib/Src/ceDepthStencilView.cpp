#include "ceDepthStencilView.h"
#include <d3d11.h>
//#include <d3dx11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	struct ceDSV
	{
		ID3D11DepthStencilView* m_D3DDepthStencilView;
		void Destroy() { m_D3DDepthStencilView->Release(); }
	};

	ceDepthStencilView::ceDepthStencilView()
	{
		m_pDSV = nullptr;
	}


	ceDepthStencilView::~ceDepthStencilView()
	{
		m_pDSV = nullptr;
	}
	void ceDepthStencilView::Init()
	{
		if (m_pDSV == nullptr)
			m_pDSV = new ceDSV();
	}

	void ceDepthStencilView::Destroy()
	{
		if (m_pDSV != nullptr) 
		{
			m_pDSV->Destroy();
			delete m_pDSV;
		}
	}

	void** ceDepthStencilView::GetDepthStencilViewData()
	{
		//! Regresa el Buffer que no cambia interpretado como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pDSV->m_D3DDepthStencilView);
	}

	void* ceDepthStencilView::GetDepthStencilView()
	{
		//! Regresa el Buffer que no cambia interpretado como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pDSV->m_D3DDepthStencilView);
	}

	void ceDepthStencilView::CreateDSV(void * pDevice, ceTexture* pTexture, int32 iWidth, int32 iHeight)
	{
		pTexture = new ceTexture();
		pTexture->Init();

		ID3D11Device* pTempDevice = (ID3D11Device*)pDevice;

		HRESULT hr = S_OK;
		// Create depth stencil texture
		D3D11_TEXTURE2D_DESC descDepth;
		ZeroMemory(&descDepth, sizeof(descDepth));
		descDepth.Width = iWidth;
		descDepth.Height = iHeight;
		descDepth.MipLevels = 1;
		descDepth.ArraySize = 1;
		descDepth.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		descDepth.SampleDesc.Count = 1;
		descDepth.SampleDesc.Quality = 0;
		descDepth.Usage = D3D11_USAGE_DEFAULT;
		descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
		descDepth.CPUAccessFlags = 0;
		descDepth.MiscFlags = 0;

		hr = pTempDevice->CreateTexture2D(&descDepth, nullptr, (ID3D11Texture2D**)pTexture->GetBackBufferData());
		if (FAILED(hr))
			std::cout << "Fallo al Crear la Textura" << std::endl;

		hr = pTempDevice->CreateDepthStencilView((ID3D11Texture2D*)pTexture->GetBackBuffer(), nullptr, &m_pDSV->m_D3DDepthStencilView);
		if (FAILED(hr))
			std::cout << "Fallo al Crear DSV" << std::endl;

	}
}