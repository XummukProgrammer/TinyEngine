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
		void Draw();

	public:
		void AddWidget(std::unique_ptr<Widget>&& widget);
		bool HasWidget(std::string_view name) const;
		Widget* GetWidget(std::string_view name) const;

	private:
		std::vector<std::unique_ptr<Widget>> _widgets;
	};
}

#endif // _GUI_HEADER_
