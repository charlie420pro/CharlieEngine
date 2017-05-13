#include "ceSwapChain.h"
#include <d3d11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	/** 
	 *	@brief Estructura que contiene un SwapChain de DirectX.
	 */
	struct SwapChain
	{
		//! Puntero a un objeto SwapChain de DirectX.
		IDXGISwapChain* m_D3DSwapChain;
		//! Funcion para destruir.
		void Destroy() { m_D3DSwapChain->Release(); }
	};

	/**
	*	@brief Estructura para utilizacion de FeaturesLevels.
	*/
	struct FeatureLevel
	{
		//! Variable FeatureLevel de DirectX.
		D3D_FEATURE_LEVEL m_D3DFeatureLevel;
	};
	
	/**
	 * @brief Constructor default de la clase.
	 */
	ceSwapChain::ceSwapChain()
	{
		m_pSC = nullptr;
	}

	/**
	 * @brief Destructor default de la clase.
	 */
	ceSwapChain::~ceSwapChain()
	{
		m_pSC = nullptr;
	}

	/**
	 * @brief Funcion que retorna el swapchain.
	 * @return Void** para reinterpretarlo como swapchain.
	 */
	void** ceSwapChain::GetSwapChainData()
	{
		//! Regresa el swapchain interpretado como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pSC->m_D3DSwapChain);
	}

	void* ceSwapChain::GetSwapChain()
	{
		return reinterpret_cast<void*>(this->m_pSC->m_D3DSwapChain);
	}

	void ceSwapChain::CreateSwapChainAndDevice(uint32 uiScrenHandle, int32 iWidth, int32 iHeight, void** pDevice, void** pDeviceContext)
	{

		ID3D11Device** tempDevice = (ID3D11Device**)pDevice;
		ID3D11DeviceContext** tempDeviceContext = (ID3D11DeviceContext**)pDeviceContext;

		//! Arreglo de drivertypes.
		D3D_DRIVER_TYPE driverTypes[] =
		{
			D3D_DRIVER_TYPE_HARDWARE,
			D3D_DRIVER_TYPE_WARP,
			D3D_DRIVER_TYPE_REFERENCE,
		};

		//! Arreglo de featurelevels.
		D3D_FEATURE_LEVEL featureLevels = D3D_FEATURE_LEVEL_11_0;

		//! Creamos el hr a modo de bandera.
		HRESULT hr = S_OK;

		//! Variable temporal para el numero de banderas.
		int32 iNumFlag = 0;


		//! Creamos el descriptor del swapchain.
		DXGI_SWAP_CHAIN_DESC sd;
		ZeroMemory(&sd, sizeof(DXGI_SWAP_CHAIN_DESC));
		sd.BufferCount = 1;
		sd.BufferDesc.Width = iWidth;
		sd.BufferDesc.Height = iHeight;
		sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		sd.BufferDesc.RefreshRate.Numerator = 60;
		sd.BufferDesc.RefreshRate.Denominator = 1;
		sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE;
		sd.BufferDesc.Scaling = DXGI_MODE_SCALING_STRETCHED;
		sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT | DXGI_USAGE_UNORDERED_ACCESS;
		sd.OutputWindow = reinterpret_cast<HWND>(uiScrenHandle);
		sd.SampleDesc.Count = 1;
		sd.SampleDesc.Quality = 0;
		sd.Windowed = true;
		sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		sd.Flags = 0;

		uint32 createDeviceFlags = 0;
#ifdef _DEBUG
		createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

		//! Creamos el device y el swapchain.
		hr = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, createDeviceFlags, &featureLevels, 1,
			D3D11_SDK_VERSION, &sd, &m_pSC->m_D3DSwapChain, tempDevice, &m_FeatureLevel->m_D3DFeatureLevel,tempDeviceContext);

		//! Si fallo
		if (FAILED(hr))
			std::cout << "Fallo al crear SwapChain" << std::endl;

		
	}

	/**
	 * @brief Funcion para inicializar 
	 */
	void ceSwapChain::Init()
	{
		if (m_pSC == nullptr)	
			m_pSC = new SwapChain();

		//! Asignamos memoria a los featurelevels.
		m_FeatureLevel = new FeatureLevel();
		m_FeatureLevel->m_D3DFeatureLevel = D3D_FEATURE_LEVEL_11_0;
		
	}

	/**
	 * @brief Funcion para destruir.
	 */
	void ceSwapChain::Destroy()
	{
		if (m_pSC != nullptr)
		{
			m_pSC->Destroy();
			delete m_pSC;
		}
	}
}