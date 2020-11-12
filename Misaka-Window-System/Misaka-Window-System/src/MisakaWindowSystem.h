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
        HWND GetHandle() const { return mhWnd; }
        void Close();

        virtual ~Window();

    protected:
        explicit Window() = delete;
        explicit Window(INT iWidth, INT iHeight, LPCWSTR lpTitle, Configuration config);

        static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    };

    class Keyboard
    {
    public:
        enum class Action { None, Press, Release };
   
    protected:
        friend class Window;
        Action meActions[255];
        static inline Keyboard* mKeyboard;
    
    public:
        static Keyboard* CreateKeyboardInstance();
        static Keyboard* GetInstance();

        bool IsKeyDown(INT iKey);
        Action GetAction(INT iKey) const { return meActions[iKey]; }

        void ResetState();

        virtual ~Keyboard();

    protected:
        explicit Keyboard();
    };

    class Mouse
    {
    public:
        enum class Action { None, Press, Release };

    protected:
        friend class Window;

        Action mActions[3];
        POINT mPoint;
        INT miScroll;

        static inline Mouse* mMouse;
    public:
        static Mouse* CreateMouseInstance();
        static Mouse* GetInstance();

        int GetScroll() const { return miScroll; }

        Action GetLeftButton() const { return mActions[0]; }
        Action GetRightButton() const { return mActions[1]; }
        Action GetMiddleButton() const { return mActions[1]; }

        int GetPosX() const { return mPoint.x; }
        int GetPosY() const { return mPoint.y; }
        bool IsDown(INT iButton);

        void ResetState();

        virtual ~Mouse();
    protected:
        explicit Mouse();
    };

    INT WINAPI Main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT iShowCmd);
}

#define MISAKA_QUIT_OK 0
#define MISAKA_RUN_APPLICATION \
    int main(const int argc, const char** argv)   \
    {											  \
        return Misaka::Main(GetModuleHandle(NULL), NULL, GetCommandLineA(), SW_SHOWNORMAL); \
    }