﻿#ifndef _TINY_ENGINE_HEADER_
#define _TINY_ENGINE_HEADER_

#include <TinyEngine/Core/Core.hpp>
#include <TinyEngine/Core/Application.hpp>
#include <TinyEngine/Core/Window.hpp>
#include <TinyEngine/Core/FpsCounter.hpp>
#include <TinyEngine/Core/Timer.hpp>
#include <TinyEngine/Core/PathBuilder.hpp>

#include <TinyEngine/Events/Publisher.hpp>
#include <TinyEngine/Events/Subscriber.hpp>
#include <TinyEngine/Events/EventParameters.hpp>

#include <TinyEngine/Data/CounterRef.hpp>
#include <TinyEngine/Data/EventableValue.hpp>

#include <TinyEngine/Gui/GuiController.hpp>
#include <TinyEngine/Gui/GuiModel.hpp>
#include <TinyEngine/Gui/GuiView.hpp>
#include <TinyEngine/Gui/GuiControllers.hpp>

#include <TinyEngine/Gui/Debug/GuiDebugController.hpp>
#include <TinyEngine/Gui/Debug/GuiDebugModel.hpp>
#include <TinyEngine/Gui/Debug/GuiDebugView.hpp>

#include <TinyEngine/Assets/Assets.hpp>
#include <TinyEngine/Assets/AllAssets.hpp>
#include <TinyEngine/Assets/IAsset.hpp>
#include <TinyEngine/Assets/AssetParameters.hpp>
#include <TinyEngine/Assets/TextureAssets.hpp>

#include <TinyEngine/Render/Render.hpp>
#include <TinyEngine/Render/ILayout.hpp>
#include <TinyEngine/Render/IObject.hpp>
#include <TinyEngine/Render/ObjectsLayout.hpp>
#include <TinyEngine/Render/VisualObject.hpp>
#include <TinyEngine/Render/RadialLightObject.hpp>

#include <TinyEngine/ActionsQueue/ActionsQueue.hpp>
#include <TinyEngine/ActionsQueue/IAction.hpp>
#include <TinyEngine/ActionsQueue/CustomAction.hpp>
#include <TinyEngine/ActionsQueue/SequenceActions.hpp>

#endif // _TINY_ENGINE_HEADER_
