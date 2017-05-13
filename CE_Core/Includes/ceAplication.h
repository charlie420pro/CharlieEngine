#pragma once
#include "cePrerequisitesCore.h"
#include <cePrerequisitesUtil.h>
#include <ceGraphicsAPI.h>
#include <string>

//! Inclusion dentro del espacio de nombre.
namespace ceEngineSDK
{
	//! Declaracion por delante de graphicsAPI.
	//class ceGraphicsAPI;

	//! Clase de aplicacion base de esta pueden heredar distintas clases.
	class CE_CORE_EXPORT ceAplication
	{

	public:

		//! Constructor default de la clase.
		ceAplication();
		//! Destructor default de la clase virtual para que puedan heredar de esta clase.
		virtual~ceAplication();
		
	protected:
		/************************************************************************/
		/*						Funciones Virtuales								*/
		/************************************************************************/

		//! Funcion para pre inicializar.
		virtual void OnPreInitialize();
		//! Funcion para el momento de inicializar.
		virtual void OnInitialize();
		//! Funcion para utilizar despues de la inicializacion.
		virtual void OnPosInitialize();
		//! Funcion para pre destruir.
		virtual void OnPreDestroy();
		//! Funcion para utiliar antes de destruir.
		virtual void OnDestroy();
		//! Funcion para actualizar.
		virtual void UpDate(float fDelta);
		//! Funcion para renderear.
		virtual void Render();
		//! Funcion para cambiar el tama�o.
		virtual void OnSize();

	public:
		/************************************************************************/
		/*                        Funciones de Clase		                    */
		/************************************************************************/

		//! Funcion para correr la aplicacion.
		int32 Run();
		//! Puntero a un objeto de graphics.
		ceGraphicsAPI m_Graphics;

	private:

		//! Funcion para inicializar.
		virtual void Init();
		//! Funcion para destruir.
		virtual void Destroy();

		/**
		 *	@brief Funcion para retornar el ancho.
		 *	@return Ancho de la ventana.
		 */
		int32 GetWidth() { return m_iWidth; }

		/**
		 *	@brief Funcion para retornar el alto.
		 *	@return Alto de la ventana.
		 */
		int32 GetHeight() { return m_iHeight; }

	protected:
		/************************************************************************/
		/*                 Variables miembro de la clase						*/
		/************************************************************************/

		//! Variable para el titulo de la ventana.
		std::string m_szTitle; 
		//! Handle al objeto de pantalla.
		int32 m_iScreenHandle; 
		//! Variable para el ancho de pantalla.
		int32 m_iWidth;
		//! Variable para el alto de pantalla.
		int32 m_iHeight;
		

	};

}