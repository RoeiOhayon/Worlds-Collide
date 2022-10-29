#pragma once
#include "../UIComponent.h"
#include <string>

template<class T>
class Menu :
    public UIComponent
{
public:
    Menu(UIProps&& uiProps, std::vector<T>& menuItems, T& activeMenuItem) :
        UIComponent(std::move(uiProps)), menuItems(menuItems), activeMenuItem(activeMenuItem) {}

    virtual void render() override
    {
		ImGui::BeginChild("Menu");
		float width = ImGui::GetWindowWidth() / this->uiProps.colWidth;
		ImGui::SetWindowFontScale(2);

		for (auto& menuItem : this->menuItems)
		{
			if (menuItem == this->activeMenuItem)
			{
				ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.5, 0.5, 1, 1));
				ImGui::Button(menuItem, ImVec2(width, 40));
				ImGui::PopStyleColor(1);
			}
			else
			{
				ImGui::Button(menuItem, ImVec2(width, 40));
			}
			
			if (ImGui::IsItemHovered())
				ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
			if (ImGui::IsItemFocused())
			{
				this->activeMenuItem = menuItem;
			}
		}

		ImGui::EndChild();
    }
private:
    std::vector<T> menuItems;
    T& activeMenuItem;
};

