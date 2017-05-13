#include "ceBlob.h"
#include <d3d11.h>
#include <d3dcompiler.h>


namespace ceEngineSDK
{
	/**
	*	@brief Estructura para utilizacion de blob.
	*/
	struct BlobDX
	{
		//! Puntero a un blob de DirectX.
		ID3DBlob* m_pBlobOut;

		//! Funcion para liberar memoria del blob.
		void Destroy() { if (m_pBlobOut != nullptr) m_pBlobOut->Release(); }
	};

	ceBlob::ceBlob()
	{
		m_pBlob = nullptr;
	}

	ceBlob::~ceBlob()
	{
		m_pBlob = nullptr;
	}

	void ceBlob::Init()
	{
		if (m_pBlob == nullptr)
			m_pBlob = new BlobDX();
	}

	void ceBlob::Destroy()
	{
		if (m_pBlob != nullptr)
		{
			m_pBlob->Destroy();
			delete m_pBlob;
		}
	}
	void ** ceBlob::GetBlobData()
	{
		//! Regresa el Blob que no cambia interpretado como un void** para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void**>(&this->m_pBlob->m_pBlobOut);
	}
	
	const void * ceBlob::GetBufferPointer()
	{
		return m_pBlob->m_pBlobOut->GetBufferPointer();
	}

	SIZE_T ceBlob::GetBufferSize()
	{
		return m_pBlob->m_pBlobOut->GetBufferSize();
	}

	void * ceBlob::GetBlob()
	{
		//! Regresa el Blob que no cambia interpretado como un void* para utilizarlo fuera de este archivo cpp.
		return reinterpret_cast<void*>(this->m_pBlob->m_pBlobOut);
	}
}