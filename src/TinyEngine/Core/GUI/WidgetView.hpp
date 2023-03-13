﻿#ifndef _WIDGET_VIEW_HEADER_
#define _WIDGET_VIEW_HEADER_

namespace TinyEngine
{
	class IWidgetView
	{
	public:
		IWidgetView() = default;
		virtual ~IWidgetView() = default;

	public:
		virtual void OnDraw() = 0;
	};
}

#endif // _WIDGET_VIEW_HEADER_
