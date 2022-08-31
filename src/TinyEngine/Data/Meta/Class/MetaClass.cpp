#include "MetaClass.hpp"

namespace TinyEngine
{
	void MetaClass::AddGuiWidgetsToContainer(GuiWidgetContainerPtr container)
	{
		GetMembers().AddGuiWidgetsToContainer(container);
	}
}
