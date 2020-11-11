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
        static inline Window* mWindow;

    public:
        
        static Window* CreateWindowInstance(INT iWidth, INT iHeight, LPCWSTR lpTitle, Configuration config);
        static Window* GetInstance();

        bool IsAlive();
        void PollEvents();
        bool IsResized() const { return mbResized; }
        int GetWidth() const { return miWidth; }
        int GetHeight() const { return miHeight; }
        
        virtual ~Window();

    protected:
        explicit Window() = delete;
        explicit Window(INT iWidth, INT iHeight, LPCWSTR lpTitle, Configuration config);

        static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    };

    class Keyboard
    {
    public:
        enum class Action { Press, Release, None };
   
    private:
        friend class Window;
        INT miKey;
        Action meAction;
        
    protected:
        static inline Keyboard* mKeyboard;
    
    public:
        static Keyboard* CreateKeyboardInstance();
        static Keyboard* GetInstance();

        bool IsKeyDown(INT iKey);
        int GetKey() const { return miKey; }
        Action GetAction() const { return meAction; }

        void ResetState();

    protected:
        explicit Keyboard();
    };

    INT WINAPI Main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT iShowCmd);
}

#define MISAKA_QUIT_OK 0
#define MISAKA_RUN_APPLICATION \
    int main(const int argc, const char** argv)   \
    {											  \
        return Misaka::Main(GetModuleHandle(NULL), NULL, GetCommandLineA(), SW_SHOWNORMAL); \
    }