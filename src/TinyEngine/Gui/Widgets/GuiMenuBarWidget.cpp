#include "GuiMenuBarWidget.hpp"

namespace TinyEngine
{
	GuiMenuBarWidget::Ptr GuiMenuBarWidget::Create()
	{
		auto widget = std::make_shared<GuiMenuBarWidget>();
		return widget;
	}

	void GuiMenuBarWidget::Draw(float deltaTime, IRenderWindowPtr renderWindowPtr)
	{
		if (ImGui::BeginMenuBar())
		{
			for (const auto& menu : _menus)
			{
				if (ImGui::BeginMenu(menu.name.c_str()))
				{
					for (const auto& item : menu.items)
					{
						if (ImGui::MenuItem(item.name.c_str()))
						{
							if (item.action)
							{
								item.action();
							}
						}
					}

					ImGui::EndMenu();
				}
			}

			ImGui::EndMenuBar();
		}
	}

	void GuiMenuBarWidget::AddMenu(const Menu& menu)
	{
		_menus.push_back(menu);
	}
}
