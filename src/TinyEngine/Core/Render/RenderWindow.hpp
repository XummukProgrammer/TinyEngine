#ifndef _INTERFACE_RENDER_WINDOW_HEADER_
#define _INTERFACE_RENDER_WINDOW_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Data/Singleton.hpp>
#include <TinyEngine/Core/Render/RenderObject.hpp>
#include <TinyEngine/Core/Render/RenderWindowSettings.hpp>

#include "raylib-cpp.hpp"

#include <functional>
#include <memory>

namespace TinyEngine
{
	class RenderWindow final : public Singleton<RenderWindow>
	{
	public:
		RenderWindow();
		~RenderWindow();

	public:
		void Create(const RenderWindowSettings& windowSettings);
		bool IsClosed() const;
		void Clear();
		void Begin();
		void End();
		void Close();

	private:
		std::unique_ptr<raylib::Window> _window;
	};
};

#endif // _INTERFACE_RENDER_WINDOW_HEADER_
