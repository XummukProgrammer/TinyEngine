#ifndef _GUI_CONTROLLER_HEADER_
#define _GUI_CONTROLLER_HEADER_

#include "GuiModel.hpp"
#include "GuiView.hpp"

#include <memory>

namespace TinyEngine
{
	class GuiController
	{
	public:
		GuiController() = default;
		virtual ~GuiController() = default;

	public:
		void OnGuiRenderer();

	public:
		virtual GuiModel& GetModel() = 0;
		virtual GuiView& GetView() = 0;

	protected:
		virtual void CreateModel() = 0;
		virtual void CreateView() = 0;
		
	};
}

#endif // _GUI_CONTROLLER_HEADER_
