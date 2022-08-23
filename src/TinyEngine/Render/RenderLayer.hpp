#ifndef _RENDER_LAYER_HEADER_
#define _RENDER_LAYER_HEADER_

#include <TinyEngine/Core/Forwards.hpp>

#include <list>

namespace TinyEngine
{
	class RenderLayer final
	{
	public:
		using ObjectsList = std::list<IRenderObjectSharedPtr>;

	public:
		RenderLayer() = default;
		~RenderLayer() = default;

	public:
		void Update(float deltaTime);
		void Draw(IRenderWindowSharedPtr renderWindowPtr);

	public:
		void AddRenderObject(IRenderObjectSharedPtr object);
		void RemoveRenderObject(IRenderObjectSharedPtr object);
		bool HasRenderObject(IRenderObjectSharedPtr object) const;

	private:
		ObjectsList::const_iterator GetConstObjectIterator(IRenderObjectSharedPtr object) const;

	private:
		ObjectsList _objects;
	};
};

#endif // _RENDER_LAYER_HEADER_
