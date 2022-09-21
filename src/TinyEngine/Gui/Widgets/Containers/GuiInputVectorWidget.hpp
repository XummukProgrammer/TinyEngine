#ifndef _GUI_INPUT_VECTOR_WIDGET_HEADER_
#define _GUI_INPUT_VECTOR_WIDGET_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Gui/GuiWidget.hpp>
#include <TinyEngine/Gui/GuiWidgetContainer.hpp>

#include <string>
#include <functional>

namespace TinyEngine
{
	class GuiInputVectorWidget final : public GuiWidget, public GuiWidgetContainer
	{
	public:
		using ValueAdd = std::function<void()>;

	public:
		GuiInputVectorWidget() = default;
		~GuiInputVectorWidget() = default;

	public:
		static GuiInputVectorWidgetSharedPtr Create(std::string_view name);

	public:
		void SetName(std::string_view name) { _name = name; }
		const std::string& GetName() const { return _name; }

		void SetOnValueAddCallback(const ValueAdd& callback) { _onValueAddCallback = callback; }

	public:
		void Load();

	public:
		void Draw(float deltaTime) override;

	private:
		void OnValueAdd();

	private:
		std::string _name;
		bool _isValueAdd = false;
		ValueAdd _onValueAddCallback;
	};

}

#endif // _GUI_INPUT_VECTOR_WIDGET_HEADER_
