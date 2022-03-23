#ifndef _GUI_DEBUG_CONTROLLER_HEADER_
#define _GUI_DEBUG_CONTROLLER_HEADER_

#include <TinyEngine/Gui/GuiController.hpp>

#include <TinyEngine/Gui/Debug/GuiDebugModel.hpp>
#include <TinyEngine/Gui/Debug/GuiDebugView.hpp>

namespace TinyEngine
{
	class GuiDebugController final : public GuiController
	{
	public:
		GuiDebugController() = default;
		~GuiDebugController() = default;

	public:
		virtual GuiModel& GetModel() { return _model; }
		virtual GuiView& GetView() { return _view; }

	private:
		GuiDebugModel _model;
		GuiDebugView _view;
	};
}

#endif // _GUI_DEBUG_CONTROLLER_HEADER_
