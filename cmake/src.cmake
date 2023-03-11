
set(ENGINE_HEADERS
	src/TinyEngine/TinyEngine.hpp
	
	src/TinyEngine/Core/Application/Application.hpp
	src/TinyEngine/Core/Application/Context.hpp
	
	src/TinyEngine/Core/VisualObject/Transform.hpp
	src/TinyEngine/Core/VisualObject/VisualObject.hpp
	src/TinyEngine/Core/Resources/FileSystem.hpp
	
	src/TinyEngine/Core/Serialization/IArchive.hpp
	src/TinyEngine/Core/Serialization/XmlArchive.hpp
	
	src/TinyEngine/Core/Reflection/ReflectionObject.hpp
	src/TinyEngine/Core/Reflection/ReflectionMember.hpp
)

set(ENGINE_SOURCES
	src/TinyEngine/TinyEngine.cpp
	
	src/TinyEngine/Core/Application/Application.cpp
	src/TinyEngine/Core/Application/Context.cpp
	
	src/TinyEngine/Core/VisualObject/Transform.cpp
	src/TinyEngine/Core/VisualObject/VisualObject.cpp
	
	src/TinyEngine/Core/Resources/FileSystem.cpp
	
	src/TinyEngine/Core/Serialization/IArchive.cpp
	src/TinyEngine/Core/Serialization/XmlArchive.cpp
	
	src/TinyEngine/Core/Reflection/ReflectionObject.cpp
	src/TinyEngine/Core/Reflection/ReflectionMember.cpp
)
