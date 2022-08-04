#ifndef _GUI_WIDGET_CONTAINER_HEADER_
#define _GUI_WIDGET_CONTAINER_HEADER_

#include <TinyEngine/Core/Forwards.hpp>

#include <unordered_map>
#include <string>
#include <memory>
#include <functional>

namespace TinyEngine
{
	class GuiWidgetContainer
	{
	public:
		using EachWidgetsCallback = std::function<void(std::string_view id, GuiWidgetSharedPtr)>;

	public:
		GuiWidgetContainer() = default;
		virtual ~GuiWidgetContainer() = default;

	public:
		void Draw(float deltaTime, IRenderWindowSharedPtr renderWindowPtr);

	public:
		void AddWidget(std::string_view id, GuiWidgetSharedPtr widget);
		template<typename T> std::shared_ptr<T> GetWidget(std::string_view id) const;
		bool HasWidget(std::string_view id) const;

		void EachWidgets(EachWidgetsCallback callback);

	private:
		std::unordered_map<std::string, GuiWidgetSharedPtr> _widgets;
	};

	template<typename T>
	std::shared_ptr<T> GuiWidgetContainer::GetWidget(std::string_view id) const
	{
		auto it = _widgets.find(std::string{id});
		if (it != _widgets.end())
		{
			return std::dynamic_pointer_cast<T>(it->second);
		}
		return nullptr;
	}
}

#endif // _GUI_WIDGET_CONTAINER_HEADER_
