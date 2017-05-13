#include "ceRenderTargetView.h"
#include <d3d11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	struct RTV
	{
		ID3D11RenderTargetView* m_D3DRenderTargetView;
		void Destroy() { m_D3DRenderTargetView->Release(); }
	};

	ceRenderTargetView::ceRenderTargetView()
	{
		m_pRTV = nullptr;
	}


	ceRenderTargetView::~ceRenderTargetView()
	{
		m_pRTV = nullptr;
	}


	void ceRenderTargetView::Init()
	{
		if (m_pRTV == nullptr)
			m_pRTV = new RTV();

	}

	void ceRenderTargetView::Destroy()
	{
		if (m_pRTV != nullptr)
		{
			m_pRTV->Destroy();
			delete m_pRTV;
		}
	}
	void ** ceRenderTargetView::GetRenderTargetViewData()
	{
		//! Regresa el Buffer que no cambia interpretado como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pRTV->m_D3DRenderTargetView);
	}
	void * ceRenderTargetView::GetRenderTargetView()
	{
		//! Regresa el Buffer que no cambia interpretado como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pRTV->m_D3DRenderTargetView);
	}

	void ceRenderTargetView::CreateRTV(void * pSwapChain, void * pDevice, ceTexture* pTexture)
	{
		//! Creamos un HRESULT a manera de bandera.
		HRESULT hr = S_OK;

		pTexture = new ceTexture();
		pTexture->Init();
		IDXGISwapChain* pTempSwapChain = (IDXGISwapChain*)pSwapChain;
		ID3D11Device* pTempDevice = (ID3D11Device*)pDevice;

		hr = pTempSwapChain->GetBuffer(0, IID_ID3D11Texture2D, pTexture->GetBackBufferData());
		//! Si fallo 
		if (FAILED(hr))
			std::cout << "Fallo al Crear la Textura" << std::endl;

		//! //! Creamos el render target view.
		hr = pTempDevice->CreateRenderTargetView((ID3D11Texture2D*)pTexture->GetBackBuffer(), nullptr, &m_pRTV->m_D3DRenderTargetView);
		//! Si fallo
		if (FAILED(hr))
			std::cout << "Fallo al Crear RTV" << std::endl;

		
	}
}