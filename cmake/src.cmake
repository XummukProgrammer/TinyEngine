
set(ENGINE_HEADERS
	src/TinyEngine/TinyEngine.hpp
	
	src/TinyEngine/Core/Core.hpp
	src/TinyEngine/Core/Application.hpp
	
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
)

set(ENGINE_SOURCES
	src/TinyEngine/Core/Application.cpp
	
	src/TinyEngine/Graphics/SFML/SFMLWindow.cpp
	src/TinyEngine/Graphics/SFML/SFMLPoint.cpp
)
