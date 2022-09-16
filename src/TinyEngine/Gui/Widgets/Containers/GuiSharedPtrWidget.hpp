﻿#ifndef _GUI_SHARED_PTR_WIDGET_HEADER_
#define _GUI_SHARED_PTR_WIDGET_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Gui/GuiWidget.hpp>
#include <TinyEngine/Gui/GuiWidgetContainer.hpp>

#include <functional>
#include <string>

namespace TinyEngine
{
	class GuiSharedPtrWidget final : public GuiWidget, public GuiWidgetContainer
	{
	public:
		using OnInit = std::function<void(std::string_view)>;

	public:
		GuiSharedPtrWidget() = default;
		~GuiSharedPtrWidget() = default;

	public:
		static GuiSharedPtrWidgetSharedPtr Create(std::string_view name, bool isInited, const OnInit& callback);

	public:
		void Load();

		void SetName(std::string_view name) { _name = name; }
		const std::string& GetName() const { return _name; }

		void SetIsInited(bool isInited) { _isInited = isInited; }
		bool IsInited() const { return _isInited; }

		void SetOnInitCallback(const OnInit& callback) { _onInitCallback = callback; }

	public:
		void Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr) override;

	private:
		void OnInitHandler();

	private:
		std::string _name;
		bool _isInited = false;
		GuiInputTextWidgetSharedPtr _inputTextPtr;
		OnInit _onInitCallback;
		bool _isInit = false;
	};
}

#endif // _GUI_SHARED_PTR_WIDGET_HEADER_
