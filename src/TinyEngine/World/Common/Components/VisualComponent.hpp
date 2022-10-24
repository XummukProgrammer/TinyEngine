#ifndef _VISUAL_COMPONENT_HEADER_
#define _VISUAL_COMPONENT_HEADER_

#include <TinyEngine/World/Component.hpp>
#include <TinyEngine/Render/RenderObject.hpp>

namespace TinyEngine
{
	class VisualComponent final : public Component
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(VisualComponent, Component)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_layerId, "LayerID", "Layer ID");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		VisualComponent() = default;
		~VisualComponent() = default;

	public:
		void OnInit() override;
		void OnDeinit() override;

		void OnEnable() override;
		void OnDisable() override;

		void OnUpdate() override;

	public:
		PointF GetPosition() const;
		PointF GetScale() const;
		float GetRotation() const;

		void SetTexture(std::string_view assetId);
		void SetTextureRect(const Rect& rectangle);

		bool IsPointIntersects(const PointF& point) const;
		bool IsRectIntersects(const RectF& rectangle) const;

	private:
		void SetPosition(const PointF& position);
		void SetScale(const PointF& factors);
		void SetRotation(float rotation);

		void UpdateWithTransform();
		void TryUpdateLayer();

	private:
		RenderObjectSharedPtr _object;
		RenderLayerSharedPtr _layer;

		TransformComponentSharedPtr _transformComponent;

	private:
		int _layerId = 0;
		int _prevLayerId = 0;
	};
}

#endif // _VISUAL_COMPONENT_HEADER_
