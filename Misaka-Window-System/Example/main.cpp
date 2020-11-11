#include <MisakaWindowSystem.h>
#include <iostream>


INT WINAPI Misaka::Main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT iShowCmd)
{
    Misaka::Window::Configuration conf(hInstance, iShowCmd);
    Misaka::Window* win = Misaka::Window::CreateWindowInstance(700, 400, L"Title", conf);
    Misaka::Keyboard* kbd = Misaka::Keyboard::CreateKeyboardInstance();
    Misaka::Mouse* mouse = Misaka::Mouse::CreateMouseInstance();
    while (win->IsAlive())
    {
        win->PollEvents();

        if (mouse->GetButton() == MISAKA_BUTTON_RIGHT && mouse->GetAction() == Misaka::Mouse::Action::Release)
            std::cout << "LEFT" << std::endl;

        if (mouse->GetScroll() == MISAKA_SCROLL_DOWN)
            std::cout << "DDDD" << std::endl;

        if (kbd->GetKey() && kbd->GetAction() == Misaka::Keyboard::Action::Press)
            std::cout << kbd->GetKey() << std::endl;

        if(win->IsResized())
            std::cout << win->GetWidth() << ":" << win->GetHeight() << std::endl;

        mouse->ResetState();
        kbd->ResetState();
    }
    
    delete win;
    delete kbd;
    return MISAKA_QUIT_OK;
}

MISAKA_RUN_APPLICATION;