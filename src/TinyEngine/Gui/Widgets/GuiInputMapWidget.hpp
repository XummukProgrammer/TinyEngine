#ifndef _GUI_INPUT_MAP_WIDGET_HEADER_
#define _GUI_INPUT_MAP_WIDGET_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Gui/GuiWidget.hpp>
#include <TinyEngine/Gui/GuiWidgetContainer.hpp>

namespace TinyEngine
{
	class GuiInputMapWidget final : public GuiWidget, public GuiWidgetContainer
	{
	public:

	public:
		GuiInputMapWidget() = default;
		~GuiInputMapWidget() = default;

	public:
		static GuiInputMapWidgetSharedPtr Create();

	public:
		void Load();

	public:
		void Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr) override;

	private:
	};
}

#endif // _GUI_INPUT_MAP_WIDGET_HEADER_
