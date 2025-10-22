#pragma once
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_win32.h"
#include "Win32Window.h"
#include "GL3Graphics.h"

#include <Windows.h>

class ImguiManager
{
public:
	ImguiManager(Win32Window& window, GL3Graphics& gfx);
	~ImguiManager();

public:
	void SetDarkTheme();
	void LoadFont(const char* fontPath);

	void NewFrame();

	void Render();

	ID3D11RenderTargetView* g_mainRenderTargetView = nullptr;
private:
	void Initialize();


private:
	Win32Window& m_Window;
	GL3Graphics& m_GFX;

	bool  g_SwapChainOccluded = false;

	int m_ResizeWidth = 0;
	int m_ResizeHeight = 0;
};

