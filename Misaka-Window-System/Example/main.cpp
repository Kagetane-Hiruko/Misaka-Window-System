#include <MisakaWindowSystem.h>
#include <iostream>
#include <chrono>

INT WINAPI Misaka::Main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT iShowCmd)
{
    Misaka::Window::Configuration conf(hInstance, iShowCmd);
    Misaka::Window* win = Misaka::Window::CreateWindowInstance(700, 400, L"Title", conf);
    Misaka::Keyboard* kbd = Misaka::Keyboard::CreateKeyboardInstance();
    Misaka::Mouse* mouse = Misaka::Mouse::CreateMouseInstance();

    std::chrono::milliseconds ms1, ms2;
    ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    while (win->IsAlive())
    {
        win->PollEvents();

        if (mouse->GetLeftButton() == Mouse::Action::Release && mouse->GetRightButton() == Mouse::Action::Release)
        {
            std::cout << "a" << std::endl;
        }

        if(mouse->GetScroll() == MISAKA_SCROLL_DOWN)
            std::cout << mouse->GetScroll() << std::endl;
    
        if (kbd->IsKeyDown(MISAKA_KEY_SPACE))
            std::cout << "0" << std::endl;

        if(win->IsResized())
            std::cout << win->GetWidth() << ":" << win->GetHeight() << std::endl;

        mouse->ResetState();
        kbd->ResetState();
    }
    
    delete win;
    delete kbd;
    delete mouse;
    return MISAKA_QUIT_OK;
}

MISAKA_RUN_APPLICATION;