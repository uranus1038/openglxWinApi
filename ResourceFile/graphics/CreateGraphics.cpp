#include "../../CommonFile/include/glfw/glfw3.h"
#include "../../CommonFile/include/glad/glad.h"
#include <iostream>

int main()  
{
    glfwInit();
   
    GLFWwindow* window = glfwCreateWindow(800, 800, "เกม", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "failed";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window) ;
    glfwTerminate();
    return 0;
}
