#include "glfw/glfw3.h"
#include "glad/glad.h"
#include "EBO.cpp"
#include "VAO.cpp"
#include "VBO.cpp"
#include "shaderClass.cpp"
#include <math.h>
int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLfloat vertices[] = {
        0.0f, -0.2f, 0.0f,
        -0.5f, 1.0f, 0.0f,
        1.0f, 0.5f, 0.0f,
        0.5f, 1.0f, 0.0f};
    GLuint indices[] =
        {
            3, 0, 1,
        };
    GLFWwindow *window = glfwCreateWindow(800, 800, "preview", NULL, NULL);
    if (window == NULL)
    {
        Console::Log("Failed");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glViewport(200, 200, 400, 400);

    Shader shader_0("D:/UMI/Engin/NunthawanEnginX/ResourceFile/graphics/shader/default.vert","D:/UMI/Engin/NunthawanEnginX/ResourceFile/graphics/shader/default.frag");
    VAO vao_1 ;
    VBO vbo_1(vertices,sizeof(vertices));
    EBO ebo_1(indices,sizeof(indices));
    vao_1.LinkVBO(vbo_1 , 0);
    vao_1.Unbind();
    vbo_1.Unbind();
    ebo_1.Unbind();

    glClearColor(0.0f, 0.13f, 0.17f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader_0.Activate();
        vao_1.Bind();
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    vao_1.Delete();
    vbo_1.Delete();
    ebo_1.Delete();
    shader_0.Delete();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
