
set(ENGINE_HEADERS
	src/TinyEngine/TinyEngine.hpp
	
	src/TinyEngine/Core/Core.hpp
	src/TinyEngine/Core/Application.hpp
	src/TinyEngine/Core/Window.hpp
	
	src/TinyEngine/Events/Subscriber.hpp
	src/TinyEngine/Events/Publisher.hpp
	src/TinyEngine/Events/EventParameters.hpp
	
	src/TinyEngine/Data/CounterRef.hpp
	src/TinyEngine/Data/EventableValue.hpp
)

set(ENGINE_SOURCES
	src/TinyEngine/TinyEngine.cpp
	
	src/TinyEngine/Core/Core.cpp
	src/TinyEngine/Core/Application.cpp
	src/TinyEngine/Core/Window.cpp
	
	src/TinyEngine/Events/Subscriber.cpp
	src/TinyEngine/Events/Publisher.cpp
	src/TinyEngine/Events/EventParameters.cpp
	
	src/TinyEngine/Data/CounterRef.cpp
	src/TinyEngine/Data/EventableValue.cpp
)
