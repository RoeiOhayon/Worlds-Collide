#pragma once
#include "../UIComponent.h"

class App :
    public UIComponent
{
public:
    template<class ...Args>
    App(UIProps&& uiProps, Args&&... children) :
        UIComponent(std::move(uiProps), std::forward<Args>(children)...) {}

    virtual void render() override;
};

