#include "MetaClass.hpp"

namespace TinyEngine
{
	MetaMembers& MetaClass::GetMembers(bool isCheckLoaded)
	{
		if (isCheckLoaded)
		{
			_members.Clear();
			OnLoad();
		}
		return _members;
	}

	bool MetaClass::IsLoaded() const
	{
		return !_members.IsEmpty();
	}

	void MetaClass::AddGuiWidgetsToContainer(GuiWidgetContainerPtr container)
	{
		GetMembers().AddGuiWidgetsToContainer(container);
	}

	void MetaClass::TryLoad()
	{
		if (!IsLoaded())
		{
			OnLoad();
		}
	}
}
