#ifndef _SEQUENCE_ACTIONS_HEADER_
#define _SEQUENCE_ACTIONS_HEADER_

#include <TinyEngine/ActionsQueue/ActionsQueueContainer.hpp>

#include <queue>
#include <memory>

namespace TinyEngine
{
	class SequenceActions final : public ActionsQueueContainer, public IAction
	{
	public:
		SequenceActions() = default;
		~SequenceActions() = default;

	public:
		bool IsExecute() const override { return true; }
		void OnExecute() override;
		bool IsExecuted() const override;
	};
}

#endif // _SEQUENCE_ACTIONS_HEADER_
