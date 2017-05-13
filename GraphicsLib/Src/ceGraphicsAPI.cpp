#include "ceGraphicsAPI.h"
#include <windows.h>
#include <dxgi.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <fstream>

namespace ceEngineSDK
{
	const int32 g_iNumBuffer = 3;
	// Create vertex buffer
	ceVertex Vertex[] =
	{
		{ ceVector3D(-1.0f, 1.0f, -1.0f), ceVector2D(0.0f, 0.0f) },
		{ ceVector3D(1.0f, 1.0f, -1.0f), ceVector2D(1.0f, 0.0f) },
		{ ceVector3D(1.0f, 1.0f, 1.0f), ceVector2D(1.0f, 1.0f) },
		{ ceVector3D(-1.0f, 1.0f, 1.0f), ceVector2D(0.0f, 1.0f) },

		{ ceVector3D(-1.0f, -1.0f, -1.0f), ceVector2D(0.0f, 0.0f) },
		{ ceVector3D(1.0f, -1.0f, -1.0f), ceVector2D(1.0f, 0.0f) },
		{ ceVector3D(1.0f, -1.0f, 1.0f), ceVector2D(1.0f, 1.0f) },
		{ ceVector3D(-1.0f, -1.0f, 1.0f), ceVector2D(0.0f, 1.0f) },

		{ ceVector3D(-1.0f, -1.0f, 1.0f), ceVector2D(0.0f, 0.0f) },
		{ ceVector3D(-1.0f, -1.0f, -1.0f), ceVector2D(1.0f, 0.0f) },
		{ ceVector3D(-1.0f, 1.0f, -1.0f), ceVector2D(1.0f, 1.0f) },
		{ ceVector3D(-1.0f, 1.0f, 1.0f), ceVector2D(0.0f, 1.0f) },

		{ ceVector3D(1.0f, -1.0f, 1.0f), ceVector2D(0.0f, 0.0f) },
		{ ceVector3D(1.0f, -1.0f, -1.0f), ceVector2D(1.0f, 0.0f) },
		{ ceVector3D(1.0f, 1.0f, -1.0f), ceVector2D(1.0f, 1.0f) },
		{ ceVector3D(1.0f, 1.0f, 1.0f), ceVector2D(0.0f, 1.0f) },

		{ ceVector3D(-1.0f, -1.0f, -1.0f), ceVector2D(0.0f, 0.0f) },
		{ ceVector3D(1.0f, -1.0f, -1.0f), ceVector2D(1.0f, 0.0f) },
		{ ceVector3D(1.0f, 1.0f, -1.0f), ceVector2D(1.0f, 1.0f) },
		{ ceVector3D(-1.0f, 1.0f, -1.0f), ceVector2D(0.0f, 1.0f) },

		{ ceVector3D(-1.0f, -1.0f, 1.0f), ceVector2D(0.0f, 0.0f) },
		{ ceVector3D(1.0f, -1.0f, 1.0f), ceVector2D(1.0f, 0.0f) },
		{ ceVector3D(1.0f, 1.0f, 1.0f), ceVector2D(1.0f, 1.0f) },
		{ ceVector3D(-1.0f, 1.0f, 1.0f), ceVector2D(0.0f, 1.0f) },
	};

	uint32 Indices[] =
	{
		3,1,0,
		2,1,3,

		6,4,5,
		7,4,6,

		11,9,8,
		10,9,11,

		14,12,13,
		15,12,14,

		19,17,16,
		18,17,19,

		22,20,21,
		23,20,22
	};


	/**
	 *	@brief Constructor default de la clase.
	 **/
	ceGraphicsAPI::ceGraphicsAPI()
	{
		//! Asignamos por default en el constructor los punteros como nulos.
		m_pDevice = nullptr;
		m_pDeviceContext = nullptr;
		m_pSwapChain = nullptr;
		m_pRenderTargetView = nullptr;
		m_pDepthStencilView = nullptr;
		m_pPixelShader = nullptr;
		m_pVertexShader = nullptr;
		m_pTextureRTV = nullptr;
		m_pTextureDSV = nullptr;
		m_pInputLayaout = nullptr;
		m_pShaderResourceView = nullptr;
		m_pSampler = nullptr;
		m_pBlob = nullptr;
		m_uiScreenHandle = m_iHeight = m_iWidth = 0;
	}

	/**
	 *	@brief Destructor default de la clase.
	 **/
	ceGraphicsAPI::~ceGraphicsAPI()
	{
		//! Asignamos por default en el destructor todos los punteros como nulos.
		m_pDevice = nullptr;
		m_pDeviceContext = nullptr;
		m_pSwapChain = nullptr;
		m_pRenderTargetView = nullptr;
		m_pDepthStencilView = nullptr;
		m_pPixelShader = nullptr;
		m_pVertexShader = nullptr;
		m_pTextureRTV = nullptr;
		m_pTextureDSV = nullptr;
		m_pInputLayaout = nullptr;
		m_pShaderResourceView = nullptr;
		m_pSampler = nullptr;
		m_pBlob = nullptr;
		m_uiScreenHandle = m_iHeight = m_iWidth = 0;
	}

	/**
	 *	@brief Funcion para inicializar graphics.
	 *	@param iScreenHanlde: Identificador de la ventana.
	 *	@param iWidth: Ancho de la ventana.
	 *	@param iHeight: Alto de la ventana.
	 **/
	void ceGraphicsAPI::Init(uint32 uiScreenHandle, int32 iWidth, int32 iHeight)
	{
		//! Guardamos las variables de parametro en las variables miembro para futuras referencias.
		m_uiScreenHandle = uiScreenHandle;
		m_iWidth = iWidth;
		m_iHeight = iHeight;

		//! Limpiamos en caso de que ya se hayan inicializado variables.
		Destroy();


		//! Creamos el device.
		CreateDevice();
		//! Creamos el device context.
		CreateDeviceContext();
		//! Creamos el swap chain.
		CreateSwapChain(m_uiScreenHandle, m_iWidth, m_iHeight,
		m_pDevice->GetDeviceData(), m_pDeviceContext->GetDeviceContextData());
		

		//! Creamos el render target view.
		CreateRenderTargetView(m_pSwapChain->GetSwapChain(), m_pDevice->GetDevice(), m_pTextureRTV);
		//! Creamos el depth stencil view.
		CreateDepthStencilView(m_pDevice->GetDevice(), m_pTextureDSV);

		//! Creamos el Vertex Shader.
		CreateVertexShader(m_pDevice->GetDevice());
		//! Creamos el pixel shader.
		CreatePixelShader(m_pDevice->GetDevice());
		//! Creamos el InputLayout.
		CreateInputLayout(m_pDevice->GetDevice());

	
		//! Creamos el VertexBuffer.
		CreateVertexBuffer(m_pDevice->GetDevice(), Vertex);
		//! Creamos el IndexBuffer.
		CreateIndexBuffer(m_pDevice->GetDevice(), Indices);
		//! Creamos los constantbuffer.
		CreateConstantBuffers(m_pDevice->GetDevice(),g_iNumBuffer);

		//! Creamos el render target.
		SetRenderTargets();
		//! Seteamos el viewport.
		SetViewPort(m_pDeviceContext->GetDeviceContext());

		//! Seteamos el input layout.
		SetInputLayaout();
		//! Seteamos el tipo de topologia.
		SetPrimitiveTopology();

		//! Creamos el sample.
		CreateSample(m_pDevice->GetDevice());
		//! Creamos la camara del mundo.
		CreateCamera();

		//! Seteamos los shaders.
		SetShaders(m_pDeviceContext->GetDeviceContext(), m_pPixelShader->GetPixelShader(), 
				  m_pVertexShader->GetVertexShader());
				
	}

	/**
	 *	@brief Funcion para renderear.
	 */
	void ceGraphicsAPI::Render()
	{

		ID3D11DeviceContext* pDeviceContext = (ID3D11DeviceContext*)m_pDeviceContext->GetDeviceContext();
		IDXGISwapChain* pSwapChain = (IDXGISwapChain*)m_pSwapChain->GetSwapChain();
		ID3D11RenderTargetView* pRTV = (ID3D11RenderTargetView*)m_pRenderTargetView->GetRenderTargetView();
		ID3D11DepthStencilView* pDSV = (ID3D11DepthStencilView*)m_pDepthStencilView->GetDepthStencilView();
		
		
		float ClearColor[4] = { 0.7f, 0.2f, 0.2f, 1.0f }; // red, green, blue, alpha

		pDeviceContext->ClearRenderTargetView(pRTV, ClearColor);
		pDeviceContext->ClearDepthStencilView(pDSV, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1, 0);	

		ceMatrix_4X4 ArrayMatrix[g_iNumBuffer];
		ArrayMatrix[0] = m_Projection.Transpose();
		ArrayMatrix[1] = m_View.Transpose();
		ArrayMatrix[2] = m_World.Transpose();

		for (int32 i = 0; i < g_iNumBuffer; i++)
		{
			
			ceMatrix_4X4* TempProjection = (ceMatrix_4X4*)m_pConstantBuffers[i]->MapBuffer(pDeviceContext);
			*TempProjection = ArrayMatrix[i];
			m_pConstantBuffers[i]->UnMapBuffer(pDeviceContext);
			m_pConstantBuffers[i]->SetBuffer(pDeviceContext, i, 1, 0, NULL, NULL);
		}

		SetVertexBuffer(m_pDeviceContext->GetDeviceContext(), sizeof(ceVertex), 0);
		SetIndexBuffer(m_pDeviceContext->GetDeviceContext());

		pDeviceContext->DrawIndexed(36,0,0);
		pSwapChain->Present(1, 0);
	}

	/**
	 *	@brief Funcion para actualizar.
	 *	@param fTime: Tiempo de actualizacion.
	 */
	void ceGraphicsAPI::Update(float fTime)
	{
	}

	/**
	 *	@brief Funcion para destruir.
	 **/
	void ceGraphicsAPI::Destroy()
	{
		//! Si el device es diferente de nulo.
		if (m_pDevice != nullptr)
		{
			m_pDevice->Destroy();//! Llama su funcion destroy.
			delete m_pDevice;//! Elimina el puntero.
		}

		//! Si el devicecontext es diferente de nulo.
		if (m_pDeviceContext != nullptr)
		{
			m_pDeviceContext->Destroy();//! Llama su funcion destroy.
			delete m_pDeviceContext;//! Elimina el puntero.
		}

		//! Si el swapchain es diferente de nulo.
		if (m_pSwapChain != nullptr)
		{
			m_pSwapChain->Destroy();//! Llama su funcion destroy.
			delete m_pSwapChain;//! Elimina el puntero.
		}

		//! Si el rendertargetview es diferente de nulo.
		if (m_pRenderTargetView != nullptr)
		{
			m_pRenderTargetView->Destroy();//! Llama su funcion destroy.
			delete m_pRenderTargetView;//! Elimina el puntero.
		}

		//! Si el depthstencilview es diferente de nulo.
		if (m_pDepthStencilView != nullptr)
		{
			m_pDepthStencilView->Destroy();//! Llama su funcion destroy.
			delete m_pDepthStencilView;//! Elimina el puntero.
		}

		//! Si la textura es diferente de nulo.
		if (m_pTextureDSV != nullptr)
		{
			m_pTextureDSV->Destroy();//! Llama su funcion destroy.
			delete m_pTextureDSV;//! Elimina el puntero.
		}
		//! Si la textura es diferente de nulo.
		if (m_pTextureRTV != nullptr)
		{
			m_pTextureRTV->Destroy();//! Llama su funcion destroy.
			delete m_pTextureRTV;//! Elimina el puntero.
		}

		//! Si el inputlayaout es diferente de nulo.
		if (m_pInputLayaout != nullptr)
		{
			m_pInputLayaout->Destroy();//! Llama su funcion destroy.
			delete m_pInputLayaout;//! Elimina el puntero.
		}

		//! Si el shaderresoureview diferente de nulo.
		if (m_pShaderResourceView != nullptr)
		{
			m_pShaderResourceView->Destroy();//! Llama su funcion destroy.
			delete m_pShaderResourceView;//! Elimina el puntero.
		}

		//! Si el sampler es diferente de nulo.
		if (m_pSampler != nullptr)
		{
			m_pSampler->Destroy();//! Llama su funcion destroy.
			delete m_pSampler;//! Elimina el puntero.
		}

		//! Si el blob es diferente de nulo.
		if (m_pBlob != nullptr)
		{
			m_pBlob->Destroy();//! Llama su funcion destroy.
			delete m_pBlob;//! Elimina el puntero.
		}

	}

	/**
	 *	@brief Funcion para crear el Device.
	 **/
	void ceGraphicsAPI::CreateDevice()
	{
		//! Asignamos memoria al device.
		m_pDevice = new ceDevice();
		//! Mandamos llamar la funcion de inicializar.
		m_pDevice->Init();

	}

	/**
	 *	@brief Funcion para crear el DeviceContext.
	 **/
	void ceGraphicsAPI::CreateDeviceContext()
	{
		//! Asignamos memoria al devicecontext.
		m_pDeviceContext = new ceDeviceContext();
		//! Mandamos llamar la funcion de inicializar.
		m_pDeviceContext->Init();
	}

	/**
	 *  @brief Funcion para crear el swapchain.
	 *	@param uint32 Handle de la ventana.
	 *	@param int32	Ancho de la ventana.
	 *	@param int32	Alto de la ventana.
	 *	@param void** Puntero a un Device.
	 *	@param void** Puntero a un DeviceContext.
	 **/
	void ceGraphicsAPI::CreateSwapChain(uint32 uiScreenHandle, int32 iWidth, int32 iHeight, void** ppDevice, void** ppDeviceContext)
	{
		//! Asignamos memoria al swapchain.
		m_pSwapChain = new ceSwapChain();
		//! Mandamos llamar su funcion para inicializar.
		m_pSwapChain->Init();
		//! Creamos la cadena de intercambio y el dispositivo.
		m_pSwapChain->CreateSwapChainAndDevice(uiScreenHandle, iWidth, iHeight, ppDevice, ppDeviceContext);
			
	}

	/**
	 *	@brief Funcion para Crear el Render Target View.
	 *	@param void* Puntero al Swapchain.
	 *	@param void* Puntero al Device.
	 *	@param ceTexture* Textura.
	 **/
	void ceGraphicsAPI::CreateRenderTargetView(void* pSwapChain, void* pDevice, ceTexture* Texture)
	{
		
		//! Asignamos memoria al render target view.
		m_pRenderTargetView = new ceRenderTargetView();
		//! Mandamos llamar su funcion para inicializar.
		m_pRenderTargetView->Init();
		//! Creamos el render target view.
		m_pRenderTargetView->CreateRTV(pSwapChain, pDevice, Texture);
				
	}

	/**
	 *	@brief Funcion para Crear el Depth Stencil View.
	 *	@param void* Puntero al Device.
	 *	@param ceTexture* Textura.
	 **/
	void ceGraphicsAPI::CreateDepthStencilView(void* pDevice, ceTexture* pTexture)
	{
		//! Asignamos memoria al depth stencil view.	
		m_pDepthStencilView = new ceDepthStencilView();
		//! Mandamos llamar su funcion para inicializar.
		m_pDepthStencilView->Init();
		//! Creamos el depth stencil view.
		m_pDepthStencilView->CreateDSV(pDevice, pTexture, m_iWidth, m_iHeight);
	}

	/**
	 *	@brief Funcion para crear el Vertex Shader.
	 *	@param void* Device.
	 **/
	void ceGraphicsAPI::CreateVertexShader(void* pDevice)
	{
		//! Asignamos memoria al vertex shader.
		m_pVertexShader = new ceVertexShader();
		//! Mandamos llamar su funcion para inicializar.
		m_pVertexShader->Init();

		//! Asignamos memoria al blob.
		m_pBlob = new ceBlob();
		//! Mandamos llamar la funcion para inicializar.
		m_pBlob->Init();

		//! Compilamos el shader desde un archivo.
		CompileShaderFromFile("VertexShader.hlsl", "VSMain", "vs_5_0", m_pBlob);
		//! Creamos el vertex shader.
		m_pVertexShader->CreateVertexShader(pDevice, m_pBlob);
			
	}

	/**
	 *	@brief Funcion para crear el Pixel Shader.
	 *	@param void* Device.
	 **/
	void ceGraphicsAPI::CreatePixelShader(void* pDevice)
	{
		//! Asignamos memoria al pixel shader.
		m_pPixelShader = new cePixelShader();
		//! Mandamos llamar la funcion de inicializar.
		m_pPixelShader->Init();

		//! Asignamos memoria al blob.
		ceBlob* pBlob = new ceBlob();
		//! Mandamos llamar la funcion para inicializar.
		pBlob->Init();

		//! Compilamos el shader desde un archivo.
		CompileShaderFromFile("PixelShader.hlsl", "PSMain", "ps_5_0", pBlob);
		//! Creamos el pixel shader.
		m_pPixelShader->CreatePixelShader(pDevice, pBlob);		
	}

	/**
	 *	@brief Funcion para crear el InputLayout.
	 *	@param void* Device.
	 **/
	void ceGraphicsAPI::CreateInputLayout(void* pDevice)
	{
		//! Asignamos memoria al input layaout.
		m_pInputLayaout = new ceInputLayaout();
		//! Mandamos llamar la funcion de inicializar.
		m_pInputLayaout->Init();
		//! Creamos el input layout.
		m_pInputLayaout->CreateILO(pDevice, m_pBlob);
			
	}

	/**
	 *	@brief Funcion para crear el Vertex Buffer.
	 *	@param void* Device.
	 *	@param ceVertex* Vertices del Mesh.
	 **/
	void ceGraphicsAPI::CreateVertexBuffer(void* pDevice, ceVertex* MeshVertex)
	{
		//! Asignamos memoria al vertex buffer.
		m_pVertexBuffer = new ceBuffer();
		//! Mandamos llamar la funcion para inicializar.
		m_pVertexBuffer->Init();
		//! Creamos el vertex buffer.
		m_pVertexBuffer->CreateVertexBuffer(MeshVertex, pDevice, D3D11_USAGE_DEFAULT, D3D11_BIND_VERTEX_BUFFER, 0);	
	}

	/**
	 *	@brief Funcion para crear el Index Buffer.
	 *	@param void* Device.
	 *	@param ceVertex* Indices del Mesh.
	 **/
	void ceGraphicsAPI::CreateIndexBuffer(void* pDevice, uint32* uiIndices)
	{
		//! Asignamos memoria al index buffer.
		m_pIndexBuffer = new ceBuffer();
		//! Mandamos llamar la funcion de inicializar.
		m_pIndexBuffer->Init();
		//! Creamos el index buffer.
		m_pIndexBuffer->CreateIndexBuffer(uiIndices, pDevice, D3D11_USAGE_DEFAULT, D3D11_BIND_INDEX_BUFFER, 0);
		
	}
		
	/**
	 *	@brief Funcion para setear la Topologia.
	 **/
	void ceGraphicsAPI::SetPrimitiveTopology()
	{
		ID3D11DeviceContext* pDeviceContext = (ID3D11DeviceContext*)m_pDeviceContext->GetDeviceContext();
		pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	}

	/**
	 *	@brief Funcion para crear los ConstantBuffers.
	 *	@param void* Device.
	 **/
	void ceGraphicsAPI::CreateConstantBuffers(void* pDevice, const int32 iNumBuffers)
	{

		//! Asignamos el tamaño a la lista de buffers
		m_pConstantBuffers.resize(iNumBuffers);

		for (int32 i = 0; i < iNumBuffers; i++)
		{
			m_pConstantBuffers[i] = new ceBuffer();
			m_pConstantBuffers[i]->Init();
			m_pConstantBuffers[i]->CreateConstantBuffer(pDevice);
		}
		
	}

	/**
	 *	@brief Funcion para crear el Sampler.
	 *	@param void* Device.
	 **/
	void ceGraphicsAPI::CreateSample(void* pDevice)
	{
		//! Asignamos memoria al sampler.
		m_pSampler = new ceSampler();
		//! Mandamos llamar la funcion para inicializar.
		m_pSampler->Init();
		//! Creamos el sampler.
		m_pSampler->CreateSampler(pDevice);
			
	}

	/**
	 *	@brief Funcion para crear la camara.
	 **/
	void ceGraphicsAPI::CreateCamera()
	{
		
		RECT rc;
		GetClientRect(reinterpret_cast<HWND>(m_uiScreenHandle), &rc);//! Guardamos las dimensiones de la ventana en el RECT
		uint32 width = rc.right - rc.left;
		uint32 height = rc.bottom - rc.top;

		ceVector4D Eye(0.0f, 3.0f, -6.0f, 0.0f);
		ceVector4D At(0.0f, 0.0f, 0.0f, 0.0f);
		ceVector4D Up(0.0f, 1.0f, 0.0f, 0.0f);

		m_World.Zero();
		m_View.Zero();
		m_Projection.Zero();

		m_World.Identity();
		m_View.LookAtLeftH(Eye, At, Up);
		m_Projection.PerspectiveFOVLH(1.0f, 10000.0f, ceMath::PI_HALF / 2, width / (FLOAT)height);
	}

	/**
	 *	@brief Funcion para setear los render targets.
	 **/
	void ceGraphicsAPI::SetRenderTargets()
	{
		//! Asignamos el device a un temporal para acceder de una manera mas facil a la variable.
		ID3D11DeviceContext* pTempDevice = (ID3D11DeviceContext*)m_pDeviceContext->GetDeviceContext();
		//! Llamamos a la funcion OMSet.
		pTempDevice->OMSetRenderTargets(1, (ID3D11RenderTargetView**)m_pRenderTargetView->GetRenderTargetViewData(),
			(ID3D11DepthStencilView*)m_pDepthStencilView->GetDepthStencilView());
	}

	/**
	 *	@brief Funcion para setear el View Port.
	 *	@param void* DeviceContext.
	 **/
	void ceGraphicsAPI::SetViewPort(void* pDeviceContext)
	{
		ID3D11DeviceContext* pTempDeviceContext = (ID3D11DeviceContext*)pDeviceContext;
		// Setup the viewport
		D3D11_VIEWPORT vp;
		vp.Width = (float)m_iWidth;
		vp.Height = (float)m_iHeight;
		vp.MinDepth = 0.0f;
		vp.MaxDepth = 1.0f;
		vp.TopLeftX = 0;
		vp.TopLeftY = 0;
		pTempDeviceContext->RSSetViewports(1, &vp);
	}

	/**
	 *	@brief Funcion para setear el InputLayaout.
	 **/
	void ceGraphicsAPI::SetInputLayaout()
	{
		ID3D11DeviceContext* pDeviceContext = (ID3D11DeviceContext*)m_pDeviceContext->GetDeviceContext();
		ID3D11InputLayout* pIL = (ID3D11InputLayout*)m_pInputLayaout->GetInputLayout();

		//! Seteamos el input layout.
		pDeviceContext->IASetInputLayout(pIL);
	}

	/**
	 *	@brief Funcion para Setear el Vertex Buffer.
	 *	@param void* DeviceContext.
	 *	@param uint32 Stride.
	 *	@param uint32 Offset.
	 **/
	void ceGraphicsAPI::SetVertexBuffer(void* pDeviceContext, uint32 Stride, uint32 Offset)
	{
		m_pVertexBuffer->SetBuffer(pDeviceContext, 0, 1, 1, Stride, Offset);	
	}

	/**
	 *	@brief Funcion para setear el IndexBuffer.
	 *	@param void* DeviceContext.
	 **/
	void ceGraphicsAPI::SetIndexBuffer(void* pDeviceContext)
	{
		m_pIndexBuffer->SetBuffer(pDeviceContext, 0, 1, 2, NULL, NULL);
	}

	/**
	 *	@breif Funcion para setear los shaders.
	 *	@param void* DeviceContext.
	 *	@param void* PixelShader.
	 *	@param void* VertexShader.
	 **/
	void ceGraphicsAPI::SetShaders(void * pDeviceContext, void * pPixelShader, void * pVertexShader)
	{
		ID3D11DeviceContext* pTempDeviceContext = (ID3D11DeviceContext*)pDeviceContext;
		ID3D11VertexShader* pTempVertexShader = (ID3D11VertexShader*)pVertexShader;
		ID3D11PixelShader* pTempPixelShader = (ID3D11PixelShader*)pPixelShader;

		pTempDeviceContext->VSSetShader(pTempVertexShader, nullptr, 0);
		pTempDeviceContext->PSSetShader(pTempPixelShader, nullptr, 0);
	}

	/**
	 *	@brief Funcion para compilar un Shader desde un Archivo.
	 *	@param const char* Nombre del Archivo.
	 *	@param const String Punto de Entrada.
	 *	@param const String Shader Model.
	 *	@param ceBlob* Blob.
	 **/
	void ceGraphicsAPI::CompileShaderFromFile(const char* szFileName, const String szEntryPoint, 
											const String szShaderModel, ceBlob* ppBlobOut)
	{
		HRESULT hr = S_OK;
		

		//TODO: Implentar despues con mi propia clase de archivo.
		int32 iSize = 0;
		std::fstream file;
		String fileData;

		file.open(szFileName, std::ios::in | std::ios::out | std::ios::ate);
		iSize = file.tellg();//! Manda al final del archivo por tanto es el tamaño.
		file.seekg(0, std::fstream::beg);//! Funcion para regresar al inicio del archivo.

		
		fileData.resize(iSize + 1, 0);
		file.read(&fileData[0], iSize);
		file.seekg(iSize);
		file.close();



		DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
		// Set the D3DCOMPILE_DEBUG flag to embed debug information in the shaders.
		// Setting this flag improves the shader debugging experience, but still allows 
		// the shaders to be optimized and to run exactly the way they will run in 
		// the release configuration of this program.
		dwShaderFlags |= D3DCOMPILE_DEBUG;
#endif

		ID3DBlob* pErrorBlob;
		
		hr = D3DCompile(fileData.c_str(), fileData.size(),szFileName, nullptr, nullptr,
			szEntryPoint.c_str(),szShaderModel.c_str(),dwShaderFlags
			, 0, (ID3DBlob**)ppBlobOut->GetBlobData(), &pErrorBlob);

		if (FAILED(hr))
		{
			if (pErrorBlob != nullptr)
				OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
			if (pErrorBlob) 
				pErrorBlob->Release();
			std::cout << "Fallo al Cargar el Archivo" << std::endl;
		}

		if (pErrorBlob) 
			pErrorBlob->Release();

	}
}