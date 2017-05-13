#pragma once
#include "cePrerequisitesGraphics.h"

namespace ceEngineSDK
{
	/************************************************************************/
	/*             Llamada por delante de la estructura Device				*/
	/************************************************************************/
	struct Device;

	//! Clase para utilizar objeto ceDevice.
	class CE_GRAPHICS_EXPORT ceDevice
	{
	public:
		//! Constructor default de la clase.
		ceDevice();
		//! Destructor default de la clase.
		~ceDevice();

		/************************************************************************/
		/*                     Variables miembro de la clase					*/
		/************************************************************************/

		//! Puntero a un device.
		Device* m_pD;

		/************************************************************************/
		/*                    Funciones miembro de la clase						*/
		/************************************************************************/

		//! Funcion para inicializar.
		void Init();
		//! Funcion para destruir.
		void Destroy();

		/************************************************************************/
		/*								Accesores								*/
		/************************************************************************/

		//! Funcion para obtener el device por referencia.
		void** GetDeviceData();
		//! Funcion para obtener el device como puntero.
		void* GetDevice();
	};
}