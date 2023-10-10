#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>
namespace UMISystem
{
    class Debug{
        public :
       
        static void Log(std::string msg);
        
    } ;
    class Console{
        public :
         static void Log(std::string msg);
    };
} // namespace system
