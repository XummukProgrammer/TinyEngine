
set(ENGINE_HEADERS
	src/TinyEngine/TinyEngine.hpp
	src/TinyEngine/Core/Application.hpp
	src/TinyEngine/Core/Logger.hpp
	src/TinyEngine/Core/Debug.hpp
	src/TinyEngine/Core/FileSystem.hpp
	src/TinyEngine/Core/Constants.hpp
	src/TinyEngine/Core/Forwards.hpp
	src/TinyEngine/Render/Render.hpp
	src/TinyEngine/Render/IRenderObject.hpp
	src/TinyEngine/Render/IRenderWindow.hpp
	src/TinyEngine/Render/Point.hpp
	src/TinyEngine/Render/Rect.hpp
	src/TinyEngine/Render/RenderLayer.hpp
	src/TinyEngine/Render/RenderLayers.hpp
	src/TinyEngine/Render/RenderWindowSettings.hpp
	src/TinyEngine/Render/Texture.hpp
	src/TinyEngine/Render/Sfml/SfmlRender.hpp
	src/TinyEngine/Render/Sfml/SfmlRenderObject.hpp
	src/TinyEngine/Render/Sfml/SfmlRenderUtils.hpp
	src/TinyEngine/Render/Sfml/SfmlRenderWindow.hpp
	src/TinyEngine/Gui/Gui.hpp
	src/TinyEngine/Gui/GuiVisitor.hpp
	src/TinyEngine/Gui/SfmlGuiDelegate.hpp
	src/TinyEngine/Gui/GuiWidget.hpp
	src/TinyEngine/Gui/GuiWidgetContainer.hpp
	src/TinyEngine/Gui/Widgets/GuiLabelWidget.hpp
	src/TinyEngine/Gui/Widgets/GuiWindowWidget.hpp
	src/TinyEngine/Gui/Widgets/GuiMenuBarWidget.hpp
	src/TinyEngine/Gui/Widgets/GuiProjectWidget.hpp
	src/TinyEngine/Gui/Widgets/GuiButtonWidget.hpp
	src/TinyEngine/Gui/Widgets/GuiInputTextWidget.hpp
	src/TinyEngine/Gui/Widgets/GuiCheckboxWidget.hpp
	src/TinyEngine/Gui/Widgets/GuiInputNumberWidget.hpp
	src/TinyEngine/Gui/Widgets/GuiInputFloatWidget.hpp
	src/TinyEngine/Gui/Widgets/Containers/GuiPropertiesWidget.hpp
	src/TinyEngine/Gui/Widgets/Containers/GuiInputVectorWidget.hpp
	src/TinyEngine/Gui/Widgets/Containers/GuiInputMapWidget.hpp
	src/TinyEngine/Gui/Widgets/Containers/GuiMetaClassWidget.hpp
	src/TinyEngine/Data/Singleton.hpp
	src/TinyEngine/Data/Serialization/Serialization.hpp
	src/TinyEngine/Data/Serialization/SerializationVisitor.hpp
	src/TinyEngine/Data/Serialization/SerializationDefines.hpp
	src/TinyEngine/Data/Serialization/XmlArchive.hpp
	src/TinyEngine/Data/Meta/Members/MetaDefaultMembers.hpp
	src/TinyEngine/Data/Meta/Members/IMetaMember.hpp
	src/TinyEngine/Data/Meta/Members/MetaMembers.hpp
	src/TinyEngine/Data/Meta/Members/MetaVectorMember.hpp
	src/TinyEngine/Data/Meta/Members/MetaMapMember.hpp
	src/TinyEngine/Data/Meta/Members/MetaClassMember.hpp
	src/TinyEngine/Data/Meta/Members/MetaSharedPtrMember.hpp
	src/TinyEngine/Data/Meta/Class/MetaClass.hpp
	src/TinyEngine/Data/Meta/MetaDefines.hpp
	src/TinyEngine/Data/Meta/MetaVisitor.hpp
	src/TinyEngine/Data/Factory.hpp
	src/TinyEngine/Core/Assets/Asset.hpp
	src/TinyEngine/Core/Assets/AssetHolder.hpp
	src/TinyEngine/Core/Assets/AssetLoader.hpp
	src/TinyEngine/Core/Assets/AssetTexture.hpp
	src/TinyEngine/Core/Assets/Assets.hpp
)

set(ENGINE_SOURCES
	src/TinyEngine/Core/Application.cpp
	src/TinyEngine/Core/Logger.cpp
	src/TinyEngine/Core/Debug.cpp
	src/TinyEngine/Core/FileSystem.cpp
	src/TinyEngine/Render/Render.cpp
	src/TinyEngine/Render/RenderLayer.cpp
	src/TinyEngine/Render/RenderLayers.cpp
	src/TinyEngine/Render/Sfml/SfmlRenderObject.cpp
	src/TinyEngine/Render/Sfml/SfmlRenderUtils.cpp
	src/TinyEngine/Render/Sfml/SfmlRenderWindow.cpp
	src/TinyEngine/Gui/Gui.cpp
	src/TinyEngine/Gui/SfmlGuiDelegate.cpp
	src/TinyEngine/Gui/GuiWidgetContainer.cpp
	src/TinyEngine/Gui/Widgets/GuiLabelWidget.cpp
	src/TinyEngine/Gui/Widgets/GuiWindowWidget.cpp
	src/TinyEngine/Gui/Widgets/GuiMenuBarWidget.cpp
	src/TinyEngine/Gui/Widgets/GuiProjectWidget.cpp
	src/TinyEngine/Gui/Widgets/GuiButtonWidget.cpp
	src/TinyEngine/Gui/Widgets/GuiInputTextWidget.cpp
	src/TinyEngine/Gui/Widgets/GuiCheckboxWidget.cpp
	src/TinyEngine/Gui/Widgets/GuiInputNumberWidget.cpp
	src/TinyEngine/Gui/Widgets/GuiInputFloatWidget.cpp
	src/TinyEngine/Gui/Widgets/Containers/GuiPropertiesWidget.cpp
	src/TinyEngine/Gui/Widgets/Containers/GuiInputVectorWidget.cpp
	src/TinyEngine/Gui/Widgets/Containers/GuiInputMapWidget.cpp
	src/TinyEngine/Gui/Widgets/Containers/GuiMetaClassWidget.cpp
	src/TinyEngine/Data/Serialization/Serialization.cpp
	src/TinyEngine/Data/Serialization/XmlArchive.cpp
	src/TinyEngine/Data/Meta/Members/MetaDefaultMembers.cpp
	src/TinyEngine/Data/Meta/Members/IMetaMember.cpp
	src/TinyEngine/Data/Meta/Members/MetaMembers.cpp
	src/TinyEngine/Data/Meta/Members/MetaVectorMember.cpp
	src/TinyEngine/Data/Meta/Members/MetaMapMember.cpp
	src/TinyEngine/Data/Meta/Members/MetaClassMember.cpp
	src/TinyEngine/Data/Meta/Members/MetaSharedPtrMember.cpp
	src/TinyEngine/Data/Meta/Class/MetaClass.cpp
	src/TinyEngine/Core/Assets/Asset.cpp
	src/TinyEngine/Core/Assets/AssetHolder.cpp
	src/TinyEngine/Core/Assets/AssetLoader.cpp
	src/TinyEngine/Core/Assets/AssetTexture.cpp
	src/TinyEngine/Core/Assets/Assets.cpp
)
