#ifndef _OBJECTS_LAYER_COMPONENT_HEADER_
#define _OBJECTS_LAYER_COMPONENT_HEADER_

#include <TinyEngine/Level/Component.hpp>

#include <string>

namespace TinyEngine::Render
{
	class ObjectsLayer;
}

namespace TinyEngine::Common
{
	class ObjectsLayerComponent final : public Level::Component
	{
	public:
		using ObjectsLayerPtr = std::shared_ptr<Render::ObjectsLayer>;

	public:
		ObjectsLayerComponent();
		~ObjectsLayerComponent() = default;

	public:
		void OnInit() override;
		void OnDeinit() override;

	public:
		void SetKey(std::string_view key);
		const std::string& GetKey() const;

		ObjectsLayerPtr GetObjectsLayer() const;

	private:
		std::string _key;
		ObjectsLayerPtr _objectsLayer;
	};
}

#endif // _OBJECTS_LAYER_COMPONENT_HEADER_
