#include <MisakaWindowSystem.h>
#include <iostream>


INT WINAPI Misaka::Main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT iShowCmd)
{
    Misaka::Window::Configuration conf(hInstance, iShowCmd);
    Misaka::Window* win = Misaka::Window::CreateWindowInstance(700, 400, L"Title", conf);
    Misaka::Keyboard* kbd = Misaka::Keyboard::CreateKeyboardInstance();
    int i = 0;
    while (win->IsAlive())
    {
        win->PollEvents();

        if (kbd->GetKey() && kbd->GetAction() == Misaka::Keyboard::Action::Press)
            std::cout << kbd->GetKey() << std::endl;

        if(win->IsResized())
            std::cout << win->GetWidth() << ":" << win->GetHeight() << std::endl;

        kbd->ResetState();
    }
    
    delete win;
    return MISAKA_QUIT_OK;
}

MISAKA_RUN_APPLICATION;