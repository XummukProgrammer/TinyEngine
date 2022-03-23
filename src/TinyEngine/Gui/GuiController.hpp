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
		void OnAppEntry();
		void OnAppQuit();

		void OnGuiRenderer();

	private:
		void OnIsEnableChanged(BoolEventableValue::ValueChangedParametersTemplate& params);

	protected:
		virtual void OnInit();
		virtual void OnDeinit();

		virtual void OnEnable() {}
		virtual void OnDisable() {}

	public:
		virtual GuiModel& GetModel() = 0;
		virtual GuiView& GetView() = 0;
	};
}

#endif // _GUI_CONTROLLER_HEADER_
