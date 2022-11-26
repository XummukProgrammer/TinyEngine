
set(ENGINE_HEADERS
	src/TinyEngine/TinyEngine.hpp
	src/TinyEngine/Core/Application.hpp
	src/TinyEngine/Core/Logger.hpp
	src/TinyEngine/Core/Debug.hpp
	src/TinyEngine/Core/FileSystem.hpp
	src/TinyEngine/Core/Constants.hpp
	src/TinyEngine/Core/Forwards.hpp
	src/TinyEngine/Core/Render/Render.hpp
	src/TinyEngine/Core/Render/RenderObject.hpp
	src/TinyEngine/Core/Render/RenderWindow.hpp
	src/TinyEngine/Core/Render/Point.hpp
	src/TinyEngine/Core/Render/Rect.hpp
	src/TinyEngine/Core/Render/RenderLayer.hpp
	src/TinyEngine/Core/Render/RenderLayers.hpp
	src/TinyEngine/Core/Render/RenderWindowSettings.hpp
	src/TinyEngine/Core/Render/Texture.hpp
	src/TinyEngine/Core/Gui/Gui.hpp
	src/TinyEngine/Core/Gui/GuiVisitor.hpp
	src/TinyEngine/Core/Gui/GuiWidget.hpp
	src/TinyEngine/Core/Gui/GuiWidgetContainer.hpp
	src/TinyEngine/Core/Gui/Widgets/GuiLabelWidget.hpp
	src/TinyEngine/Core/Gui/Widgets/GuiWindowWidget.hpp
	src/TinyEngine/Core/Gui/Widgets/GuiMenuBarWidget.hpp
	src/TinyEngine/Core/Gui/Widgets/GuiButtonWidget.hpp
	src/TinyEngine/Core/Gui/Widgets/GuiInputTextWidget.hpp
	src/TinyEngine/Core/Gui/Widgets/GuiCheckboxWidget.hpp
	src/TinyEngine/Core/Gui/Widgets/GuiInputNumberWidget.hpp
	src/TinyEngine/Core/Gui/Widgets/GuiInputFloatWidget.hpp
	src/TinyEngine/Core/Gui/Widgets/GuiStringListBoxWidget.hpp
	src/TinyEngine/Core/Gui/Widgets/GuiFileBrowserWidget.hpp
	src/TinyEngine/Core/Gui/Widgets/Containers/GuiPropertiesWidget.hpp
	src/TinyEngine/Core/Gui/Widgets/Containers/GuiInputVectorWidget.hpp
	src/TinyEngine/Core/Gui/Widgets/Containers/GuiInputMapWidget.hpp
	src/TinyEngine/Core/Gui/Widgets/Containers/GuiMetaClassWidget.hpp
	src/TinyEngine/Core/Gui/Widgets/Containers/GuiSharedPtrWidget.hpp
	src/TinyEngine/Core/Gui/Widgets/Containers/GuiTreeContainerWidget.hpp
	src/TinyEngine/Core/Data/Singleton.hpp
	src/TinyEngine/Core/Data/Serialization/Serialization.hpp
	src/TinyEngine/Core/Data/Serialization/SerializationVisitor.hpp
	src/TinyEngine/Core/Data/Serialization/SerializationDefines.hpp
	src/TinyEngine/Core/Data/Serialization/XmlArchive.hpp
	src/TinyEngine/Core/Data/Meta/Members/IMetaMember.hpp
	src/TinyEngine/Core/Data/Meta/Members/MetaMembers.hpp
	src/TinyEngine/Core/Data/Meta/Class/MetaClass.hpp
	src/TinyEngine/Core/Data/Meta/MetaDefines.hpp
	src/TinyEngine/Core/Data/Meta/MetaVisitor.hpp
	src/TinyEngine/Core/Data/Factory.hpp
	src/TinyEngine/Core/Assets/Asset.hpp
	src/TinyEngine/Core/Assets/AssetFile.hpp
	src/TinyEngine/Core/Assets/Common/AssetHolder.hpp
	src/TinyEngine/Core/Assets/Assets.hpp
	src/TinyEngine/Core/Assets/Common/TextureAsset.hpp
	src/TinyEngine/Core/Assets/Common/LinkAsset.hpp
	src/TinyEngine/Core/World/World.hpp
	src/TinyEngine/Core/World/Entity.hpp
	src/TinyEngine/Core/World/Component.hpp
	src/TinyEngine/Core/World/Common/Components/TransformComponent.hpp
	src/TinyEngine/Core/World/Common/Components/VisualComponent.hpp
	src/TinyEngine/Core/Event/Event.hpp
	src/TinyEngine/Core/Event/EventSender.hpp
	src/TinyEngine/Core/Event/EventSubscriber.hpp
	src/TinyEngine/Core/States/State.hpp
	src/TinyEngine/Core/States/States.hpp
	src/TinyEngine/Core/States/StateTransition.hpp
	src/TinyEngine/Core/States/StateTransitions.hpp
	src/TinyEngine/Core/States/Common/StateConditionTransition.hpp
	src/TinyEngine/Core/States/Common/StartState.hpp
	src/TinyEngine/Core/States/Common/CloseState.hpp
	src/TinyEngine/Core/Conditions/Condition.hpp
	src/TinyEngine/Core/Conditions/ConditionVariable.hpp
	src/TinyEngine/Core/Conditions/ConditionContext.hpp
	src/TinyEngine/Core/Conditions/ConditionContextVariable.hpp
	src/TinyEngine/Core/Conditions/Common/AndCondition.hpp
	src/TinyEngine/Core/Conditions/Common/CompareCondition.hpp
	src/TinyEngine/Core/Conditions/Common/OrCondition.hpp
	
	src/TinyEngine/Core/Project.hpp
	
	src/TinyEngine/Libs/ImGui-Addons/FileBrowser/ImGuiFileBrowser.h
	
	src/Dirent/dirent.h
)

set(ENGINE_SOURCES
	src/TinyEngine/Core/Application.cpp
	src/TinyEngine/Core/Logger.cpp
	src/TinyEngine/Core/Debug.cpp
	src/TinyEngine/Core/FileSystem.cpp
	src/TinyEngine/Core/Render/Render.cpp
	src/TinyEngine/Core/Render/RenderLayer.cpp
	src/TinyEngine/Core/Render/RenderLayers.cpp
	src/TinyEngine/Core/Gui/Gui.cpp
	src/TinyEngine/Core/Gui/GuiWidgetContainer.cpp
	src/TinyEngine/Core/Gui/Widgets/GuiLabelWidget.cpp
	src/TinyEngine/Core/Gui/Widgets/GuiWindowWidget.cpp
	src/TinyEngine/Core/Gui/Widgets/GuiMenuBarWidget.cpp
	src/TinyEngine/Core/Gui/Widgets/GuiButtonWidget.cpp
	src/TinyEngine/Core/Gui/Widgets/GuiInputTextWidget.cpp
	src/TinyEngine/Core/Gui/Widgets/GuiCheckboxWidget.cpp
	src/TinyEngine/Core/Gui/Widgets/GuiInputNumberWidget.cpp
	src/TinyEngine/Core/Gui/Widgets/GuiInputFloatWidget.cpp
	src/TinyEngine/Core/Gui/Widgets/GuiStringListBoxWidget.cpp
	src/TinyEngine/Core/Gui/Widgets/GuiFileBrowserWidget.cpp
	src/TinyEngine/Core/Gui/Widgets/Containers/GuiPropertiesWidget.cpp
	src/TinyEngine/Core/Gui/Widgets/Containers/GuiInputVectorWidget.cpp
	src/TinyEngine/Core/Gui/Widgets/Containers/GuiInputMapWidget.cpp
	src/TinyEngine/Core/Gui/Widgets/Containers/GuiMetaClassWidget.cpp
	src/TinyEngine/Core/Gui/Widgets/Containers/GuiSharedPtrWidget.cpp
	src/TinyEngine/Core/Gui/Widgets/Containers/GuiTreeContainerWidget.cpp
	src/TinyEngine/Core/Data/Serialization/Serialization.cpp
	src/TinyEngine/Core/Data/Serialization/XmlArchive.cpp
	src/TinyEngine/Core/Data/Meta/Members/MetaMembers.cpp
	src/TinyEngine/Core/Data/Meta/Class/MetaClass.cpp
	src/TinyEngine/Core/Assets/Asset.cpp
	src/TinyEngine/Core/Assets/AssetFile.cpp
	src/TinyEngine/Core/Assets/Common/AssetHolder.cpp
	src/TinyEngine/Core/Assets/Assets.cpp
	src/TinyEngine/Core/Assets/Common/TextureAsset.cpp
	src/TinyEngine/Core/Assets/Common/LinkAsset.cpp
	src/TinyEngine/Core/World/World.cpp
	src/TinyEngine/Core/World/Entity.cpp
	src/TinyEngine/Core/World/Common/Components/VisualComponent.cpp
	src/TinyEngine/Core/Event/EventSender.cpp
	src/TinyEngine/Core/Event/EventSubscriber.cpp
	src/TinyEngine/Core/States/State.cpp
	src/TinyEngine/Core/States/States.cpp
	src/TinyEngine/Core/States/StateTransition.cpp
	src/TinyEngine/Core/States/StateTransitions.cpp
	src/TinyEngine/Core/States/Common/StateConditionTransition.cpp
	src/TinyEngine/Core/States/Common/StartState.cpp
	src/TinyEngine/Core/States/Common/CloseState.cpp
	src/TinyEngine/Core/Conditions/Condition.cpp
	src/TinyEngine/Core/Conditions/ConditionVariable.cpp
	src/TinyEngine/Core/Conditions/ConditionContext.cpp
	src/TinyEngine/Core/Conditions/ConditionContextVariable.cpp
	src/TinyEngine/Core/Conditions/Common/AndCondition.cpp
	src/TinyEngine/Core/Conditions/Common/CompareCondition.cpp
	src/TinyEngine/Core/Conditions/Common/OrCondition.cpp
	
	src/TinyEngine/Core/Project.cpp
	
	src/TinyEngine/Libs/ImGui-Addons/FileBrowser/ImGuiFileBrowser.cpp
	
	# TODO: Не подключать, если сборка с SFML отключена
	src/TinyEngine/Core/Backends/SFML/GUI/SfmlGuiImpl.cpp
	src/TinyEngine/Core/Backends/SFML/Render/SfmlRenderObjectImpl.cpp
	src/TinyEngine/Core/Backends/SFML/Render/SfmlRenderWindowImpl.cpp
)
