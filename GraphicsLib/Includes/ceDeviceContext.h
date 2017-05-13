#pragma once
#include "cePrerequisitesGraphics.h"

namespace ceEngineSDK
{
	/************************************************************************/
	/*          Llamada por delante de la estructura devicecontext			*/
	/************************************************************************/
	struct DeviceContext;

	//! Clase para la utilizacion de objetos ceDeviceContext.
	class CE_GRAPHICS_EXPORT ceDeviceContext
	{
	public:
		//! Constructor default.
		ceDeviceContext();
		//! Destructor default.
		~ceDeviceContext();

		/************************************************************************/
		/*						Variables miembro de la clase					*/
		/************************************************************************/

		//! Puntero a un objeto DeviceContext.
		DeviceContext* m_pDC;

		/************************************************************************/
		/*						 Funciones de la clase.							*/
		/************************************************************************/

		//! Funcion para inicializar.
		void Init();
		//! Funcion para destruir.
		void Destroy();

		/************************************************************************/
		/*								Accesores								*/	
		/************************************************************************/

		//! Funcion para obtener el DeviceContext por parametro.
		void** GetDeviceContextData();
		//! Funcion para obtener el deviceContext como puntero.
		void* GetDeviceContext();
	};
}
