#include <MisakaWindowSystem.h>
#include <iostream>


INT WINAPI Misaka::Main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT iShowCmd)
{
    Misaka::Window::Configuration conf(hInstance, iShowCmd);
    Misaka::Window* win = Misaka::Window::CreateWindowInstance(700, 400, L"Title", conf);

    while (win->IsAlive())
    {
        win->PollEvents();
    }
    
    delete win;
    return MISAKA_QUIT_OK;
}

MISAKA_RUN_APPLICATION;