#include "App.h"

void App::render()
{
	for (auto& child : this->children)
		child->render();
}