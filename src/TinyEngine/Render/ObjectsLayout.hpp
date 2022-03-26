#ifndef _OBJECTS_LAYOUT_HEADER_
#define _OBJECTS_LAYOUT_HEADER_

#include <TinyEngine/Render/IObject.hpp>

#include <TinyEngine/Render/ILayout.hpp>

#include <memory>
#include <vector>

namespace TinyEngine
{
	// Слой состоящий из базовых объектов.
	class ObjectsLayout final : public ILayout
	{
	public:
		ObjectsLayout() = default;
		~ObjectsLayout() = default;

	public:
		// Окно обновляется.
		void OnWindowUpdated() override;
		// Окно рисуется.
		void OnWindowDrawed() override;

	public:
		// Добавить объект.
		void AddObject(IObject* object);
		// Удалить объект.
		void RemoveObject(const IObject* object);
		// Удалить все объекты.
		void RemoveObjects() override { _objects.clear(); }
		// Получить кол-во объектов.
		size_t GetObjectsCount() const override { return _objects.size(); }

	private:
		// Объекты.
		std::vector<IObject*> _objects;
	};
}

#endif // _OBJECTS_LAYOUT_HEADER_
