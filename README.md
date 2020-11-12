# Misaka Window System
Static C++ library for creating window that will be used in combination with DirectX or OpenGL projects. Also provides interface for keyboard and mouse events.

> This library is still in development and will be expanded in future.
> :warning: **Not to be used in production!**
<p align="center">
    <br>
    <img src="img.PNG" width="500" >
</p>

## Structure
Misaka window system consists for three main classes:

* Window
* Keyboard
* Mouse


## Creating window example

```.cpp
#include <MisakaWindowSystem.h>

INT WINAPI Misaka::Main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT iShowCmd)
{
    Misaka::Window::Configuration conf(hInstance, iShowCmd);
    Misaka::Window* win = Misaka::Window::CreateWindowInstance(700, 400, L"Misaka Window", conf);

    while (win->IsAlive())
    {
        win->PollEvents();
    }
    
    delete win;
    return MISAKA_QUIT_OK;
}

MISAKA_RUN_APPLICATION;
```
