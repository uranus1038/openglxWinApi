#include "WindowGui.cpp" 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WindowGui window;
    bool isWindow = window.createWindow(
        L"NunthawanEngine Alpha 1.0",
        L"UMICLASS",
        CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
        hInstance,nCmdShow);
    if(!isWindow)
    {
        Console::Log("Window init failed !");
        return -1 ;
    }else
    {
        Console::Log("Create window successed");
    }
    window.loopEvent();
    window.destroyWindow();

    return 0;
}