#ifndef _VISUAL_OBJECT_HEADER_
#define _VISUAL_OBJECT_HEADER_

#include <TinyEngine/Render/IObject.hpp>

namespace TinyEngine::Render
{
	class VisualObject final : public IObject
	{
	public:
		VisualObject() = default;
		~VisualObject() = default;

	public:
		void OnDraw() override;
	};
}

#endif // _VISUAL_OBJECT_HEADER_
