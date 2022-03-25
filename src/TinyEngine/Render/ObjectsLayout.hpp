#ifndef _OBJECTS_LAYOUT_HEADER_
#define _OBJECTS_LAYOUT_HEADER_

#include <TinyEngine/Render/ILayout.hpp>

namespace TinyEngine
{
	class ObjectsLayout final : public ILayout
	{
	public:
		ObjectsLayout() = default;
		~ObjectsLayout() = default;

	public:
		void OnWindowUpdated() override;
		void OnWindowDrawed() override;
	};
}

#endif // _OBJECTS_LAYOUT_HEADER_
