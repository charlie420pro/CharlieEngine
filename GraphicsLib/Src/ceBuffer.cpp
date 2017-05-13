#include "ceBuffer.h"
#include <d3d11.h>
#include <d3dcompiler.h>

namespace ceEngineSDK
{
	struct ceBufferDX
	{
		ID3D11Buffer*  m_pBufferDX;	
		void Destroy() { m_pBufferDX->Release(); }
	};

	ceBuffer::ceBuffer()
	{
		m_pBuffer = nullptr;
	}


	ceBuffer::~ceBuffer()
	{
		m_pBuffer = nullptr;
	}

	void ceBuffer::Init()
	{
		if (m_pBuffer == nullptr)
			m_pBuffer = new ceBufferDX();
		
	}

	void ceBuffer::Destroy()
	{
		if (m_pBuffer != nullptr)
		{
			m_pBuffer->Destroy();
			delete m_pBuffer;
		}
	}

	/**
	 *	@brief Funcion que retorna un VertexBuffer de DirectX por referencia.
	 *  @return void** El VertexBuffer reinterpretado como un void.
	 */
	void** ceBuffer::GetBufferData()
	{
		//! 
		return (void**)&m_pBuffer->m_pBufferDX;
	}

	/**
	*	@brief Funcion que retorna un Buffer de DirectX.
	*  @return void** El Buffer que cambia cada frame reinterpretado como un void.
	*/
	void* ceBuffer::GetBuffer()
	{
		//! 
		return (void*)m_pBuffer->m_pBufferDX;
	}

	void ceBuffer::SetBuffer(void* pDeviceContext, uint32 uiStartSlot, uint32 uiNumBuffer, uint32 iBufferType, uint32 Stride, uint32 Offset)
	{
		ID3D11DeviceContext* tempDeviceContext = (ID3D11DeviceContext*)pDeviceContext;

		if (iBufferType == CONSTANT_BUFFER)
			tempDeviceContext->VSSetConstantBuffers(uiStartSlot, uiNumBuffer, &m_pBuffer->m_pBufferDX);
		
		else if (iBufferType == VERTEX_BUFFER)
			tempDeviceContext->IASetVertexBuffers(uiStartSlot, uiNumBuffer, &m_pBuffer->m_pBufferDX, &Stride, &Offset);

		else if (iBufferType == INDEX_BUFFER)
			tempDeviceContext->IASetIndexBuffer(m_pBuffer->m_pBufferDX, DXGI_FORMAT_R32_UINT, 0);

		else
			return;
	}

	void ceBuffer::CreateVertexBuffer(ceVertex* Data, void * pDevice, int32 iUsageFlag, int32 iBindFlags, int32 iAccessFlag)
	{
		HRESULT hr = S_OK;
		ID3D11Device* tempDevice = (ID3D11Device*)pDevice;

		D3D11_BUFFER_DESC bd;
		ZeroMemory(&bd, sizeof(bd));
		bd.Usage = (D3D11_USAGE)iUsageFlag;
		bd.ByteWidth = sizeof(ceVertex) * 24;
		bd.BindFlags = (D3D11_BIND_FLAG)iBindFlags;
		bd.CPUAccessFlags = (D3D11_CPU_ACCESS_FLAG)iAccessFlag;
		bd.MiscFlags = 0;
		bd.StructureByteStride = 0;


		D3D11_SUBRESOURCE_DATA InitData;
		ZeroMemory(&InitData, sizeof(InitData));
		InitData.pSysMem = Data;

		hr = tempDevice->CreateBuffer(&bd, &InitData, &m_pBuffer->m_pBufferDX);
		if (FAILED(hr))
			std::cout << "Fallo al Crear el VertexBuffer" << std::endl;
	}

	void ceBuffer::CreateIndexBuffer(uint32* Data, void * pDevice, int32 iUsageFlag, int32 iBindFlags, int32 iAccessFlag)
	{
		HRESULT hr = S_OK;
		ID3D11Device* tempDevice = (ID3D11Device*)pDevice;

		D3D11_BUFFER_DESC bd;
		ZeroMemory(&bd, sizeof(bd));
		bd.Usage = (D3D11_USAGE)iUsageFlag;
		bd.ByteWidth = sizeof(uint32) * 36;
		bd.BindFlags = (D3D11_BIND_FLAG)iBindFlags;
		bd.CPUAccessFlags = (D3D11_CPU_ACCESS_FLAG)iAccessFlag;
		bd.MiscFlags = 0;
		bd.StructureByteStride = 0;


		D3D11_SUBRESOURCE_DATA InitData;
		ZeroMemory(&InitData, sizeof(InitData));
		InitData.pSysMem = Data;

		hr = tempDevice->CreateBuffer(&bd, &InitData, &m_pBuffer->m_pBufferDX);
		if (FAILED(hr))
			std::cout << "Fallo al Crear el IndexBuffer" << std::endl;

		
	}

	void ceBuffer::CreateConstantBuffer(void * pDevice)
	{
		HRESULT hr = S_OK;
		ID3D11Device* tempDevice = (ID3D11Device*)pDevice;

		D3D11_BUFFER_DESC bd;
		ZeroMemory(&bd, sizeof(bd));
		bd.Usage = D3D11_USAGE_DYNAMIC;
		bd.ByteWidth = (sizeof(ceMatrix_4X4) + 15) & 0xfffffff0;
		bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		bd.MiscFlags = 0;
		bd.StructureByteStride = 0;

		hr = tempDevice->CreateBuffer(&bd, nullptr, &m_pBuffer->m_pBufferDX);
		
		if (FAILED(hr))
			std::cout << "Fallo al Crear el ConstantBuffer" << std::endl;

	}

	void * ceBuffer::MapBuffer(void* pDeviceContext)
	{
		D3D11_MAPPED_SUBRESOURCE ms = {};
		ID3D11DeviceContext* tempDeviceContext = (ID3D11DeviceContext*)pDeviceContext;

		tempDeviceContext->Map(m_pBuffer->m_pBufferDX, 0, D3D11_MAP_WRITE_DISCARD, 0, &ms);
		return ms.pData;
	}

	void ceBuffer::UnMapBuffer(void* pDeviceContext)
	{
		ID3D11DeviceContext* tempDeviceContext = (ID3D11DeviceContext*)pDeviceContext;
		tempDeviceContext->Unmap(m_pBuffer->m_pBufferDX, 0);
	}
	
}