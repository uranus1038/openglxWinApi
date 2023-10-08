#include "WindowGui.h"
using namespace system ;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WindowGui window;
    int hWnd = window.createWindow(
        L"NunthawanEngine Alpha 1.0",
        L"UMICLASS",
        CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
        hInstance,nCmdShow);
    if(hWnd == 1)
    {
        Debug::Log("Window Init failed !");
    }
    window.loopEvent();

    return 0;
}