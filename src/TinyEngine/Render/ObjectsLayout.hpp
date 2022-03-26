#ifndef _OBJECTS_LAYOUT_HEADER_
#define _OBJECTS_LAYOUT_HEADER_

#include <TinyEngine/Render/IObject.hpp>

#include <TinyEngine/Render/ILayout.hpp>

#include <memory>
#include <vector>

namespace TinyEngine
{
	class ObjectsLayout final : public ILayout
	{
	public:
		ObjectsLayout() = default;
		~ObjectsLayout() = default;

	public:
		void OnWindowUpdated() override;
		void OnWindowDrawed() override;

	public:
		void AddObject(IObject* object);
		void RemoveObject(const IObject* object);

	private:
		std::vector<IObject*> _objects;
	};
}

#endif // _OBJECTS_LAYOUT_HEADER_
