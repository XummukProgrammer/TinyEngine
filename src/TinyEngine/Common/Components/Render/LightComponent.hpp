#ifndef _LIGHT_COMPONENT_HEADER_
#define _LIGHT_COMPONENT_HEADER_

#include <TinyEngine/Level/Component.hpp>

namespace TinyEngine::Render
{
	class ObjectsLayer;
	class LightObject;
}

namespace TinyEngine::Common
{
	class TransformComponent;

	class LightComponent final : public Level::Component
	{
	public:
		using ObjectsLayerPtr = std::shared_ptr<Render::ObjectsLayer>;
		using LightObjectPtr = std::shared_ptr<Render::LightObject>;
		using WeakTransformComponent = std::weak_ptr<TransformComponent>;

	public:
		LightComponent();
		~LightComponent() = default;

	public:
		void OnInit() override;
		void OnDeinit() override;

		void OnUpdate() override;

	public:
		void SetObjectsLayer(const ObjectsLayerPtr& objectsLayer);

		LightObjectPtr GetLightObject() const;

	private:
		ObjectsLayerPtr _objectsLayer;
		LightObjectPtr _lightObject;
		WeakTransformComponent _weakTransformComponent;
	};
}

#endif // _LIGHT_COMPONENT_HEADER_
