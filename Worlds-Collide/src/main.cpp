#include <spdlog/spdlog.h>
#include <GLFW/glfw3.h>

#include "UI/UIComponent.h"

int main()
{
	UIComponent app = UIComponent();
	spdlog::info("App is running");
	glfwInit();

    return 0;
}