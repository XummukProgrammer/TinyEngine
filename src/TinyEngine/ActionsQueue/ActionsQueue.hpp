#ifndef _ACTIONS_QUEUE_HEADER_
#define _ACTIONS_QUEUE_HEADER_

#include <TinyEngine/ActionsQueue/IAction.hpp>

#include <memory>
#include <queue>

namespace TinyEngine
{
	class ActionsQueue final
	{
	public:
		using IActionPtr = std::unique_ptr<IAction>;

	public:
		ActionsQueue() = default;
		virtual ~ActionsQueue() = default;

	public:
		void OnWindowUpdated();

	public:
		void AddAction(IActionPtr&& action);

	public:
		// Очередь экшенов.
		std::queue<IActionPtr> _actionsQueue;
	};
}

#endif // _ACTIONS_QUEUE_HEADER_
