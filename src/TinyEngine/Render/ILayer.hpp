#ifndef _INTERFACE_LAYER_HEADER_
#define _INTERFACE_LAYER_HEADER_

#include <memory>
#include <string>

namespace TinyEngine::Render
{
	class ILayer
	{
	public:
		ILayer() = default;
		virtual ~ILayer() = default;

	public:
		virtual void OnInit() {}
		virtual void OnDeinit() {}

		virtual void OnUpdate() {}
		virtual void OnDraw() {}

	public:
		bool IsValid() const;

		void Remove();
		bool IsRemoved() const;

	private:
		bool _isRemoved = false;
	};
}

#endif // _INTERFACE_LAYER_HEADER_
