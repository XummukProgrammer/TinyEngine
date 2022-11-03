#ifndef _GUI_META_CLASS_WIDGET_HEADER_
#define _GUI_META_CLASS_WIDGET_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Gui/GuiWidget.hpp>
#include <TinyEngine/Core/Gui/GuiWidgetContainer.hpp>

namespace TinyEngine
{
	class GuiMetaClassWidget final : public GuiWidget, public GuiWidgetContainer
	{
	public:
		GuiMetaClassWidget() = default;
		~GuiMetaClassWidget() = default;

	public:
		static GuiMetaClassWidgetSharedPtr Create(std::string_view name);

	public:
		void SetName(std::string_view name) { _name = name; }
		const std::string& GetName() const { return _name; }

	public:
		void Draw(float deltaTime) override;

	private:
		std::string _name;
	};
}

#endif // _GUI_META_CLASS_WIDGET_HEADER_
