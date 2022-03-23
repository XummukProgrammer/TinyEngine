#ifndef _GUI_MODEL_HEADER_
#define _GUI_MODEL_HEADER_

#include <TinyEngine/Data/EventableValue.hpp>

#include "imgui.h"

namespace TinyEngine
{
	class GuiModel
	{
	public:
		GuiModel() = default;
		virtual ~GuiModel() = default;

	public:
		virtual void OnInit();
		virtual void OnDeinit();

	public:
		BoolEventableValue isEnabled;
	};
}

#endif // _GUI_MODEL_HEADER_
