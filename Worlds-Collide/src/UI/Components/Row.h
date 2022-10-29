#pragma once
#include "../UIComponent.h"

class Row :
    public UIComponent
{
public:
    template<class ...Args>
    Row(Args&&... children) :
        UIComponent(UIProps({ .name = "Grid" }), std::forward<Args>(children)...) {}

    virtual void render() override;
public:
    const static int COLUMNS_NUM = 12;
    const static int ROWS_NUM = 12;
private:
    bool isFirstRow = true;
};

