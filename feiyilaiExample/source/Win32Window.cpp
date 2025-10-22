#include "header/Win32Window.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

static int g_ResizeWidth = 0;
static int g_ResizeHeight = 0;

Win32Window::Win32Window(const wchar_t* title, int width, int height)
{
    // Make process DPI aware and obtain main monitor scale
	//ImGui_ImplWin32_EnableDpiAwareness(); // FIXME: This somehow doesn't work in the Win32+OpenGL example. Why?
    float main_scale = ImGui_ImplWin32_GetDpiScaleForMonitor(::MonitorFromPoint(POINT{ 0, 0 }, MONITOR_DEFAULTTOPRIMARY));

    // Create application window
    m_WndClass = { sizeof(m_WndClass), CS_OWNDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, L"ImGui Example", nullptr };
    ::RegisterClassExW(&m_WndClass);
    m_HWND = ::CreateWindowExW(0L, m_WndClass.lpszClassName, title, WS_OVERLAPPEDWINDOW, 100, 100, (int)(width * main_scale), (int)(height * main_scale), nullptr, nullptr, m_WndClass.hInstance, nullptr);
}

Win32Window::~Win32Window()
{
    ::DestroyWindow(m_HWND);
    ::UnregisterClassW(m_WndClass.lpszClassName, m_WndClass.hInstance);
}

void Win32Window::Show()
{
    ::ShowWindow(m_HWND, SW_SHOWDEFAULT);
}

void Win32Window::WindowUpdate()
{
    ::UpdateWindow(m_HWND);
}

int Win32Window::GetWindowWidth() const
{
    RECT rect;
    GetWindowRect(m_HWND, &rect);
    return rect.right - rect.left;
}

int Win32Window::GettWindowHeight() const
{
    RECT rect;
    GetWindowRect(m_HWND, &rect);
    return rect.bottom - rect.top;
}

void Win32Window::GetWindowSize(int& width, int& height) const
{
    RECT rect;
    GetWindowRect(m_HWND, &rect);
    width = rect.right - rect.left;
    height = rect.bottom - rect.top;
}

int Win32Window::GetWidth() const
{
    return g_ResizeWidth;
    //RECT rect;
    //GetClientRect(m_HWND, &rect);
    //return rect.right - rect.left;
}

int Win32Window::GetHeight() const
{
    return g_ResizeHeight;

    //RECT rect;
    //GetClientRect(m_HWND, &rect);
    //return rect.bottom - rect.top;
}

void Win32Window::GetClientSize(int& width, int& height) const
{
    RECT rect;
    GetClientRect(m_HWND, &rect);
    width = rect.right - rect.left;
    height = rect.bottom - rect.top;
}

bool Win32Window::HandleMessage()
{
    static bool done = false;
    // Poll and handle messages (inputs, window resize, etc.)
	// See the WndProc() function below for our to dispatch events to the Win32 backend.
    MSG msg;
    while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
    {
        ::TranslateMessage(&msg);
        ::DispatchMessage(&msg);
        if (msg.message == WM_QUIT)
            return false;
    }

    if (done)
        return false;

    if (::IsIconic(m_HWND))
    {
        ::Sleep(10);
    }

    return true;
}

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
LRESULT WINAPI Win32Window::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (wParam != SIZE_MINIMIZED)
        {
            g_ResizeWidth = LOWORD(lParam);
            g_ResizeHeight = HIWORD(lParam);
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProcW(hWnd, msg, wParam, lParam);
}