#include <spdlog/spdlog.h>
#include <GLFW/glfw3.h>

#include "UI/UIComponent.h"

GLFWwindow* createWindow(uint16_t width, uint16_t height, const char* title)
{
    if (!glfwInit())
        throw std::exception("Failed to Init GLFW");

    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw std::exception("Failed to Init Window");
    }

    glfwMakeContextCurrent(window);

    return window;
}



int main()
{
    GLFWwindow* window;
    window = createWindow(640, 480, "Hayush");

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0, 0.5);
        glVertex2f(0.5, -0.5);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

int nomain()
{
	UIComponent app = UIComponent();
	spdlog::info("App is running");

    return 0;
}