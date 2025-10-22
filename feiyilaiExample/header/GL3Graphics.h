#pragma once
#include "Win32Window.h"
#include <Windows.h>
#include <d3d11.h>

class GL3Graphics
{
public:
	GL3Graphics(Win32Window& window);
	~GL3Graphics();

public:
	// Data stored per platform window
	struct WGL_WindowData { HDC hDC = nullptr; };

	bool IsInitializationSuccessful() { return m_InitializationSuccessful; }

    // Helper functions
	static bool CreateDeviceWGL(HWND hWnd, WGL_WindowData* data);

	static void CleanupDeviceWGL(HWND hWnd, WGL_WindowData* data);

	static HGLRC& GetHRC();
	WGL_WindowData& GetMainWindowData() { return g_MainWindow; }
private:
	bool m_InitializationSuccessful = false;
	Win32Window& m_Window;


	WGL_WindowData   g_MainWindow;

	// Data
	//ID3D11Device* g_pd3dDevice = nullptr;
	//ID3D11DeviceContext* g_pd3dDeviceContext = nullptr;
	//IDXGISwapChain* g_pSwapChain = nullptr;

	//UINT                     g_ResizeWidth = 0, g_ResizeHeight = 0;
	//ID3D11RenderTargetView* g_mainRenderTargetView = nullptr;
};

