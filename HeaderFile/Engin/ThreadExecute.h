#pragma once 
#include <iostream>
#include <fstream>
#include <thread>
#include <functional>


namespace ThreadExecute
{
    class thread{
        public :
        static void runtime(std::function<void()> func);
        static void callBackFunc() ;
        static void processPreview() ;
        private :

    };
} // namespace ThreadExecute
