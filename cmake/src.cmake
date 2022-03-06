
set(ENGINE_HEADERS
	src/TinyEngine/TinyEngine.hpp
	src/TinyEngine/Core/Application.hpp
	src/TinyEngine/Core/FileSystem.hpp
	src/TinyEngine/Core/Window.hpp
	src/TinyEngine/Core/Context.hpp
	
	src/TinyEngine/Utils/XmlUtils.hpp
	
	src/TinyEngine/Properties/Properties.hpp
	src/TinyEngine/Properties/IProperty.hpp
	src/TinyEngine/Properties/PropertyData.hpp
	src/TinyEngine/Properties/Data/IntProperty.hpp
)

set(ENGINE_SOURCES
	src/TinyEngine/TinyEngine.cpp
	src/TinyEngine/Core/Application.cpp
	src/TinyEngine/Core/FileSystem.cpp
	src/TinyEngine/Core/Window.cpp
	src/TinyEngine/Core/Context.cpp
	
	src/TinyEngine/Utils/XmlUtils.cpp
	
	src/TinyEngine/Properties/Properties.cpp
	src/TinyEngine/Properties/IProperty.cpp
	src/TinyEngine/Properties/PropertyData.cpp
	src/TinyEngine/Properties/Data/IntProperty.cpp
)
