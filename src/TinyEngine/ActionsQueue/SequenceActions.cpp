#include "SequenceActions.hpp"

namespace TinyEngine
{
	void SequenceActions::OnExecute()
	{ 
		OnWindowUpdated();
	}

	bool SequenceActions::IsExecuted() const
	{
		return IsEmpty();
	}
}
