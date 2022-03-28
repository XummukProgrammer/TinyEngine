#ifndef _SEQUENCE_ACTIONS_HEADER_
#define _SEQUENCE_ACTIONS_HEADER_

#include <TinyEngine/ActionsQueue/ActionsQueueContainer.hpp>

#include <fmt/format.h>

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

	public:
		void SetId(std::string_view id) override { _id = fmt::format("SequenceActions_{}", id); }
		std::string GetId() const override { return _id; }

	private:
		std::string _id;
	};
}

#endif // _SEQUENCE_ACTIONS_HEADER_
