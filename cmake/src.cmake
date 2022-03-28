
set(ENGINE_HEADERS
	src/TinyEngine/TinyEngine.hpp
	
	src/TinyEngine/Core/Core.hpp
	src/TinyEngine/Core/Application.hpp
	src/TinyEngine/Core/Window.hpp
	src/TinyEngine/Core/Gui.hpp
	src/TinyEngine/Core/FpsCounter.hpp
	src/TinyEngine/Core/Timer.hpp
	src/TinyEngine/Core/PathBuilder.hpp
	
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
	
	src/TinyEngine/Assets/Assets.hpp
	src/TinyEngine/Assets/AllAssets.hpp
	src/TinyEngine/Assets/IAsset.hpp
	src/TinyEngine/Assets/AssetParameters.hpp
	src/TinyEngine/Assets/TextureAssets.hpp
	
	src/TinyEngine/Render/Render.hpp
	src/TinyEngine/Render/ILayout.hpp
	src/TinyEngine/Render/IObject.hpp
	src/TinyEngine/Render/ObjectsLayout.hpp
	src/TinyEngine/Render/VisualObject.hpp
	src/TinyEngine/Render/RadialLightObject.hpp
	
	src/TinyEngine/ActionsQueue/ActionsQueue.hpp
	src/TinyEngine/ActionsQueue/IAction.hpp
	src/TinyEngine/ActionsQueue/CustomAction.hpp
	src/TinyEngine/ActionsQueue/SequenceActions.hpp
	src/TinyEngine/ActionsQueue/ActionsQueueContainer.hpp
)

set(ENGINE_SOURCES
	src/TinyEngine/TinyEngine.cpp
	
	src/TinyEngine/Core/Core.cpp
	src/TinyEngine/Core/Application.cpp
	src/TinyEngine/Core/Window.cpp
	src/TinyEngine/Core/Gui.cpp
	src/TinyEngine/Core/FpsCounter.cpp
	src/TinyEngine/Core/Timer.cpp
	src/TinyEngine/Core/PathBuilder.cpp
	
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
	
	src/TinyEngine/Assets/Assets.cpp
	src/TinyEngine/Assets/AllAssets.cpp
	src/TinyEngine/Assets/IAsset.cpp
	src/TinyEngine/Assets/AssetParameters.cpp
	src/TinyEngine/Assets/TextureAssets.cpp
	
	src/TinyEngine/Render/Render.cpp
	src/TinyEngine/Render/ILayout.cpp
	src/TinyEngine/Render/IObject.cpp
	src/TinyEngine/Render/ObjectsLayout.cpp
	src/TinyEngine/Render/VisualObject.cpp
	src/TinyEngine/Render/RadialLightObject.cpp
	
	src/TinyEngine/ActionsQueue/ActionsQueue.cpp
	src/TinyEngine/ActionsQueue/IAction.cpp
	src/TinyEngine/ActionsQueue/CustomAction.cpp
	src/TinyEngine/ActionsQueue/SequenceActions.cpp
	src/TinyEngine/ActionsQueue/ActionsQueueContainer.cpp
)
