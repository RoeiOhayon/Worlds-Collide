#pragma once
#include "../UIComponent.h"

class Text :
    public UIComponent
{
public:
    Text(UIProps&& uiProps, const char* content) :
        UIComponent(std::move(uiProps)), content(std::move(content)) {}

    virtual void render() override;
private:
    const char* content;
};

