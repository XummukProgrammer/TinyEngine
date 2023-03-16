
set(ENGINE_HEADERS
	src/TinyEngine/TinyEngine.hpp
	
	src/TinyEngine/Core/Application/Application.hpp
	src/TinyEngine/Core/Application/Context.hpp
	src/TinyEngine/Core/Application/Project.hpp
	
	src/TinyEngine/Core/VisualObject/Transform.hpp
	src/TinyEngine/Core/VisualObject/VisualObject.hpp
	src/TinyEngine/Core/Resources/FileSystem.hpp
	
	src/TinyEngine/Core/Serialization/IArchive.hpp
	src/TinyEngine/Core/Serialization/XmlArchive.hpp
	
	src/TinyEngine/Core/Reflection/ReflectionObject.hpp
	src/TinyEngine/Core/Reflection/IReflectionMember.hpp
	src/TinyEngine/Core/Reflection/ReflectionMember.hpp
	src/TinyEngine/Core/Reflection/TypeFactory.hpp
	
	src/TinyEngine/Core/GUI/GUI.hpp
	src/TinyEngine/Core/GUI/Widget.hpp
	src/TinyEngine/Core/GUI/WidgetView.hpp
	src/TinyEngine/Core/GUI/WidgetsContainer.hpp
	src/TinyEngine/Core/GUI/Widgets/TextBox/TextBox.hpp
	src/TinyEngine/Core/GUI/Widgets/TextBox/ITextBoxView.hpp
	src/TinyEngine/Core/GUI/Widgets/TextBox/TextBoxImGUIView.hpp
	src/TinyEngine/Core/GUI/Widgets/Window/Window.hpp
	src/TinyEngine/Core/GUI/Widgets/Window/IWindowView.hpp
	src/TinyEngine/Core/GUI/Widgets/Window/WindowImGUIView.hpp
	src/TinyEngine/Core/GUI/Widgets/SameLine/SameLine.hpp
	src/TinyEngine/Core/GUI/Widgets/SameLine/ISameLineView.hpp
	src/TinyEngine/Core/GUI/Widgets/SameLine/SameLineImGUIView.hpp
	src/TinyEngine/Core/GUI/Widgets/Button/Button.hpp
	src/TinyEngine/Core/GUI/Widgets/Button/IButtonView.hpp
	src/TinyEngine/Core/GUI/Widgets/Button/ButtonImGUIView.hpp
	
	src/TinyEngine/Core/Events/Signal.hpp
	src/TinyEngine/Core/Events/Slot.hpp
)

set(ENGINE_SOURCES
	src/TinyEngine/TinyEngine.cpp
	
	src/TinyEngine/Core/Application/Application.cpp
	src/TinyEngine/Core/Application/Context.cpp
	src/TinyEngine/Core/Application/Project.cpp
	
	src/TinyEngine/Core/VisualObject/Transform.cpp
	src/TinyEngine/Core/VisualObject/VisualObject.cpp
	
	src/TinyEngine/Core/Resources/FileSystem.cpp
	
	src/TinyEngine/Core/Serialization/IArchive.cpp
	src/TinyEngine/Core/Serialization/XmlArchive.cpp
	
	src/TinyEngine/Core/Reflection/ReflectionObject.cpp
	src/TinyEngine/Core/Reflection/IReflectionMember.cpp
	src/TinyEngine/Core/Reflection/ReflectionMember.cpp
	src/TinyEngine/Core/Reflection/TypeFactory.cpp
	
	src/TinyEngine/Core/GUI/GUI.cpp
	src/TinyEngine/Core/GUI/Widget.cpp
	src/TinyEngine/Core/GUI/WidgetView.cpp
	src/TinyEngine/Core/GUI/WidgetsContainer.cpp
	src/TinyEngine/Core/GUI/Widgets/TextBox/TextBox.cpp
	src/TinyEngine/Core/GUI/Widgets/TextBox/ITextBoxView.cpp
	src/TinyEngine/Core/GUI/Widgets/TextBox/TextBoxImGUIView.cpp
	src/TinyEngine/Core/GUI/Widgets/Window/Window.cpp
	src/TinyEngine/Core/GUI/Widgets/Window/IWindowView.cpp
	src/TinyEngine/Core/GUI/Widgets/Window/WindowImGUIView.cpp
	src/TinyEngine/Core/GUI/Widgets/SameLine/SameLine.cpp
	src/TinyEngine/Core/GUI/Widgets/SameLine/ISameLineView.cpp
	src/TinyEngine/Core/GUI/Widgets/SameLine/SameLineImGUIView.cpp
	src/TinyEngine/Core/GUI/Widgets/Button/Button.cpp
	src/TinyEngine/Core/GUI/Widgets/Button/IButtonView.cpp
	src/TinyEngine/Core/GUI/Widgets/Button/ButtonImGUIView.cpp
	
	src/TinyEngine/Core/Events/Signal.cpp
	src/TinyEngine/Core/Events/Slot.cpp
)
