#ifndef _GUI_INPUT_VECTOR_WIDGET_HEADER_
#define _GUI_INPUT_VECTOR_WIDGET_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Gui/Widgets/Containers/GuiTreeContainerWidget.hpp>

#include <string>
#include <functional>

namespace TinyEngine
{
	class GuiInputVectorWidget final : public GuiTreeContainerWidget
	{
	public:
		using ValueAdd = std::function<void()>;

	public:
		GuiInputVectorWidget() = default;
		~GuiInputVectorWidget() = default;

	public:
		static GuiInputVectorWidgetSharedPtr Create(std::string_view name);

	public:
		void SetOnValueAddCallback(const ValueAdd& callback) { _onValueAddCallback = callback; }

	public:
		void Load() override;

	private:
		void OnValueAdd();

		void OnPostDraw() override;

	private:
		bool _isValueAdd = false;
		ValueAdd _onValueAddCallback;
	};

}

#endif // _GUI_INPUT_VECTOR_WIDGET_HEADER_
