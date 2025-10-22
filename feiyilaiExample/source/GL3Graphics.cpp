#include "header/GL3Graphics.h"

static HGLRC g_hRC = nullptr;

GL3Graphics::GL3Graphics(Win32Window& window)
	:m_Window(window)
{
    // Initialize OpenGL
    if (!CreateDeviceWGL(window.GetHWND(), &g_MainWindow))
    {
        CleanupDeviceWGL(window.GetHWND(), &g_MainWindow);
        ::DestroyWindow(window.GetHWND());
        ::UnregisterClassW(window.GetWndClass().lpszClassName, window.GetWndClass().hInstance);
        return;
    }

    if (!wglMakeCurrent(g_MainWindow.hDC, g_hRC))
    {
        return;
    }

    m_InitializationSuccessful = true;
}

GL3Graphics::~GL3Graphics()
{
    CleanupDeviceWGL(m_Window.GetHWND(), &g_MainWindow);
    wglDeleteContext(g_hRC);
}

bool GL3Graphics::CreateDeviceWGL(HWND hWnd, WGL_WindowData* data)
{
    HDC hDc = ::GetDC(hWnd);
    PIXELFORMATDESCRIPTOR pfd = { 0 };
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;

    const int pf = ::ChoosePixelFormat(hDc, &pfd);
    if (pf == 0)
        return false;
    if (::SetPixelFormat(hDc, pf, &pfd) == FALSE)
        return false;
    ::ReleaseDC(hWnd, hDc);

    data->hDC = ::GetDC(hWnd);
    if (!g_hRC)
        g_hRC = wglCreateContext(data->hDC);
    return true;
}

void GL3Graphics::CleanupDeviceWGL(HWND hWnd, WGL_WindowData* data)
{
    wglMakeCurrent(nullptr, nullptr);
    ::ReleaseDC(hWnd, data->hDC);
}

HGLRC& GL3Graphics::GetHRC()
{
    return g_hRC;
}
