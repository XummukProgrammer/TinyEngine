#ifndef _VISUAL_OBJECT_COMPONENT_HEADER_
#define _VISUAL_OBJECT_COMPONENT_HEADER_

#include <TinyEngine/Level/Component.hpp>

namespace TinyEngine::Render
{
	class ObjectsLayer;
	class VisualObject;
}

namespace TinyEngine::Common
{
	class TransformComponent;
	class RectComponent;
	class TextureComponent;

	class VisualObjectComponent final : public Level::Component
	{
	public:
		using ObjectsLayerPtr = std::shared_ptr<Render::ObjectsLayer>;
		using VisualObjectPtr = std::shared_ptr<Render::VisualObject>;
		using WeakTransformComponent = std::weak_ptr<TransformComponent>;
		using WeakRectComponent = std::weak_ptr<RectComponent>;
		using WeakTextureComponent = std::weak_ptr<TextureComponent>;

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
		WeakRectComponent _weakRectComponent;
		WeakTextureComponent _weakTextureComponent;
	};
}

#endif // _VISUAL_OBJECT_COMPONENT_HEADER_
