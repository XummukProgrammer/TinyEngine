#ifndef _RENDER_HEADER_
#define _RENDER_HEADER_

#include <TinyEngine/Render/ILayout.hpp>

#include <vector>
#include <memory>

namespace TinyEngine
{
	// Класс для отрисовки.
	class Render final
	{
	public:
		Render() = default;
		~Render() = default;

	public:
		// Приложение запускается.
		void OnAppEntry();
		// Приложение закрывается.
		void OnAppQuit();

		// Окно обновляется.
		void OnWindowUpdated();
		// Окно рисуется.
		void OnWindowDrawed();

	public:
		// Добавить слой.
		void AddLayout(ILayout* layout);
		// Удалить слой.
		void RemoveLayout(const ILayout* layout);
		// Получить кол-во слоёв.
		size_t GetLayoutsCount() const { return _layouts.size(); }

		// Получить общее кол-во объектов.
		size_t GetObjectsCount() const;

	private:
		// Слои.
		std::vector<ILayout*> _layouts;
	};
}

#endif // _RENDER_HEADER_
