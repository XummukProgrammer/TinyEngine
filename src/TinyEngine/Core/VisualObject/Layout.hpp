#ifndef _LAYOUT_HEADER_
#define _LAYOUT_HEADER_

#include <memory>

namespace TinyEngine
{
	class Transform;

	class Layout
	{
	public:
		Layout() = default;
		virtual ~Layout() = default;

		void SetTransform(const std::shared_ptr<Transform>& transform);

		virtual void Recalculate() {}

	protected:
		std::shared_ptr<Transform> GetTransform() const { return _transform; }

	private:
		std::shared_ptr<Transform> _transform;
	};

	class VerticalLayout : public Layout
	{
	public:
		VerticalLayout() = default;
		~VerticalLayout() = default;

		void Recalculate() override;
	};
}

#endif // _LAYOUT_HEADER_
