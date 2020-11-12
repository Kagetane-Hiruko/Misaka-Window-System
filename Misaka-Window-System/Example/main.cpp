#include <MisakaWindowSystem.h>
#include <iostream>
#include <chrono>

INT WINAPI Misaka::Main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT iShowCmd)
{
    Misaka::Window::Configuration conf(hInstance, iShowCmd);
    Misaka::Window* win = Misaka::Window::CreateWindowInstance(700, 400, L"Misaka Window", conf);
    Misaka::Keyboard* kbd = Misaka::Keyboard::CreateKeyboardInstance();
    Misaka::Mouse* mouse = Misaka::Mouse::CreateMouseInstance();

    while (win->IsAlive())
    {
        win->PollEvents();

        if (kbd->IsKeyDown(MISAKA_KEY_ESCAPE))
        {
            win->Close();
        }

        if (win->IsResized())
        {
            std::cout << win->GetWidth() << ":" << win->GetHeight() << std::endl;
        }

        mouse->ResetState();
        kbd->ResetState();
    }
    
    delete win;
    delete kbd;
    delete mouse;
    return MISAKA_QUIT_OK;
}

MISAKA_RUN_APPLICATION;