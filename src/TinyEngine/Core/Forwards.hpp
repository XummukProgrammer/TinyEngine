﻿#ifndef _FORWARDS_HEADER_
#define _FORWARDS_HEADER_

#include <memory>

#define TINY_ENGINE_FORWARD_BASE(type, name) \
	type name; \
	using name ## Ptr = name*; \
	using name ## SharedPtr = std::shared_ptr<name>; \
	using name ## UniquePtr = std::unique_ptr<name>; \
	using name ## WeakPtr = std::weak_ptr<name>;

#define TINY_ENGINE_FORWARD_STRUCT(cls) TINY_ENGINE_FORWARD_BASE(struct, cls)
#define TINY_ENGINE_FORWARD_CLASS(cls) TINY_ENGINE_FORWARD_BASE(class, cls)

#define TINY_ENGINE_FORWARD_ENUM_CLASS(name) enum class name;

namespace TinyEngine
{
	TINY_ENGINE_FORWARD_ENUM_CLASS(DirType)
	TINY_ENGINE_FORWARD_ENUM_CLASS(ArchiveFormat)
	TINY_ENGINE_FORWARD_ENUM_CLASS(MetaMemberFlag)
	TINY_ENGINE_FORWARD_ENUM_CLASS(LogType)

	TINY_ENGINE_FORWARD_CLASS(ApplicationDelegate)
	TINY_ENGINE_FORWARD_CLASS(Debug)
	TINY_ENGINE_FORWARD_CLASS(FileSystem)
	TINY_ENGINE_FORWARD_CLASS(Logger)
	TINY_ENGINE_FORWARD_CLASS(Asset)
	TINY_ENGINE_FORWARD_CLASS(AssetHolder)
	TINY_ENGINE_FORWARD_CLASS(AssetSource)
	TINY_ENGINE_FORWARD_CLASS(AssetLoader)
	TINY_ENGINE_FORWARD_CLASS(Assets)
	TINY_ENGINE_FORWARD_CLASS(Factory)
	TINY_ENGINE_FORWARD_CLASS(IArchive)
	TINY_ENGINE_FORWARD_CLASS(BaseArchive)
	TINY_ENGINE_FORWARD_CLASS(OutputArchive)
	TINY_ENGINE_FORWARD_CLASS(InputArchive)
	TINY_ENGINE_FORWARD_STRUCT(XmlDataArchive)
	TINY_ENGINE_FORWARD_CLASS(XmlOutputArchive)
	TINY_ENGINE_FORWARD_CLASS(XmlInputArchive)
	TINY_ENGINE_FORWARD_CLASS(Gui)
	TINY_ENGINE_FORWARD_CLASS(GuiWidget)
	TINY_ENGINE_FORWARD_CLASS(GuiWidgetContainer)
	TINY_ENGINE_FORWARD_CLASS(GuiLabelWidget)
	TINY_ENGINE_FORWARD_CLASS(GuiMenuBarWidget)
	TINY_ENGINE_FORWARD_CLASS(GuiWindowWidget)
	TINY_ENGINE_FORWARD_CLASS(GuiMainWindowWidget)
	TINY_ENGINE_FORWARD_CLASS(GuiProjectWidget)
	TINY_ENGINE_FORWARD_CLASS(GuiButtonWidget)
	TINY_ENGINE_FORWARD_CLASS(GuiInputTextWidget)
	TINY_ENGINE_FORWARD_CLASS(GuiCheckboxWidget)
	TINY_ENGINE_FORWARD_CLASS(GuiInputNumberWidget)
	TINY_ENGINE_FORWARD_CLASS(GuiInputFloatWidget)
	TINY_ENGINE_FORWARD_CLASS(GuiPropertiesWidget)
	TINY_ENGINE_FORWARD_CLASS(GuiInputVectorWidget)
	TINY_ENGINE_FORWARD_CLASS(GuiInputMapWidget)
	TINY_ENGINE_FORWARD_CLASS(GuiMetaClassWidget)
	TINY_ENGINE_FORWARD_CLASS(GuiSharedPtrWidget)
	TINY_ENGINE_FORWARD_CLASS(GuiStringListBoxWidget)
	TINY_ENGINE_FORWARD_CLASS(GuiInputEnumWidget)
	TINY_ENGINE_FORWARD_STRUCT(RenderWindowSettings)
	TINY_ENGINE_FORWARD_CLASS(Point)
	TINY_ENGINE_FORWARD_CLASS(PointF)
	TINY_ENGINE_FORWARD_STRUCT(Rect)
	TINY_ENGINE_FORWARD_STRUCT(RectF)
	TINY_ENGINE_FORWARD_STRUCT(Texture)
	TINY_ENGINE_FORWARD_CLASS(RenderLayer)
	TINY_ENGINE_FORWARD_CLASS(RenderLayers)
	TINY_ENGINE_FORWARD_CLASS(Render)
	TINY_ENGINE_FORWARD_CLASS(MetaMemberData)
	TINY_ENGINE_FORWARD_CLASS(IMetaMember)
	TINY_ENGINE_FORWARD_CLASS(MetaIntMemberWrapper)
	TINY_ENGINE_FORWARD_CLASS(MetaIntMember)
	TINY_ENGINE_FORWARD_CLASS(MetaMembers)
	TINY_ENGINE_FORWARD_CLASS(MetaClass)
	TINY_ENGINE_FORWARD_CLASS(RenderObject)
	TINY_ENGINE_FORWARD_CLASS(Entity)
	TINY_ENGINE_FORWARD_CLASS(Component)
	TINY_ENGINE_FORWARD_CLASS(World)
	TINY_ENGINE_FORWARD_CLASS(TransformComponent)
	TINY_ENGINE_FORWARD_CLASS(VisualComponent)
}

#endif // _FORWARDS_HEADER_
