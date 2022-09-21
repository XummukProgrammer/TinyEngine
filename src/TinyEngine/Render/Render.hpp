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
		Render& Execute();
		Render& Destroy();
		RenderLayers& GetLayers() { return _renderLayers; }

		void CreateWindow(const RenderWindowSettings& windowSettings);

	public:
		void Close();

	private:
		void Update(float deltaTime);
		void Draw();

		void OnEventReceived();

	private:
		RenderLayers _renderLayers;
	};
};

#endif // _INTERFACE_RENDER_HEADER_
