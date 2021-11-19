#include "Window.h"
Window* window = nullptr;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT mas, WPARAM wp, LPARAM lp) 
{
    switch (mas)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            window->EndProcess();
            break;

        default:
            return DefWindowProc(hwnd, mas, wp, lp);
            break;
    }
    return 0;
}

bool Window::Create()
{
    WNDCLASS wc = {};

    wc.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpfnWndProc = WindowProc;
    wc.lpszClassName = L"name";

    RegisterClass(&wc);

    if (!window)
        window = this;

    CreateWindowEx(0, L"name", L"Text Editor", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, WIDTH, HEIGHT, NULL, NULL, NULL, NULL);

    IsRunning = true;

    return true;
}

bool Window::isRunning()
{
    return IsRunning;
}

bool Window::EndProcess()
{
    IsRunning = false;

    return IsRunning;
}

bool Window::show()
{
    MSG msg = {};

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return true;
}
