#include "../../HeaderFile/Engin/WindowGui.h"
int WindowGui::createWindow(const wchar_t windowName[],const wchar_t windowClassName[],int width , int height , int x , int y,HINSTANCE hInstance ,int mCmdShowm ) noexcept
{
    
    WNDCLASS wc = {0};
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = windowClassName;

    if (!RegisterClass(&wc)) 
    {
        system::Debug::Log("Window registerClass failed !");
        return 1 ;
    }

    this->hWnd = CreateWindowEx(
        0,
       windowClassName,
       windowName,
        WS_OVERLAPPEDWINDOW,
        width,height, x,y,
        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );
    if(this->hWnd == NULL)
    {
        return 1 ;
    }
    return 0 ; 
}

void WindowGui::loopEvent() {
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void WindowGui::destroyWindow(HWND hWnd) {
    if (hWnd == NULL) {
        DestroyWindow(hWnd);
    }
}

LRESULT CALLBACK WindowGui::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // ทำงานกับ GUI ของคุณที่นี่
            EndPaint(hWnd, &ps);
            break;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
