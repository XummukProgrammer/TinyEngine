#ifndef _INTERFACE_OBJECT_HEADER_
#define _INTERFACE_OBJECT_HEADER_

namespace TinyEngine
{
	// Объект.
	class IObject
	{
	public:
		IObject() = default;
		virtual ~IObject() = default;

	public:
		// Окно обновляется.
		virtual void OnWindowUpdated() {}
		// Окно рисуется.
		virtual void OnWindowDrawed() {}
	};
}

#endif // _INTERFACE_OBJECT_HEADER_
