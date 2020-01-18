#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

enum EXIT_CODES
{
    EXIT_OK = 0
    , FAIL_GLFW_INIT
    , FAIL_GLFW_CREATE_WINDOW
    , FAIL_GLEW_INIT
};

int main(void)
{
    GLFWwindow* window;

    /* Initialize GLFW */
    if (!glfwInit())
        return FAIL_GLFW_INIT;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return FAIL_GLFW_CREATE_WINDOW;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Initialize GLEW */
    if (glewInit() != GLEW_OK)
        return FAIL_GLEW_INIT;

    /* Print the welcome message */
    std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

    /* Generate a new vertex buffer */
    GLuint buffer;
    glGenBuffers(1, &buffer);

    /* Put vertices into the vertex buffer */
    float vertices[] = { -0.5f, -0.5f, +0.0f, +0.5f, +0.5f, -0.5f };
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    /* Specify the vertex attributes */
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), 0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return EXIT_OK;
}