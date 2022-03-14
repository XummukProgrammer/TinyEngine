#ifndef _OBJECTS_LAYER_HEADER_
#define _OBJECTS_LAYER_HEADER_

#include <memory>
#include <vector>

#include <TinyEngine/Render/ILayer.hpp>

namespace TinyEngine::Render
{
	class IObject;

	class ObjectsLayer final : public ILayer
	{
	public:
		using ObjectPtr = std::shared_ptr<IObject>;

	public:
		ObjectsLayer() = default;
		~ObjectsLayer() = default;

	public:
		void OnDraw() override;

	public:
		void AddObject(const ObjectPtr& object);
		void RemoveObject(const ObjectPtr& object);

	private:
		void TryRemoveObjects();

	private:
		std::vector<ObjectPtr> _objects;
	};
}

#endif // _OBJECTS_LAYER_HEADER_
