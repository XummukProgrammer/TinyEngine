#ifndef _COMPONENT_HEADER_
#define _COMPONENT_HEADER_

#include <memory>

namespace TinyEngine::Level
{
	class Component
	{
	public:
		Component() = default;
		virtual ~Component() = default;

	public:
		virtual void OnInit() {}
		virtual void OnDeinit() {}

		virtual void OnUpdate() {}

	public:
		bool IsValid() const;

		void Remove();
		bool IsRemoved() const;

	private:
		bool _isRemoved = false;
	};
}

#endif // _COMPONENT_HEADER_
