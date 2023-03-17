#ifndef _SAME_LINE_HEADER_
#define _SAME_LINE_HEADER_

#include <TinyEngine/Core/GUI/Widget.hpp>

namespace TinyEngine
{
	class SameLine final : public Widget
	{
	public:
		SameLine() = default;
		~SameLine() = default;

	protected:
		virtual std::unique_ptr<IWidgetView> MakeImGUIView() const override;
	};
}

#endif // _SAME_LINE_HEADER_
