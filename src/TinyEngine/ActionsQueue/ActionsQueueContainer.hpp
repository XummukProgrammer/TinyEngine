﻿#ifndef _ACTIONS_QUEUE_CONTAINER_HEADER_
#define _ACTIONS_QUEUE_CONTAINER_HEADER_

#include <TinyEngine/ActionsQueue/IAction.hpp>

#include <queue>
#include <memory>

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

		bool IsEmpty() const { return _actionsQueue.empty(); }

	private:
		// Очередь экшенов.
		std::queue<IActionPtr> _actionsQueue;
	};
}

#endif // _ACTIONS_QUEUE_CONTAINER_HEADER_
