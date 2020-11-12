#include "MisakaWindowSystem.h"

#include <iostream>

namespace Misaka
{
    /*------------------------------------------------------------------------
                                      Window
    ------------------------------------------------------------------------*/

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
        mbResized = FALSE;
        while (PeekMessage(&mMsg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&mMsg);
            DispatchMessage(&mMsg);
        }
    }

    void Window::Close()
    {
        DestroyWindow(mhWnd);
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
        Keyboard* kbd = Keyboard::GetInstance();
        Mouse* mouse = Mouse::GetInstance();
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
        case WM_MOUSEWHEEL:
        {
            mouse->miScroll = wParam;
            return 0;
        }
        break;
        case WM_KEYDOWN: case WM_KEYUP:
        {
            if (kbd != NULL)
            {
                kbd->meActions[wParam] = (message == WM_KEYDOWN) ? Keyboard::Action::Press : Keyboard::Action::Release;
            }
            return 0;
        }
        break;
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        }
        break;        
        case WM_LBUTTONDOWN: case WM_RBUTTONDOWN: case WM_MBUTTONDOWN:
        {
            if (mouse != NULL)
            {
                (message == WM_LBUTTONDOWN) ? mouse->mActions[0] = Mouse::Action::Press :
                (message == WM_RBUTTONDOWN) ? mouse->mActions[1] = Mouse::Action::Press :
                                              mouse->mActions[2] = Mouse::Action::Press ;
            }
            return 0;
        }
        break;
        case WM_LBUTTONUP: case WM_RBUTTONUP: case WM_MBUTTONUP:
        {
            if (mouse != NULL)
            {
                (message == WM_LBUTTONUP) ? mouse->mActions[0] = Mouse::Action::Release :
                (message == WM_RBUTTONUP) ? mouse->mActions[1] = Mouse::Action::Release :
                                            mouse->mActions[2] = Mouse::Action::Release ;
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

    /*------------------------------------------------------------------------
                                    Keyboard
    ------------------------------------------------------------------------*/
    
    Keyboard* Keyboard::CreateKeyboardInstance()
    {
        if (mKeyboard == NULL)
        {
            mKeyboard = new Keyboard();
        }
        return mKeyboard;
    }

    Keyboard* Keyboard::GetInstance()
    {
        return mKeyboard;
    }

    bool Keyboard::IsKeyDown(INT iKey)
    {
        return GetKeyState(iKey) & 0x8000;
    }

    void Keyboard::ResetState()
    {
        ZeroMemory(meActions, sizeof(meActions));
    }

    Keyboard::Keyboard()
    {
        ZeroMemory(meActions, sizeof(meActions));
    }

    Keyboard::~Keyboard()
    {

    }

    /*------------------------------------------------------------------------
                                      Mouse
    ------------------------------------------------------------------------*/

    Mouse* Mouse::CreateMouseInstance()
    {
        if (mMouse == NULL)
        {
            mMouse = new Mouse();
        }
        return mMouse;
    }

    Mouse* Mouse::GetInstance()
    {
        return mMouse;
    }

    void Mouse::ResetState()
    {
        ZeroMemory(mActions, sizeof(mActions));
       
        GetCursorPos(&mPoint);
        ScreenToClient(Window::GetInstance()->GetHandle(), &mPoint);

        miScroll = MISAKA_SCROLL_NONE;
    }

    bool Mouse::IsDown(INT iButton)
    {
        return (GetKeyState(iButton) & 0x8000);
    }

    Mouse::Mouse()
        :
        mPoint({ 0, 0 })
    {
    }

    Mouse::~Mouse()
    {

    }
}