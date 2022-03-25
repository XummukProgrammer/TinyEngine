#ifndef _INTERFACE_OBJECT_HEADER_
#define _INTERFACE_OBJECT_HEADER_

namespace TinyEngine
{
	class IObject
	{
	public:
		IObject() = default;
		virtual ~IObject() = default;

	public:
		virtual void OnWindowUpdated() {}
		virtual void OnWindowDrawed() {}
	};
}

#endif // _INTERFACE_OBJECT_HEADER_
