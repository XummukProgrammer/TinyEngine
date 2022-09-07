#ifndef _GUI_INPUT_MAP_WIDGET_HEADER_
#define _GUI_INPUT_MAP_WIDGET_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Gui/GuiWidget.hpp>
#include <TinyEngine/Gui/GuiWidgetContainer.hpp>

#include <functional>
#include <string>

namespace TinyEngine
{
	class GuiInputMapWidget final : public GuiWidget, public GuiWidgetContainer
	{
	public:
		using ValueAdd = std::function<void(std::string_view id)>;

	public:
		GuiInputMapWidget() = default;
		~GuiInputMapWidget() = default;

	public:
		static GuiInputMapWidgetSharedPtr Create();

	public:
		void Load();

		void SetOnValueAddCallback(const ValueAdd& callback) { _onValueAddCallback = callback; }

	public:
		void Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr) override;

	private:
		void OnAddValue();

	private:
		ValueAdd _onValueAddCallback;
		bool _isValueAdd = false;
		GuiInputTextWidgetSharedPtr _inputKeyWidget;
	};
}

#endif // _GUI_INPUT_MAP_WIDGET_HEADER_
