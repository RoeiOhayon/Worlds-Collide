#include "Row.h"
#include <spdlog/spdlog.h>

void Row::render()
{
	ImGui::BeginChild("Row");
	if (this->children.size() <= 1)
		ImGui::Columns(2);
	else
		ImGui::Columns(this->children.size());

	ImGui::Separator();

	for (auto& child : this->children)
	{
		ImGui::SetColumnWidth(child->uiProps.col, ImGui::GetWindowWidth() * child->uiProps.colWidth);
		child->render();
		ImGui::NextColumn();
	}

	ImGui::EndChild();
}