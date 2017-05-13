#pragma once
#include "cePrerequisitesGraphics.h"


namespace ceEngineSDK
{
	//! Llamada por delante de la estructura swapchain.
	struct SwapChain;
	struct FeatureLevel;

	/**
	 *	@brief Clase de objeto SwapChain.
	 */
	class CE_GRAPHICS_EXPORT ceSwapChain
	{

	public:
		//! Constructor default de la clase.
		ceSwapChain();
		//! Destructor default de la clase.
		~ceSwapChain();

		//! Puntero a un objeto swapchain.
		SwapChain* m_pSC;
		//! Feature level
		FeatureLevel* m_FeatureLevel;

		//! Funcion para inicializar 
		void Init();
		//! Funcion para destruir.
		void Destroy();
		//! Funcion para obtener el SwapChain como referencia.
		void** GetSwapChainData();
		//! Funcion para obtener el SwapChain.
		void* GetSwapChain();
		//! Funcion para crear el SwapChain.
		void CreateSwapChainAndDevice(uint32 uiScrenHandle, int32 iWidth, int32 iHeight, void** pDevice, void** pDeviceContext);
	};
}
