#pragma once
#include "cePrerequisitesGraphics.h"
#include "ceTexture.h"

namespace ceEngineSDK
{
	/************************************************************************/
	/*                    Declaracion por delante de la estructura			*/
	/************************************************************************/
	struct ceDSV;

	//! Clase para la utilizacion de depthstencilview.
	class CE_GRAPHICS_EXPORT ceDepthStencilView
	{
	public:
		//! Constructor default de la clase.
		ceDepthStencilView();
		//! Destructor default de la clase.
		~ceDepthStencilView();

		/************************************************************************/
		/*							Funciones de la clase						*/
		/************************************************************************/

		//! Funcion para inicializar.
		void Init();
		//! Funcion para destruir.
		void Destroy();

		//! Funcionpara crear el Depth Stencil View.
		void CreateDSV(void* pDevice, ceTexture* pTexture, int32 iWidth, int32 iHeight);

		/************************************************************************/
		/*								Accesores								*/
		/************************************************************************/

		//! Funcion para obtener Depthstencilview por referencia.
		void** GetDepthStencilViewData();
		//! Funcion para obtener el Depthstencilview como puntero.
		void* GetDepthStencilView();
		

		/************************************************************************/
		/*                      Variables miembro de la clase					*/
		/************************************************************************/

		//! Puntero a un DepthStencilView.
		ceDSV* m_pDSV;
	};
}

