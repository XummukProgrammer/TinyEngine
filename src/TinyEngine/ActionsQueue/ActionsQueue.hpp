#ifndef _ACTIONS_QUEUE_HEADER_
#define _ACTIONS_QUEUE_HEADER_

#include <TinyEngine/ActionsQueue/ActionsQueueContainer.hpp>

#include <memory>

namespace TinyEngine
{
	class ActionsQueue final : public ActionsQueueContainer
	{
	public:
		ActionsQueue() = default;
		~ActionsQueue() = default;
	};
}

#endif // _ACTIONS_QUEUE_HEADER_
