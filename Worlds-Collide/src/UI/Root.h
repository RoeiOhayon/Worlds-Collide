#pragma once
#include "UIComponent.h"

class Root
{
public:
	Root(UIComponent& container);
	Root(UIComponent&& container);

	void render();
private:
	void initalizeWindow();
private:
	UIComponent& container;
	GLFWwindow* window = nullptr;
};

