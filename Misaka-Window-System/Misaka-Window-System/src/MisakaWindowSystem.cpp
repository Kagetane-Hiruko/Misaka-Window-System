#include "MisakaWindowSystem.h"

#include <iostream>

namespace Misaka
{
    Window::Configuration::Configuration(HINSTANCE hInstance, INT iShowCmd)
    {
        ZeroMemory(this, sizeof(Window::Configuration));
        this->cbSize        = sizeof(WNDCLASSEX);
        this->style         = CS_HREDRAW | CS_VREDRAW;
        this->lpfnWndProc   = Window::WindowProc;
        this->cbClsExtra    = 0;
        this->cbWndExtra    = 0;
        this->hInstance     = hInstance;
        this->hIcon         = NULL;
        this->hCursor       = LoadCursor(NULL, IDC_ARROW);
        this->hbrBackground = (HBRUSH)COLOR_WINDOW;
        this->lpszMenuName  = NULL;
        this->lpszClassName = L"WindowCLass1";
        this->hIconSm       = NULL;
        this->iShowCmd      = iShowCmd;
    }

    Window* Window::CreateWindowInstance(INT iWidth, INT iHeight, LPCWSTR lpTitle, Window::Configuration config)
    {
        if (mWindow == NULL)
        {
            mWindow = new Window(iWidth, iHeight, lpTitle, config);
        }
        return mWindow;
    }

    Window* Window::GetInstance()
    {
        return mWindow;
    }

    bool Window::IsAlive()
    {
        return IsWindow(mhWnd);
    }

    void Window::PollEvents()
    {
        if (PeekMessage(&mMsg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&mMsg);
            DispatchMessage(&mMsg);
        }
    }

    bool Window::IsResized()
    {
        if (mbResized)
        {
            mbResized = FALSE;
            return TRUE;
        }
        return FALSE;
    }
    Window::~Window()
    {

    }
   
    Window::Window(INT iWidth, INT iHeight, LPCWSTR lpTitle, Configuration config)
        : 
        miWidth(iWidth),
        miHeight(iHeight),
        mbResized(FALSE)
    {
        RegisterClassEx(&config);
        RECT winRect = { 0, 0, iWidth, iHeight };
        AdjustWindowRect(&winRect, WS_OVERLAPPEDWINDOW, FALSE);
        mhWnd = CreateWindowEx(NULL,
                               config.lpszClassName,
                               lpTitle,
                               WS_OVERLAPPEDWINDOW,
                               300,
                               300,
                               winRect.right - winRect.left,
                               winRect.bottom - winRect.top,
                               NULL,
                               NULL,
                               config.hInstance,
                               NULL);
        ShowWindow(mhWnd, config.iShowCmd);
        ZeroMemory(&mMsg, sizeof(MSG));
    }

    LRESULT CALLBACK Window::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        Window* win = Window::GetInstance();
        switch (message)
        {
        case WM_SIZE:
        {
            if (win != NULL)
            {
                RECT winRect = { 0 };
                GetClientRect(hWnd, &winRect);
                win->miWidth = winRect.right;
                win->miHeight = winRect.bottom;
                win->mbResized = TRUE;
            }
            return 0;
        }
        break;
        default:
        {

            return DefWindowProc(hWnd, message, wParam, lParam);
        }
        }
    }
}