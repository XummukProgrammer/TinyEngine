
set(ENGINE_HEADERS
	src/TinyEngine/TinyEngine.hpp
	src/TinyEngine/Core/Application.hpp
	src/TinyEngine/Core/FileSystem.hpp
	src/TinyEngine/Core/Window.hpp
	src/TinyEngine/Core/Context.hpp
	src/TinyEngine/Core/Factory.hpp
	
	src/TinyEngine/Utils/XmlUtils.hpp
	src/TinyEngine/Utils/Singleton.hpp
	
	src/TinyEngine/Properties/PropertiesData.hpp
	src/TinyEngine/Properties/IProperty.hpp
	src/TinyEngine/Properties/Data/BoolProperty.hpp
	src/TinyEngine/Properties/Data/IntProperty.hpp
	src/TinyEngine/Properties/Data/FloatProperty.hpp
	src/TinyEngine/Properties/Data/StringProperty.hpp
	
	src/TinyEngine/Level/LevelManager.hpp
	src/TinyEngine/Level/Component.hpp
	src/TinyEngine/Level/Entity.hpp
	src/TinyEngine/Level/Scene.hpp
	
	src/TinyEngine/Render/IObject.hpp
	src/TinyEngine/Render/VisualObject.hpp
	src/TinyEngine/Render/ILayer.hpp
	src/TinyEngine/Render/ObjectsLayer.hpp
	src/TinyEngine/Render/Layers.hpp
	src/TinyEngine/Render/RenderManager.hpp
	
	src/TinyEngine/Common/Components/TransformComponent.hpp
	src/TinyEngine/Common/Components/RectComponent.hpp
	src/TinyEngine/Common/Components/Render/VisualObjectComponent.hpp
	src/TinyEngine/Common/Components/Render/ObjectsLayerComponent.hpp
	src/TinyEngine/Common/Components/Render/TextureComponent.hpp
)

set(ENGINE_SOURCES
	src/TinyEngine/TinyEngine.cpp
	src/TinyEngine/Core/Application.cpp
	src/TinyEngine/Core/FileSystem.cpp
	src/TinyEngine/Core/Window.cpp
	src/TinyEngine/Core/Context.cpp
	src/TinyEngine/Core/Factory.cpp
	
	src/TinyEngine/Utils/XmlUtils.cpp
	src/TinyEngine/Utils/Singleton.cpp
	
	src/TinyEngine/Properties/PropertiesData.cpp
	src/TinyEngine/Properties/IProperty.cpp
	src/TinyEngine/Properties/Data/BoolProperty.cpp
	src/TinyEngine/Properties/Data/IntProperty.cpp
	src/TinyEngine/Properties/Data/FloatProperty.cpp
	src/TinyEngine/Properties/Data/StringProperty.cpp
	
	src/TinyEngine/Level/LevelManager.cpp
	src/TinyEngine/Level/Component.cpp
	src/TinyEngine/Level/Entity.cpp
	src/TinyEngine/Level/Scene.cpp
	
	src/TinyEngine/Render/IObject.cpp
	src/TinyEngine/Render/VisualObject.cpp
	src/TinyEngine/Render/ILayer.cpp
	src/TinyEngine/Render/ObjectsLayer.cpp
	src/TinyEngine/Render/Layers.cpp
	src/TinyEngine/Render/RenderManager.cpp
	
	src/TinyEngine/Common/Components/TransformComponent.cpp
	src/TinyEngine/Common/Components/RectComponent.cpp
	src/TinyEngine/Common/Components/Render/VisualObjectComponent.cpp
	src/TinyEngine/Common/Components/Render/ObjectsLayerComponent.cpp
	src/TinyEngine/Common/Components/Render/TextureComponent.cpp
)
