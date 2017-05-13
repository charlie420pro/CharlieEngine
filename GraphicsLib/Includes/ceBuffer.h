#pragma once
#include "cePrerequisitesGraphics.h"
#include "ceVertex.h"
#include "ceMatrix_4X4.h"

namespace ceEngineSDK
{
	/************************************************************************/
	/*   Declaracion por delante de las estructuras definidas en el CPP		*/
	/************************************************************************/ 
	struct ceBufferDX;

	/** 
	 * @brief Clase para la utilizacion de buffers.
	 */
	class CE_GRAPHICS_EXPORT ceBuffer
	{
	public:
		//! Constructor default de la clase.
		ceBuffer();
		//! Destructor default de la clase.
		~ceBuffer(); 

		/************************************************************************/
		/*                    Funciones de la clase								*/
		/************************************************************************/

		//! Funcion para inicializar.
		void Init();
		//! Funcion para destruir.
		void Destroy();

		/************************************************************************/
		/*                              Accesores							    */
		/************************************************************************/

		//! Funcion que retorna un VertexBuffer como referencia.
		void** GetBufferData();
		//! Funcion que retorna un Buffer para guardar el mundo.
		void* GetBuffer();


		//! Funcion para setear el buffer.
		void SetBuffer(void* pDeviceContext, uint32 uiStartSlot, uint32 uiNumBuffer, uint32 iBufferType, uint32 Stride, uint32 Offset);
		
		void CreateVertexBuffer(ceVertex* Data, void* pDevice, int32 iUsageFlag, int32 iBindFlag, int32 iAccessFlag);
		void CreateIndexBuffer(uint32* Data, void* pDevice, int32 iUsageFlag, int32 iBindFlag, int32 iAccessFlag);
		void CreateConstantBuffer(void* pDevice);

		void* MapBuffer(void* pDeviceContext);
		void UnMapBuffer(void* pDeviceContext);

		/************************************************************************/
		/*						Variables miembro de la clase					*/
		/************************************************************************/

	private:
		//! Puntero a buffer DX
		ceBufferDX* m_pBuffer;	
		
		//! Enumerador para saber el tipo de buffer
		enum BUFFER_TYPE
		{
			CONSTANT_BUFFER,
			VERTEX_BUFFER,
			INDEX_BUFFER
		};
	};
}
