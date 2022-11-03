#ifndef _RENDER_LAYER_HEADER_
#define _RENDER_LAYER_HEADER_

#include <TinyEngine/Core/Forwards.hpp>

#include <list>

namespace TinyEngine
{
	class RenderLayer final
	{
	public:
		using ObjectsList = std::list<RenderObjectSharedPtr>;

	public:
		RenderLayer() = default;
		~RenderLayer() = default;

	public:
		void Update(float deltaTime);
		void Draw();

	public:
		void SetLayerId(int layerId) { _layerId = layerId; }
		int GetLayerId() const { return _layerId; }

		void AddRenderObject(RenderObjectSharedPtr object);
		void RemoveRenderObject(RenderObjectSharedPtr object);
		bool HasRenderObject(RenderObjectSharedPtr object) const;

	private:
		ObjectsList::const_iterator GetConstObjectIterator(RenderObjectSharedPtr object) const;

	private:
		ObjectsList _objects;
		int _layerId = 0;
	};
};

#endif // _RENDER_LAYER_HEADER_
