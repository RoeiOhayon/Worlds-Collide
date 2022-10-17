#pragma once

#include "UIProps.h"

class UIComponent
{
public:
	UIComponent() {}
	UIComponent(UIProps&& props) : props(props) {}
	// virtual void render() = 0;
private:
	UIProps props;
};