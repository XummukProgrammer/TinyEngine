#ifndef _I_CHILD_VIEW_HEADER_
#define _I_CHILD_VIEW_HEADER_

#include <TinyEngine/Core/GUI/Widgets/Window/IWindowView.hpp>

namespace TinyEngine
{
	class IChildView : public IWindowView
	{
	public:
		IChildView() = default;
		virtual ~IChildView() = default;
	};
}

#endif // _I_CHILD_VIEW_HEADER_
