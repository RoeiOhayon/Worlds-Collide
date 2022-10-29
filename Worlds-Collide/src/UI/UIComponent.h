#pragma once

#include <utility>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <exception>
#include <vector>
#include <memory>

#include "UIProps.h"

class UIComponent
{
public:
	UIComponent(UIProps&& uiProps) : uiProps(uiProps) {}
	template<class... Args>
	UIComponent(UIProps&& uiProps, Args&&... children) :
		uiProps(uiProps), children({ children... }) {}

	virtual void render() = 0;
public:
	UIProps uiProps = UIProps({});
protected:
	std::vector<std::shared_ptr<UIComponent>> children;
	friend class Root;
};