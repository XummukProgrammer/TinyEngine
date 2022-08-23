#ifndef _INTERFACE_RENDER_HEADER_
#define _INTERFACE_RENDER_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Data/Singleton.hpp>

#include <TinyEngine/Render/RenderLayers.hpp>

namespace TinyEngine
{
	class Render final : public Singleton<Render>
	{
	public:
		Render() = default;
		~Render() = default;

	public:
		Render& CreateSfmlWindow(const RenderWindowSettings& windowSettings);

		Render& Execute();
		Render& Destroy();
		RenderLayers& GetLayers() { return _renderLayers; }

	public:
		void Close();

	private:
		void Update(float deltaTime);
		void Draw(IRenderWindowSharedPtr window);

		void OnEventReceived();

		void CreateWindow(IRenderWindowSharedPtr window, const RenderWindowSettings& windowSettings);

	private:
		IRenderWindowSharedPtr _renderWindowPtr;
		RenderLayers _renderLayers;
	};
};

#endif // _INTERFACE_RENDER_HEADER_
