# Misaka Window System
Static C++ library for creating window that will be used in combination with DirectX or OpenGL projects. Also provides interface for keyboard and mouse events.

<p align="center">
    <br>
    <img src="img.PNG" width="500" >
</p>

## Structure
<hr>
Misaka window system consists for three main classes:

* Window
* Keyboard
* Mouse

## Window class
<hr>
Protected Fields:

```.cpp
HWND mhWnd;                     // Window handle.
MSG mMsg;                       // Message information.

int miWidth;                    // Window width.
int miHeight;                   // Window height.
bool mbResized;                 // Window resized.
static inline Window* mWindow;  // Single window instance.
```

Public Methods:

```.cpp
// Creates and returns window instance.
static Window* CreateWindowInstance(INT iWidth, INT iHeight, LPCWSTR lpTitle, Configuration config); 
static Window* GetInstance();   // Returns windows signle instance.

bool IsAlive();                 // Check if window is not destroyed.
void PollEvents();              // Poll events.
bool IsResized();               // Getter for window resize.
int GetWidth();                 // Getter for window width.
int GetHeight();                // Getter for window height.
HWND GetHandle();               // Getter for window handle.
void Close();                   // Destroy window.

virtual ~Window();              // Destructor.
```

Protected Methods:

```.cpp
explicit Window() = delete;
// Window constructor.
explicit Window(INT iWidth, INT iHeight, LPCWSTR lpTitle, Configuration config);    

// Handling window messages.
static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);  
```

Inline class for handling window configuration:
```.cpp
struct Configuration : public WNDCLASSEX
{
    INT iShowCmd;   // Display cmd.
    explicit Configuration(HINSTANCE hInstance, INT iShowCmd);
};
```