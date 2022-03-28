#ifndef _SEQUENCE_ACTIONS_HEADER_
#define _SEQUENCE_ACTIONS_HEADER_

#include <TinyEngine/ActionsQueue/IAction.hpp>

#include <queue>
#include <memory>

namespace TinyEngine
{
	class SequenceActions final : public IAction
	{
	public:
		using IActionPtr = std::unique_ptr<IAction>;

	public:
		SequenceActions() = default;
		~SequenceActions() = default;

	public:
		bool IsExecute() const override { return true; }
		void OnExecute() override;
		bool IsExecuted() const override;

	public:
		void AddAction(IActionPtr&& action);

	private:
		std::queue<IActionPtr> _actionsQueue;
	};
}

#endif // _SEQUENCE_ACTIONS_HEADER_
