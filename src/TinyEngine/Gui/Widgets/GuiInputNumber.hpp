﻿#ifndef _GUI_INPUT_NUMBER_WIDGET_HEADER_
#define _GUI_INPUT_NUMBER_WIDGET_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Gui/GuiWidget.hpp>

#include <string>
#include <functional>

namespace TinyEngine
{
	class GuiInputNumber final : public GuiWidget
	{
	public:
		using OnInputed = std::function<void(int)>;

	public:
		GuiInputNumber() = default;
		~GuiInputNumber() = default;

	public:
		static GuiInputNumberSharedPtr Create(std::string_view title, int value, const OnInputed& callback);

	public:
		void SetTitle(std::string_view title) { _title = title; }
		const std::string& GetTitle() const { return _title; }

		void SetValue(bool value) { _value = value; }
		int GetValue() const { return _value; }

		void SetOnInputedCallback(const OnInputed& callback) { _onInputedCallback = callback; }

	public:
		void Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr) override;

	private:
		std::string _title;
		OnInputed _onInputedCallback;
		int _value = 0;
	};
}

#endif // _GUI_INPUT_NUMBER_WIDGET_HEADER_
