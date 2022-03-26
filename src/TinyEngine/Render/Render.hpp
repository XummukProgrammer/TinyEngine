#ifndef _RENDER_HEADER_
#define _RENDER_HEADER_

#include <TinyEngine/Render/ILayout.hpp>

#include <vector>
#include <memory>

namespace TinyEngine
{
	class Render final
	{
	public:
		Render() = default;
		~Render() = default;

	public:
		void OnAppEntry();
		void OnAppQuit();

		void OnWindowUpdated();
		void OnWindowDrawed();

	public:
		// Добавить слой.
		void AddLayout(ILayout* layout);
		// Удалить слой.
		void RemoveLayout(const ILayout* layout);
		// Получить кол-во слоёв.
		size_t GetLayoutsCount() const { return _layouts.size(); }

	private:
		std::vector<ILayout*> _layouts;
	};
}

#endif // _RENDER_HEADER_
