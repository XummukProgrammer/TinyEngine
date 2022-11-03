#ifndef _GUI_INPUT_MAP_WIDGET_HEADER_
#define _GUI_INPUT_MAP_WIDGET_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Gui/Widgets/Containers/GuiTreeContainerWidget.hpp>

#include <functional>
#include <string>

namespace TinyEngine
{
	class GuiInputMapWidget final : public GuiTreeContainerWidget
	{
	public:
		using ValueAdd = std::function<void(std::string_view id)>;

	public:
		GuiInputMapWidget() = default;
		~GuiInputMapWidget() = default;

	public:
		static GuiInputMapWidgetSharedPtr Create(std::string_view name);

	public:
		void Load() override;

		void SetOnValueAddCallback(const ValueAdd& callback) { _onValueAddCallback = callback; }

	private:
		void OnAddValue();

		void OnPostDraw() override;

	private:
		ValueAdd _onValueAddCallback;
		bool _isValueAdd = false;
		GuiInputTextWidgetSharedPtr _inputKeyWidget;
	};
}

#endif // _GUI_INPUT_MAP_WIDGET_HEADER_
