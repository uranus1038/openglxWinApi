#pragma once
#include <windows.h>
#include <System.h>
class WindowGui {
public:
    int createWindow(const wchar_t windowName[],const wchar_t windowClassName[],int width , int height , int x , int y,HINSTANCE hInstance ,int mCmdShowm  ) noexcept;
    void destroyWindow(HWND hWnd);
    void loopEvent();
private:
    HWND hWnd ; 
    static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
   
};


