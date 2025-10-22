#pragma once
#include <Windows.h>

class Win32Window
{
public:
	Win32Window(const wchar_t* title, int width = 800, int height = 600);
	~Win32Window();

public:
	HWND GetHWND() const { return m_HWND; }

	WNDCLASSEXW GetWndClass() const { return m_WndClass; }

	void Show();

	void WindowUpdate();

	// Get window width
	int GetWindowWidth() const;
	// Get window height
	int GettWindowHeight() const;
	// Get window size (width and height)
	void GetWindowSize(int& width, int& height) const;

    // Get window width
    int GetWidth() const;
    // Get window height
	int GetHeight() const;
    // Get window size (width and height)
	void GetClientSize(int& width, int& height) const;

	bool HandleMessage();

	// Win32 message handler
	// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
	// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
	// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
	// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
	static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
private:
	HWND m_HWND;
	WNDCLASSEXW m_WndClass;
	int m_Width;
	int m_Height;
};

