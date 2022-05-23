
set(ENGINE_HEADERS
	src/TinyEngine/TinyEngine.hpp
	
	src/TinyEngine/Core/Core.hpp
	src/TinyEngine/Core/Application.hpp
	src/TinyEngine/Core/Paths.hpp
	
	src/TinyEngine/Graphics/Graphics.hpp
	src/TinyEngine/Graphics/IWindow.hpp
	src/TinyEngine/Graphics/IPoint.hpp
	
	src/TinyEngine/Graphics/SFML/SFMLGraphics.hpp
	src/TinyEngine/Graphics/SFML/SFMLWindow.hpp
	src/TinyEngine/Graphics/SFML/SFMLPoint.hpp
	
	src/TinyEngine/Events/Events.hpp
	src/TinyEngine/Events/Event.hpp
	src/TinyEngine/Events/Listener.hpp
	src/TinyEngine/Events/Sender.hpp
	
	src/TinyEngine/Debug/Debug.hpp
	src/TinyEngine/Debug/Log.hpp
	src/TinyEngine/Debug/Assert.hpp
	src/TinyEngine/Debug/DebugMessage.hpp
	src/TinyEngine/Debug/DebugAdapter.hpp
)

set(ENGINE_SOURCES
	src/TinyEngine/Core/Application.cpp
	src/TinyEngine/Core/Paths.cpp
	
	src/TinyEngine/Graphics/SFML/SFMLWindow.cpp
	
	src/TinyEngine/Debug/Log.cpp
	src/TinyEngine/Debug/Assert.cpp
	src/TinyEngine/Debug/DebugMessage.cpp
	src/TinyEngine/Debug/DebugAdapter.cpp
)
