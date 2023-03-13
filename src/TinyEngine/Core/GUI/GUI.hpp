#ifndef _GUI_HEADER_
#define _GUI_HEADER_

#include <TinyEngine/Core/GUI/WidgetsContainer.hpp>

namespace TinyEngine
{
	class GUI final
	{
	public:
		GUI() = default;
		~GUI() = default;

	public:
		template<typename T, typename = std::enable_if<std::is_base_of_v<T, Widget>>>
		static std::unique_ptr<T> MakeImGUIWidget(std::string_view name)
		{
			auto newWidget = MakeWidget<T>(name);
			newWidget->MakeView(Widget::ViewType::ImGUI);
			return std::move(newWidget);
		}

	public:
		void AddWidget(std::unique_ptr<Widget>&& widget);

	public:
		const WidgetsContainer& GetImGUIWidgetsContainer() const { return _imGUIWidgetsContainer; }
		WidgetsContainer& GetRefImGUIWidgetsContainer() { return _imGUIWidgetsContainer; }

	private:
		template<typename T, typename = std::enable_if<std::is_base_of_v<T, Widget>>>
		static std::unique_ptr<T> MakeWidget(std::string_view name)
		{
			auto newWidget = std::make_unique<T>();
			newWidget->SetName(name);
			return std::move(newWidget);
		}

	private:
		WidgetsContainer _imGUIWidgetsContainer;
	};
}

#endif // _GUI_HEADER_
