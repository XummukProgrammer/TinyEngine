
set(ENGINE_HEADERS
	src/TinyEngine/TinyEngine.hpp
	
	src/TinyEngine/Core/Core.hpp
	src/TinyEngine/Core/Application.hpp
	src/TinyEngine/Core/Window.hpp
	src/TinyEngine/Core/Gui.hpp
	src/TinyEngine/Core/FpsCounter.hpp
	src/TinyEngine/Core/Timer.hpp
	
	src/TinyEngine/Events/Subscriber.hpp
	src/TinyEngine/Events/Publisher.hpp
	src/TinyEngine/Events/EventParameters.hpp
	
	src/TinyEngine/Data/CounterRef.hpp
	src/TinyEngine/Data/EventableValue.hpp
	
	src/TinyEngine/Gui/GuiController.hpp
	src/TinyEngine/Gui/GuiModel.hpp
	src/TinyEngine/Gui/GuiView.hpp
	src/TinyEngine/Gui/GuiControllers.hpp
	
	src/TinyEngine/Gui/Debug/GuiDebugController.hpp
	src/TinyEngine/Gui/Debug/GuiDebugModel.hpp
	src/TinyEngine/Gui/Debug/GuiDebugView.hpp
)

set(ENGINE_SOURCES
	src/TinyEngine/TinyEngine.cpp
	
	src/TinyEngine/Core/Core.cpp
	src/TinyEngine/Core/Application.cpp
	src/TinyEngine/Core/Window.cpp
	src/TinyEngine/Core/Gui.cpp
	src/TinyEngine/Core/FpsCounter.cpp
	src/TinyEngine/Core/Timer.cpp
	
	src/TinyEngine/Events/Subscriber.cpp
	src/TinyEngine/Events/Publisher.cpp
	src/TinyEngine/Events/EventParameters.cpp
	
	src/TinyEngine/Data/CounterRef.cpp
	src/TinyEngine/Data/EventableValue.cpp
	
	src/TinyEngine/Gui/GuiController.cpp
	src/TinyEngine/Gui/GuiModel.cpp
	src/TinyEngine/Gui/GuiView.cpp
	src/TinyEngine/Gui/GuiControllers.cpp
	
	src/TinyEngine/Gui/Debug/GuiDebugController.cpp
	src/TinyEngine/Gui/Debug/GuiDebugModel.cpp
	src/TinyEngine/Gui/Debug/GuiDebugView.cpp
)
