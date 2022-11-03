#ifndef _GUI_SHARED_PTR_WIDGET_HEADER_
#define _GUI_SHARED_PTR_WIDGET_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Gui/Widgets/Containers/GuiTreeContainerWidget.hpp>

#include <functional>
#include <string>
#include <vector>

namespace TinyEngine
{
	class GuiSharedPtrWidget final : public GuiTreeContainerWidget
	{
	public:
		using OnInit = std::function<void(std::string_view)>;

	public:
		GuiSharedPtrWidget() = default;
		~GuiSharedPtrWidget() = default;

	public:
		static GuiSharedPtrWidgetSharedPtr Create(std::string_view name, bool isInited, const OnInit& callback, const std::vector<std::string>& inheritorTypes);

	public:
		void Load() override;

		void SetIsInited(bool isInited) { _isInited = isInited; }
		bool IsInited() const { return _isInited; }

		void SetOnInitCallback(const OnInit& callback) { _onInitCallback = callback; }

		void SetInheritorTypes(const std::vector<std::string>& types) { _inheritorTypes = types; }

	private:
		void OnInitHandler();

		void OnPostDraw() override;

	private:
		bool _isInited = false;
		GuiStringListBoxWidgetSharedPtr _typesListWidget;
		GuiButtonWidgetSharedPtr _buttonWidget;
		OnInit _onInitCallback;
		bool _isInit = false;
		std::vector<std::string> _inheritorTypes;
	};
}

#endif // _GUI_SHARED_PTR_WIDGET_HEADER_
