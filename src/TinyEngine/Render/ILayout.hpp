#ifndef _INTERFACE_LAYOUT_HEADER_
#define _INTERFACE_LAYOUT_HEADER_

namespace TinyEngine
{
	class ILayout
	{
	public:
		ILayout() = default;
		virtual ~ILayout() = default;

	public:
		virtual void OnWindowUpdated() {}
		virtual void OnWindowDrawed() {}
	};
}

#endif // _INTERFACE_LAYOUT_HEADER_
