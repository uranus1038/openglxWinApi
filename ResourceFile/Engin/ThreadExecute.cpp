#include "../../HeaderFile/Engin/ThreadExecute.h"

void ThreadExecute::thread::processPreview()
{
    if (system("g++ -I ../../CommonFile/include -L ../../CommonFile/lib -o ../graphics/preview.exe ../graphics/CreateGraphics.cpp ../graphics/glad.c -lglfw3dll  -lglfw3 -lopengl32 -lgdi32  >output.txt ") == 0)
    {
        Debug::Log("successed");
        system("D:/UMI/Engin/NunthawanEnginX/ResourceFile/graphics/preview.exe &");
        Debug::Log("successed2");
    }
    else
    {
        Console::Log("failed compiler");
    }
}
void ThreadExecute::thread::runtime(std::function<void()> func)
{
    std::thread myThread(func);
    myThread.detach();
}

