#ifndef _VISUAL_OBJECT_COMPONENT_HEADER_
#define _VISUAL_OBJECT_COMPONENT_HEADER_

#include <TinyEngine/Level/Component.hpp>

namespace TinyEngine::Level
{
	class TransformComponent;
}

namespace TinyEngine::Render
{
	class ObjectsLayer;
	class VisualObject;

	class VisualObjectComponent final : public Level::Component
	{
	public:
		using ObjectsLayerPtr = std::shared_ptr<ObjectsLayer>;
		using VisualObjectPtr = std::shared_ptr<VisualObject>;
		using WeakTransformComponent = std::weak_ptr<Level::TransformComponent>;

	public:
		VisualObjectComponent();
		~VisualObjectComponent() = default;

	public:
		void OnInit() override;
		void OnDeinit() override;

		void OnUpdate() override;

	public:
		void SetObjectsLayer(const ObjectsLayerPtr& objectsLayer);

		VisualObjectPtr GetVisualObject() const;

	private:
		ObjectsLayerPtr _objectsLayer;
		VisualObjectPtr _visualObject;
		WeakTransformComponent _weakTransformComponent;
	};
}

#endif // _VISUAL_OBJECT_COMPONENT_HEADER_
