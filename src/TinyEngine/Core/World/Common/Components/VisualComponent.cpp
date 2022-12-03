#include "VisualComponent.hpp"

#include <TinyEngine/Core/Render/Render.hpp>
#include <TinyEngine/Core/Render/RenderLayers.hpp>
#include <TinyEngine/Core/Render/RenderLayer.hpp>
#include <TinyEngine/Core/World/Entity.hpp>
#include <TinyEngine/Core/World/Common/Components/TransformComponent.hpp>

namespace TinyEngine
{
	void VisualComponent::OnInit()
	{
		_transformComponent = GetEntity()->GetComponent<TransformComponent>();
		if (!_transformComponent)
		{
			return;
		}

		_object = std::make_shared<RenderObject>();
		UpdateWithTransform();

		_object->SetTexture("");
		_object->SetTextureRect({ 0, 0, 32, 32 });

		_prevLayerId = -1;
		TryUpdateLayer();
	}

	void VisualComponent::OnDeinit()
	{
		if (_layer && _object)
		{
			_layer->RemoveRenderObject(_object);
			_object.reset();
		}
	}

	void VisualComponent::OnEnable()
	{
	}

	void VisualComponent::OnDisable()
	{
	}

	void VisualComponent::OnUpdate()
	{
		UpdateWithTransform();
		TryUpdateLayer();
	}

	void VisualComponent::SetPosition(const PointF& position)
	{
		if (_object)
		{
			_object->SetPosition(position);
		}
	}

	PointF VisualComponent::GetPosition() const
	{
		if (_object)
		{
			return _object->GetPosition();
		}
		return {};
	}

	void VisualComponent::SetScale(const PointF& factors)
	{
		if (_object)
		{
			_object->SetScale(factors);
		}
	}

	PointF VisualComponent::GetScale() const
	{
		if (_object)
		{
			return _object->GetScale();
		}
		return {};
	}

	void VisualComponent::SetRotation(float rotation)
	{
		if (_object)
		{
			_object->SetRotation(rotation);
		}
	}

	void VisualComponent::UpdateWithTransform()
	{
		if (!_transformComponent)
		{
			return;
		}

		SetPosition(_transformComponent->GetPosition());
		SetScale(_transformComponent->GetScale());
		SetRotation(_transformComponent->GetRotation());
	}

	void VisualComponent::TryUpdateLayer()
	{
		if (_prevLayerId != _layerId)
		{
			_prevLayerId = _layerId;

			Render::GetInstance()->ChangeObjectLayer(_object, _layerId);
		}
	}

	float VisualComponent::GetRotation() const
	{
		if (_object)
		{
			return _object->GetRotation();
		}
		return 0.0f;
	}

	void VisualComponent::SetTexture(std::string_view assetId)
	{
		if (_object)
		{
			_object->SetTexture(assetId);
		}
	}

	void VisualComponent::SetTextureRect(const Rect& rectangle)
	{
		if (_object)
		{
			_object->SetTextureRect(rectangle);
		}
	}
}
