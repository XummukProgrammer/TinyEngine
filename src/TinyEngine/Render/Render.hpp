#ifndef _INTERFACE_RENDER_HEADER_
#define _INTERFACE_RENDER_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Data/Singleton.hpp>

#include <TinyEngine/Render/RenderLayers.hpp>

#include <functional>

namespace TinyEngine
{
	class Render final : public Singleton<Render>
	{
	public:
		using DefaultCallback = std::function<void()>;

	public:
		Render() = default;
		~Render() = default;

	public:
		Render& Execute();
		Render& Destroy();
		RenderLayers& GetLayers() { return _renderLayers; }

		void CreateWindow(const RenderWindowSettings& windowSettings);

		void SetOnUpdateCallback(const DefaultCallback& callback) { _onUpdateCallback = callback; }

	public:
		void Close();

	private:
		void Update(float deltaTime);
		void Draw();

		void OnEventReceived();
		void OnUpdate();

	private:
		RenderLayers _renderLayers;
		DefaultCallback _onUpdateCallback;
	};
};

#endif // _INTERFACE_RENDER_HEADER_
