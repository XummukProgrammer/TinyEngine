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

		const std::vector<std::shared_ptr<Transform>>& GetAttached() const { return _attached; }

		void SetLocalPosition(const RVector2& position);
		const RVector2& GetLocalPosition() const { return _localPosition; }

		void SetPosition(const RVector2& position) { _position = position; }
		const RVector2& GetPosition() const { return _position; }

		RRectangle GetRectangle() const;

		void SetLocalScale(const RVector2& scale);
		const RVector2& GetLocalScale() const { return _localScale; }

		virtual void Draw();

	protected:
		virtual void OnDrawGizmos();

	private:
		void Recalculate();

	private:
		std::shared_ptr<Transform> _parent;
		std::vector<std::shared_ptr<Transform>> _attached;
		RVector2 _localPosition;
		RVector2 _position;
		RVector2 _localScale;
	};
}

#endif // _TRANSFORM_HEADER_
