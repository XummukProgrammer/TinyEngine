#ifndef _ACTIONS_QUEUE_CONTAINER_HEADER_
#define _ACTIONS_QUEUE_CONTAINER_HEADER_

#include <TinyEngine/ActionsQueue/IAction.hpp>
#include <TinyEngine/Data/Queue.hpp>

#include <memory>
#include <string>

namespace TinyEngine
{
	class ActionsQueueContainer
	{
	public:
		using IActionPtr = std::unique_ptr<IAction>;

	public:
		ActionsQueueContainer() = default;
		virtual ~ActionsQueueContainer() = default;

	public:
		void OnWindowUpdated();

	public:
		void AddAction(IActionPtr&& action);
		std::vector<std::string> GetActionsIds() const;

		bool IsEmpty() const { return _actionsQueue.IsEmpty(); }

	private:
		// Очередь экшенов.
		Queue<IActionPtr> _actionsQueue;
	};
}

#endif // _ACTIONS_QUEUE_CONTAINER_HEADER_
