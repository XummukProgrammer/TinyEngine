#ifndef _GUI_TREE_CONTAINER_WIDGET_HEADER_
#define _GUI_TREE_CONTAINER_WIDGET_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Gui/GuiWidget.hpp>
#include <TinyEngine/Core/Gui/GuiWidgetContainer.hpp>

#include <string>

namespace TinyEngine
{
	class GuiTreeContainerWidget : public GuiWidget, public GuiWidgetContainer
	{
	public:
		GuiTreeContainerWidget() = default;
		virtual ~GuiTreeContainerWidget() = default;

	public:
		static GuiTreeContainerWidgetSharedPtr Create(std::string_view name);

	public:
		virtual void Load() {}

		void SetName(std::string_view name) { _name = name; }
		const std::string& GetName() const { return _name; }

	public:
		void Draw(float deltaTime) final;

	protected:
		virtual void OnPostDraw() {}

	private:
		std::string _name;
	};
}

#endif // _GUI_TREE_CONTAINER_WIDGET_HEADER_
