#ifndef _GUI_INPUT_VECTOR_WIDGET_HEADER_
#define _GUI_INPUT_VECTOR_WIDGET_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Gui/GuiWidget.hpp>
#include <TinyEngine/Gui/GuiWidgetContainer.hpp>

#include <string>

namespace TinyEngine
{
	class GuiInputVectorWidget final : public GuiWidget, public GuiWidgetContainer
	{
	public:

	public:
		GuiInputVectorWidget() = default;
		~GuiInputVectorWidget() = default;

	public:
		static GuiInputVectorWidgetSharedPtr Create(std::string_view name);

	public:
		void SetName(std::string_view name) { _name = name; }
		const std::string& GetName() const { return _name; }

	public:
		void Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr) override;

	private:
		std::string _name;
	};

}

#endif // _GUI_INPUT_VECTOR_WIDGET_HEADER_
