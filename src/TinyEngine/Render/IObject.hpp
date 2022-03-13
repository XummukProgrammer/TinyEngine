#ifndef _INTERFACE_OBJECT_HEADER_
#define _INTERFACE_OBJECT_HEADER_

#include <memory>

namespace TinyEngine::Render
{
	class IObject
	{
	public:
		IObject() = default;
		virtual ~IObject() = default;

	public:
		virtual void OnInit() {}
		virtual void OnDeinit() {}

		virtual void OnUpdate() {}
		virtual void OnDraw() {}
	};
}

#endif // _INTERFACE_OBJECT_HEADER_
