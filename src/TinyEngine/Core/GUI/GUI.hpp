#ifndef _GUI_HEADER_
#define _GUI_HEADER_

#include <TinyEngine/Core/GUI/Widget.hpp>

#include <vector>
#include <memory>
#include <string>

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
		void Draw();

	public:
		void AddWidget(std::unique_ptr<Widget>&& widget);
		bool HasWidget(std::string_view name) const;
		Widget* GetWidget(std::string_view name) const;

	private:
		template<typename T, typename = std::enable_if<std::is_base_of_v<T, Widget>>>
		static std::unique_ptr<T> MakeWidget(std::string_view name)
		{
			auto newWidget = std::make_unique<T>();
			newWidget->SetName(name);
			return std::move(newWidget);
		}

	private:
		std::vector<std::unique_ptr<Widget>> _widgets;
	};
}

#endif // _GUI_HEADER_
