#ifndef _INTERFACE_ACTION_HEADER_
#define _INTERFACE_ACTION_HEADER_

#include <string>

namespace TinyEngine
{
	class IAction
	{
	public:
		IAction() = default;
		virtual ~IAction() = default;

	public:
		virtual bool IsExecute() const = 0;
		virtual void OnExecute() = 0;
		virtual bool IsExecuted() const = 0;

		virtual void SetId(std::string_view id) = 0;
		virtual std::string GetId() const = 0;
	};
}

#endif // _INTERFACE_ACTION_HEADER_
