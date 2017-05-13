#pragma once
#include "cePrerequisitesGraphics.h"

#include "ceDevice.h"
#include "ceDeviceContext.h"
#include "ceSwapChain.h"
#include "ceRenderTargetView.h"
#include "ceDepthStencilView.h"
#include "ceBlob.h"
#include "cePixelShader.h"
#include "ceVertexShader.h"
#include "ceTexture.h"
#include "ceInputLayaout.h"
#include "ceBuffer.h"
#include "ceShaderResourceView.h"
#include "ceSampler.h"
#include "ceVertex.h"

#include <cePlatformMath.h>
#include <ceVector4D.h>
#include <ceVector3D.h>
#include <ceVector2D.h>
#include <ceMatrix_4X4.h>
#include <ceString.h>


/**
 * @ namespace para incluir la clase dentro del espacio de nombre ceEngineSDK. 
 **/
namespace ceEngineSDK
{
	
	class CE_GRAPHICS_EXPORT ceGraphicsAPI
	{

	public:
		/************************************************************************/
		/*               Constructor y Destructor de la Clase					*/
		/************************************************************************/

		//! Constructor Default de la Clase.
		ceGraphicsAPI();
		//! Destructor Default de la Clase.
		~ceGraphicsAPI();

		/************************************************************************/
		/*						Funcion Miembro de la Clase						*/
		/************************************************************************/

		//! Funcion para inicializar el GraphicsAPI.
		void Init(uint32 uiScreenHandle, int32 iWidth, int32 iHeight);
		//! Funcion para renderear.
		void Render();
		//! Funcion para actualizar.
		void Update(float fTime);
		//! Funcion para destruir.
		void Destroy();

		/************************************************************************/
		/*								Funciones de Creacion					*/
		/************************************************************************/

		//! Funcion para crear el dispositivo.
		void CreateDevice();
		//! Funcion para crear el contexto del dispositivo.
		void CreateDeviceContext();
		//! Funcion para crear la cadena de intercambio.
		void CreateSwapChain(uint32 uiScreenHandle, int32 iWidth, int32 iHeight, void** ppDevice, void** ppDeviceContext);
		
		//! Funcion para crear el RenderTargetView.
		void CreateRenderTargetView(void* pSwapChain, void* pDevice, ceTexture* pTexture);
		//! Funcion para crear el DepthStencilView.
		void CreateDepthStencilView(void* pDevice, ceTexture* pTexture);
		
		//! Funcion para crear el Shader de Vertices.
		void CreateVertexShader(void* pDevice);
		//! Funcion para crear el Shader de Pixeles.
		void CreatePixelShader(void* pDevice);
		
		//! Funcion para crear el InputLayout.
		void CreateInputLayout(void* pDevice);

		//! Funcion para crear el Buffer de Vertices.
		void CreateVertexBuffer(void* pDevice, ceVertex* Vertex);
		//! Funcion para crear el Buffer de Indices.
		void CreateIndexBuffer(void* pDevice, uint32* uiIndices);
		//! Funcion para crear los Buffers Constantes.
		void CreateConstantBuffers(void* pDevice, const int32 iNumBuffers);

		//! Funcion para crear el Sampler.
		void CreateSample(void* pDevice);
		//! Funcion para crear la camara, matriz de vista, proyeccion y mundo.
		void CreateCamera();


		/************************************************************************/
		/*							 Funciones de Seteo							*/
		/************************************************************************/

		//! Funcion para setear la topologia.
		void SetPrimitiveTopology();
		
		//! Funcion para setear los Render Targets.
		void SetRenderTargets();
		//! Funcion para setear el ViewPort.
		void SetViewPort(void* pDeviceContext);
		//! Funcion para setear el InputLayout
		void SetInputLayaout();

		//! Funcion para setear el Buffer de Vertices.
		void SetVertexBuffer(void* pDeviceContext, uint32 pStride, uint32 pOffse);
		//! Funcion para setear el Buffer de Indices.
		void SetIndexBuffer(void* pDeviceContext);
		//! Funcion para setear los shaders.
		void SetShaders(void* pDeviceContext, void* pPixelShader, void* pVertexShader);
	

		/************************************************************************/
		/*							 Funciones de Ayuda							*/
		/************************************************************************/

		//! Funcion para cargar un shader desde un archivo.
		void CompileShaderFromFile(const char* szFileName, const String szEntryPoint, const String szShaderModel, ceBlob* ppBlobOut);

		/************************************************************************/
		/*                Variables Miembro de Clase							*/
		/************************************************************************/

		//! Puntero a un Device.
		ceDevice* m_pDevice;
		//! Puntero a un Device Context.
		ceDeviceContext* m_pDeviceContext;
		//! Puntero al SwapChain.
		ceSwapChain* m_pSwapChain;
		//! Puntero a un objeto de RTV.
		ceRenderTargetView* m_pRenderTargetView;
		//! Puntero a un objeto de DSV.
		ceDepthStencilView* m_pDepthStencilView;
		//! Puntero a un PixelShader.
		cePixelShader* m_pPixelShader;
		//! Puntero a un VertexShader.
		ceVertexShader* m_pVertexShader;
		//! Textura para el DepthStencilView.
		ceTexture* m_pTextureDSV;
		//! Textura para el RenderTargetView.
		ceTexture* m_pTextureRTV;

		//! Input Layout.
		ceInputLayaout* m_pInputLayaout;
		//! Shader Resource View.
		ceShaderResourceView* m_pShaderResourceView;

		//! Buffer de Vertices.
		ceBuffer* m_pVertexBuffer;
		//! Buffer de Indices.
		ceBuffer* m_pIndexBuffer;
		//! Lista de constant buffers.
		std::vector<ceBuffer*> m_pConstantBuffers;


		//! Sampler.
		ceSampler* m_pSampler;
		//! Blob.
		ceBlob* m_pBlob;

		//! Variable para almacenar el handle a la ventana.
		uint32 m_uiScreenHandle;

		//! Variable para almacenar el hancho de la ventana.
		int32 m_iWidth;
		//! Variable para almacenar el alto de la ventana.
		int32 m_iHeight;


		//! Matriz de Mundo.
		ceMatrix_4X4 m_World;
		//! Matriz de Vista.
		ceMatrix_4X4 m_View;
		//! Matriz de Proyeccion.
		ceMatrix_4X4 m_Projection;
	};
}