#include "ceAplication.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <exception>


namespace ceEngineSDK
{
	//! Utilizacion de excepciones
	using std::exception;
	//! Nombre guardado como cadena
	const char* g_szClassName = "Engine_WN_Class";
	//! Puntero a una aplicacion.
	ceAplication* g_AppBase = nullptr;

	/**
	 *	@brief Callback para mandar llamarel windowsproc
	 *	@param hWnd: Handle de la ventana.
	 *	@param uint32: Variable para el mensaje a recibir.
	 *	@param wParam: Parametro alto.
	 *	@param lParam: Parametro bajo.
	 */
	LRESULT CALLBACK WndProc(HWND hWnd, uint32 message, WPARAM wParam, LPARAM lParam)
	{
	
		//! Interpretamos el mensaje y dependiendo del caso hacemos las funcionalidades.
		switch (message)
		{

		case WM_DESTROY://! En el caso de Destroy llama a postquitmessage.
			PostQuitMessage(0);
			break;
		case WM_SIZE:

			break;
		default://! En el caso default definimos el windowproc.
			return DefWindowProc(hWnd, message, wParam, lParam);
		}

		return 0;
	}

	/**
	 *	@brief Constructor default de la clase.
	 */
	ceAplication::ceAplication()
	{
		g_AppBase = this;
		m_szTitle = "Engine";
		m_iScreenHandle = 0;
		m_iWidth = 1024;
		m_iHeight = 720;
	}

	/**
	 *	@brief Destructor default de la clase.
	 */
	ceAplication::~ceAplication()
	{
	}

	/**
	 *	@brief Funcion para correr la aplicacion.
	 *	@return Resultado de correr la aplicacion.
	 */
	int32 ceAplication::Run()
	{
		//! Registramos ventana
		HINSTANCE hInstance = GetModuleHandleA(0);
		WNDCLASSEXA wcex;
		memset(&wcex, 0, sizeof(WNDCLASSEXA));

		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = WndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = GetModuleHandle(NULL);
		wcex.hIcon = 0;
		wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
		wcex.lpszMenuName = 0;
		wcex.lpszClassName = g_szClassName;
		wcex.hIconSm = 0;

		//! Checamos que se haya registrado bien la ventana.
		if (RegisterClassEx(&wcex) == 0)
			throw exception("Fallo al registrar la ventana"); //! En caso de no haberse registrado bien manda este mensaje.
	
		
		//! Creamos la ventana.
		HWND hwnd = CreateWindow(g_szClassName, m_szTitle.c_str(), WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, m_iWidth, m_iHeight, nullptr, nullptr, hInstance, nullptr);
		
		//! Si la ventana no se creo.
		if (!hwnd)
			throw exception("Fallo al crear la ventana");//"! Manda mensaje de fallo al crear la ventana.

		//! Mostramos la ventana.
		ShowWindow(hwnd, SW_SHOW);
	
		
		//! Inicializamos graphics.
		m_Graphics.Init(reinterpret_cast<uint32>(hwnd), m_iWidth, m_iHeight);

	
		//! Frecuencia.
		LARGE_INTEGER Frecuancy;
		//! Counter.
		LARGE_INTEGER Counter;

		QueryPerformanceFrequency(&Frecuancy);
		QueryPerformanceCounter(&Counter);
		
		//! Mensaje
		MSG msg = {0};

		//! Variable para el tiempo final.
		float fEndTime = 0;
		//! Variable para el tiempo inicial.
		float fStartTime = 0;
	
		//! Loop de aplicacion.
		while (msg.message != WM_QUIT)
		{
			QueryPerformanceCounter(&Counter);

			//! El Tiempo final lo igualamos al inicial.
			fEndTime = fStartTime;
			fStartTime = Counter.QuadPart / Frecuancy.QuadPart;

			if (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE))
			{
				//TranslateMessage(&msg);
				DispatchMessageA(&msg);
			}
			
			double dDeltaTime = fStartTime - fEndTime/Frecuancy.QuadPart;
			//! Aqui actualizamos la aplicacion.
			UpDate((float)dDeltaTime);
			//! Aqui se renderea lo que sea de la aplicacion.
			Render();
		}
		//! Llamamos onpredestroy para antes de llamar el destroy.
		OnPreDestroy();
		//! Llamamos destroy para eliminar lo que sea necesario 
		Destroy();

		return (int32)msg.wParam;
	}

	/**
	 *	@brief Funcion para pre inicializar.
	 */
	void ceAplication::OnPreInitialize()
	{
	}

	/**
	 *	@brief Funcion para usar en el momento de inicializar.
	 */
	void ceAplication::OnInitialize()
	{
	}

	/**
	 *	@brief Funcion para utilizar despues de inicializar.
	 */
	void ceAplication::OnPosInitialize()
	{
	}

	/**
	 *	@brief Funcion para utilizar antes de destruir.
	 */
	void ceAplication::OnPreDestroy()
	{
	}

	/**
	 *	@brief Funcion para utilizar en el momento de destruir.
	 */
	void ceAplication::OnDestroy()
	{
	}

	/**
	 *	@brief Funcion para actualizar.
	 */
	void ceAplication::UpDate(float fDelta)
	{
	}

	/**
	 *	@brief Funcion para renderear.
	 */
	void ceAplication::Render()
	{
		m_Graphics.Render();
	}

	/**
	 *	@brief Funcion para hacer resize.
	 */
	void ceAplication::OnSize()
	{
	}

	/**
	 *	@brief Funcion para inicializar.
	 */
	void ceAplication::Init()
	{
	}

	/**
	 *	@brief Funcion para destruir.
	 */
	void ceAplication::Destroy()
	{
		m_Graphics.Destroy();
	}
}