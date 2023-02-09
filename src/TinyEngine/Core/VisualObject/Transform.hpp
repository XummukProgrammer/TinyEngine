#ifndef _TRANSFORM_HEADER_
#define _TRANSFORM_HEADER_

#include <TinyEngine/Core/VisualObject/Anchor.hpp>

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

		RVector2 GetPosition() const;
		RRectangle GetRectangle() const;

		void SetLocalScale(const RVector2& scale);
		const RVector2& GetLocalScale() const { return _localScale; }

		void SetAnchor(const std::shared_ptr<Anchor>& anchor) { _anchor = anchor; }
		std::shared_ptr<Anchor> GetAnchor() const { return _anchor; }

		virtual void Draw();

	protected:
		virtual void OnDrawGizmos();

	private:
		void Recalculate();

	private:
		std::shared_ptr<Transform> _parent;
		std::vector<std::shared_ptr<Transform>> _attached;
		RVector2 _localPosition;
		RVector2 _centerPosition;
		RVector2 _localScale;
		std::shared_ptr<Anchor> _anchor;
	};
}

#endif // _TRANSFORM_HEADER_
