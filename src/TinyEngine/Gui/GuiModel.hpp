#ifndef _GUI_MODEL_HEADER_
#define _GUI_MODEL_HEADER_

#include <TinyEngine/Data/EventableValue.hpp>

namespace TinyEngine
{
	class GuiModel
	{
	public:
		GuiModel();
		virtual ~GuiModel() = default;

	public:
		BoolEventableValue isEnabled;
	};
}

#endif // _GUI_MODEL_HEADER_
