#pragma once
#ifndef UNICODE 
#define UNICODE
#endif 

#define FILE_MENU 0 

#include <windows.h>
#include "UMISystem.cpp"
using namespace UMISystem ;
class WindowGui {
public:
    bool createWindow(const wchar_t WINDOW_TEXT[],const wchar_t WINDOW_CLASS[],int width , int height , int x , int y,HINSTANCE hInstance ,int mCmdShowm  ) noexcept;
    void destroyWindow();
    void loopEvent();
private:
    HWND hWnd ; 
   
    static void addMenu(HWND hWnd,HMENU hMenu);
    static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};


