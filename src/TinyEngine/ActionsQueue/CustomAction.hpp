#ifndef _CUSTOM_ACTION_HEADER_
#define _CUSTOM_ACTION_HEADER_

#include <TinyEngine/ActionsQueue/IAction.hpp>

#include <functional>

namespace TinyEngine
{
	class CustomAction final : public IAction
	{
	public:
		using ConditionCallback = std::function<bool()>;
		using DefaultCallback = std::function<void()>;

	public:
		CustomAction() = default;
		~CustomAction() = default;

	public:
		bool IsExecute() const override;
		void OnExecute() override;

	public:
		void SetIsExecuteCallback(const ConditionCallback& callback) { _isExecuteCallback = callback; }
		void SetOnExecuteCallback(const DefaultCallback& callback) { _onExecuteCallback = callback; }

	private:
		ConditionCallback _isExecuteCallback;
		DefaultCallback _onExecuteCallback;
	};
}

#endif // _CUSTOM_ACTION_HEADER_
