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

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        {
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(-0.5f, -0.5f);
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex2f( 0.0f,  0.5f);
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex2f( 0.5f, -0.5f);
        }
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return EXIT_OK;
}