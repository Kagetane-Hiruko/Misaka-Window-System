#pragma once

#include <windows.h>
#include <windowsx.h>
#include <gl/GL.h>
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

        int miWidth;
        int miHeight;
        bool mbResized;


    public:
        static inline Window* mWindow;
        static Window* CreateWindowInstance(INT iWidth, INT iHeight, LPCWSTR lpTitle, Configuration config);
        static Window* GetInstance();

        bool IsAlive();
        void PollEvents();
        bool IsResized();
        int GetWidth() const { return miWidth; }
        int GetHeight() const { return miHeight; }
        
        virtual ~Window();

    protected:
        explicit Window() = delete;
        explicit Window(INT iWidth, INT iHeight, LPCWSTR lpTitle, Configuration config);

        static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    };

    INT WINAPI Main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT iShowCmd);
}

#define MISAKA_QUIT_OK 0
#define MISAKA_RUN_APPLICATION \
    int main(const int argc, const char** argv)   \
    {											  \
        return Misaka::Main(GetModuleHandle(NULL), NULL, GetCommandLineA(), SW_SHOWNORMAL); \
    }