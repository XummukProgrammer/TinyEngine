#ifndef _LAYOUT_HEADER_
#define _LAYOUT_HEADER_

#include <memory>

namespace TinyEngine
{
	class Transform;

	class Layout
	{
	public:
		void SetTransform(const std::shared_ptr<Transform>& transform);

		void Recalculate();

	private:
		std::shared_ptr<Transform> _transform;
	};
}

#endif // _LAYOUT_HEADER_
