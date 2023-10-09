#include "../../HeaderFile/Engin/WindowGui.h"
#include "WindowEvent.cpp"
bool WindowGui::createWindow(const wchar_t WINDOW_TEXT[],const wchar_t WINDOW_CLASS[],int width , int height , int x , int y,HINSTANCE hInstance ,int mCmdShow ) noexcept
{
   
    WNDCLASS wc = {0};
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = reinterpret_cast<WNDPROC>(&WindowGui::WindowProc);
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = WINDOW_CLASS;

    if (!RegisterClass(&wc)) 
    {
         Console::Log("Window register failed !");
        return false ;
    }

    this->hWnd = CreateWindowEx(
        0,
        WINDOW_CLASS,
        WINDOW_TEXT,
        WS_OVERLAPPEDWINDOW,
        width,height, x,y,
        NULL,       // Parent window        
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );
    if(this->hWnd == NULL)
    {
        return false ;
    }
    ShowWindow(this->hWnd,SW_SHOWMAXIMIZED);
    return true ; 
}

void WindowGui::addMenu(HWND hWnd , HMENU hMenu)
{
    hMenu = CreateMenu();
    HMENU hMenuEdit = CreateMenu();
    AppendMenu(hMenu,MF_STRING,FILE_MENU,L"File");
    AppendMenu(hMenuEdit,MF_STRING,FILE_MENU,L"File");
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hMenuEdit,L"Edit");
     SetMenu(hWnd,hMenu);
}

void WindowGui::loopEvent() {
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void WindowGui::destroyWindow() {
    if (this->hWnd == NULL) {
        DestroyWindow(hWnd);
    }
}



