#include "glfw/glfw3.h"
#include "glad/glad.h"
#include "EBO.cpp"
#include "VAO.cpp"
#include "VBO.cpp"
#include "shaderClass.cpp"
#include "stb.cpp"
#include <math.h>
int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLfloat vertices[] = {
        -1.0f, 1.0f, 0.0f,   1.0f, 1.0f,1.0f , 0.0f, 0.0f,  
        -1.0f, -1.0f, 0.0f,  1.0f, 1.0f,1.0f , 0.0f, 1.0f,   
        1.0f, -1.0f, 0.0f,   1.0f, 1.0f,1.0f , 1.0f, 1.0f, 
        1.0f, 1.0f, 0.0f , 1.0f, 1.0f,1.0f ,   1.0f, 0.0f, }; 
    GLuint indices[] =
        {
            0,2,1,
            0,3,2
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

    Shader shader_0("D:/UMI/Engin/NunthawanEnginX/ResourceFile/graphics/shaders/default.vert","D:/UMI/Engin/NunthawanEnginX/ResourceFile/graphics/shaders/default.frag");
    VAO vao_1 ;
    vao_1.Bind();
    VBO vbo_1(vertices,sizeof(vertices));
    vbo_1.Bind();
    EBO ebo_1(indices,sizeof(indices));
    vao_1.LinkAttrib(vbo_1 , 0 , 3 ,GL_FLOAT,8*sizeof(float),(void*)0);
    vao_1.LinkAttrib(vbo_1 , 1 , 3 ,GL_FLOAT,8*sizeof(float),(void*)(3*sizeof(float)));
    vao_1.LinkAttrib(vbo_1 , 2 , 2 ,GL_FLOAT,8*sizeof(float),(void*)(6*sizeof(float)));

    vao_1.Unbind();
    vbo_1.Unbind();
    ebo_1.Unbind();
    // Import value form defult.vert
    GLuint uniID = glGetUniformLocation(shader_0.ID, "scale");

    int widthImg , heigthImg , numColCh ;
    unsigned char* imgBytes = stbi_load("D:/Downloads/asd.png",&widthImg,&heigthImg,&numColCh,0);


    GLuint texture ; 
    glGenTextures(1,&texture);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,texture);
    glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D , 0, GL_RGBA , widthImg , heigthImg , 0 ,GL_RGBA,GL_UNSIGNED_BYTE,imgBytes );
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(imgBytes);
    glBindTexture(GL_TEXTURE_2D,0);
    
     GLuint texuniID = glGetUniformLocation(shader_0.ID, "tex0");
     shader_0.Activate();
     glUniform1i(texuniID,0);

    glClearColor(0.0f, 0.13f, 0.17f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader_0.Activate();
        glUniform1f(uniID, 0.8f);
         glBindTexture(GL_TEXTURE_2D,texture);
        vao_1.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    vao_1.Delete();
    vbo_1.Delete();
    ebo_1.Delete();
    shader_0.Delete();
    glDeleteTextures(1,&texture);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
