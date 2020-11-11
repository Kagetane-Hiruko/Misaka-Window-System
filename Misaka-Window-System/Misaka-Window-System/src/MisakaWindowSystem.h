#pragma once

#include <windows.h>
#include <windowsx.h>

#include "Keys.h"

namespace Misaka
{
    class Window
    {
    public:
        struct Configuration : public WNDCLASSEX
        {
            INT iShowCmd;
            explicit Configuration(HINSTANCE hInstance, INT iShowCmd);
        };

    protected:
        HWND mhWnd;
        MSG mMsg;

    public:
        static inline Window* mWindow;
        static Window* CreateWindowInstance(INT iWidth, INT iHeight, LPCWSTR lpTitle, Configuration config);
        static Window* GetInstance();

        bool IsAlive();
        void PollEvents();
        
        virtual ~Window();

    protected:
        explicit Window() = delete;
        explicit Window(INT iWidth, INT iHeight, LPCWSTR lpTitle, Configuration config);

        static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    };

    INT WINAPI Main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT iShowCmd);
}

#define MISAKA_RUN_APPLICATION \
    int main(const int argc, const char** argv)   \
    {											  \
        return Misaka::Main(GetModuleHandle(NULL), NULL, GetCommandLineA(), SW_SHOWNORMAL); \
    }