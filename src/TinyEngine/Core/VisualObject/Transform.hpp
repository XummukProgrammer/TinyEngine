#ifndef _TRANSFORM_HEADER_
#define _TRANSFORM_HEADER_

#include <raylib-cpp.hpp>

#include <memory>
#include <vector>

namespace TinyEngine
{
	class Transform : public std::enable_shared_from_this<Transform>
	{
	public:
		Transform() = default;
		virtual ~Transform() = default;

		void SetParent(const std::shared_ptr<Transform>& parent) { _parent = parent; }
		std::shared_ptr<Transform> GetParent() const { return _parent; }

		void Attach(std::shared_ptr<Transform> transform);
		void Detach(std::shared_ptr<Transform> transform);

		void SetLocalPosition(const RVector2& position);
		const RVector2& GetLocalPosition() const { return _localPosition; }

		const RVector2& GetPosition() const { return _position; }

		virtual void Draw() {}

	private:
		void Recalculate();

	private:
		std::shared_ptr<Transform> _parent;
		std::vector<std::shared_ptr<Transform>> _attached;
		RVector2 _localPosition;
		RVector2 _position;
	};
}

#endif // _TRANSFORM_HEADER_
