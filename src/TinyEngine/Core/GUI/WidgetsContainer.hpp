#ifndef _WIDGETS_CONTAINER_HEADER_
#define _WIDGETS_CONTAINER_HEADER_

#include <TinyEngine/Core/GUI/Widget.hpp>

#include <vector>
#include <memory>
#include <string>

namespace TinyEngine
{
	class WidgetsContainer final
	{
	public:
		WidgetsContainer() = default;
		~WidgetsContainer() = default;

	public:
		void Draw();

	public:
		void AddWidget(std::unique_ptr<Widget>&& widget);
		bool HasWidget(std::string_view name) const;
		Widget* GetWidget(std::string_view name) const;

	private:
		std::vector<std::unique_ptr<Widget>> _widgets;
	};
}

#endif // _WIDGETS_CONTAINER_HEADER_
