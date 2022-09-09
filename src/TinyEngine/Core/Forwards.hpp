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

namespace TinyEngine
{
	enum class DirType;
	enum class ArchiveFormat;
	enum class RenderType;
	enum class MetaMemberFlag;

	TINY_ENGINE_FORWARD_CLASS(ApplicationDelegate)
	//TINY_ENGINE_FORWARD_CLASS(Application)
	//TINY_ENGINE_FORWARD_CLASS(IDebugOperation)
	TINY_ENGINE_FORWARD_CLASS(Debug)
	TINY_ENGINE_FORWARD_CLASS(FileSystem)
	//TINY_ENGINE_FORWARD_CLASS(LoggerStacktrace)
	//TINY_ENGINE_FORWARD_CLASS(LoggerMessage)
	//TINY_ENGINE_FORWARD_CLASS(LoggerMessages)
	TINY_ENGINE_FORWARD_CLASS(Logger)
	TINY_ENGINE_FORWARD_CLASS(Asset)
	TINY_ENGINE_FORWARD_CLASS(AssetHolder)
	TINY_ENGINE_FORWARD_CLASS(AssetSource)
	TINY_ENGINE_FORWARD_CLASS(AssetLoader)
	TINY_ENGINE_FORWARD_CLASS(Assets)
	TINY_ENGINE_FORWARD_CLASS(AssetTexture)
	TINY_ENGINE_FORWARD_CLASS(AssetSfmlTexture)
	TINY_ENGINE_FORWARD_CLASS(Factory)
	TINY_ENGINE_FORWARD_CLASS(IArchive)
	TINY_ENGINE_FORWARD_CLASS(BaseArchive)
	TINY_ENGINE_FORWARD_CLASS(OutputArchive)
	TINY_ENGINE_FORWARD_CLASS(InputArchive)
	//TINY_ENGINE_FORWARD_CLASS(SerializationUtils)
	TINY_ENGINE_FORWARD_STRUCT(XmlDataArchive)
	TINY_ENGINE_FORWARD_CLASS(XmlOutputArchive)
	TINY_ENGINE_FORWARD_CLASS(XmlInputArchive)
	TINY_ENGINE_FORWARD_CLASS(GuiDelegate)
	TINY_ENGINE_FORWARD_CLASS(Gui)
	TINY_ENGINE_FORWARD_CLASS(GuiWidget)
	TINY_ENGINE_FORWARD_CLASS(GuiWidgetContainer)
	TINY_ENGINE_FORWARD_CLASS(SfmlGuiDelegate)
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
	TINY_ENGINE_FORWARD_STRUCT(RenderWindowSettings)
	TINY_ENGINE_FORWARD_STRUCT(Point)
	TINY_ENGINE_FORWARD_STRUCT(PointF)
	TINY_ENGINE_FORWARD_STRUCT(Rect)
	TINY_ENGINE_FORWARD_STRUCT(RectF)
	TINY_ENGINE_FORWARD_STRUCT(Texture)
	TINY_ENGINE_FORWARD_CLASS(IRenderObject)
	TINY_ENGINE_FORWARD_CLASS(RenderObjectBuilder)
	TINY_ENGINE_FORWARD_CLASS(IRenderWindow)
	TINY_ENGINE_FORWARD_CLASS(RenderLayer)
	TINY_ENGINE_FORWARD_CLASS(RenderLayers)
	TINY_ENGINE_FORWARD_CLASS(Render)
	TINY_ENGINE_FORWARD_CLASS(SfmlRenderUtils)
	TINY_ENGINE_FORWARD_CLASS(SfmlRenderObject)
	TINY_ENGINE_FORWARD_CLASS(SfmlRenderObjectBuilder)
	TINY_ENGINE_FORWARD_CLASS(SfmlRenderWindow)
	TINY_ENGINE_FORWARD_CLASS(MetaMemberData)
	TINY_ENGINE_FORWARD_CLASS(IMetaMember)
	TINY_ENGINE_FORWARD_CLASS(MetaIntMemberWrapper)
	TINY_ENGINE_FORWARD_CLASS(MetaIntMember)
	TINY_ENGINE_FORWARD_CLASS(MetaMembers)
	TINY_ENGINE_FORWARD_CLASS(MetaClass)
}

#endif // _FORWARDS_HEADER_
