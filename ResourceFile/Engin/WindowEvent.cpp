#include "../../HeaderFile/Engin/WindowGui.h"
#include "ThreadExecute.cpp"
using namespace ThreadExecute ;

LRESULT CALLBACK WindowGui::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // ทำงานกับ GUI ของคุณที่นี่
        EndPaint(hWnd, &ps);
        break;
    }
    case WM_COMMAND:
        switch (wParam)
        {
        case FILE_MENU:
            Console::Log("Click");
            thread::runtime(thread::processPreview);
            break;
        }
        break;
    case WM_CREATE:
        HMENU hMenu;
        addMenu(hWnd, hMenu);
        break;
    case WM_DESTROY:
        HWND hWnd = FindWindow(NULL,L"preview");
        if(hWnd != NULL)
        {
            SendMessage(hWnd, WM_CLOSE, 0, 0);
        }
        PostQuitMessage(0);
        break;
       
    }
   return DefWindowProc(hWnd, message, wParam, lParam);
}