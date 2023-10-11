#include "UMISystem.h"
using namespace UMISystem;
void UMISystem::Debug::Log(std::string msg)
{
    std::string message = "echo " + msg + ">> output.txt";
    system(message.c_str());
}
void UMISystem::Console::Log(std::string msg)
{
    std::cout << "UMI::" << msg << std::endl;
}
