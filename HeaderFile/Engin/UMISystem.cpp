#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>
namespace UMISystem
{
    class Debug{
        public :
       
        static void Log(std::string msg)
        {
            std::string message = "echo "+ msg + ">> output.txt";
            system(message.c_str());
        }
    } ;
    class Console{
        public :
         static void Log(std::string msg){
            std::cout<< "UMI::" << msg << std::endl ;
        }
    };
} // namespace system
