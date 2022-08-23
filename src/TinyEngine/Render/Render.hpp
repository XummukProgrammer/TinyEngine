#ifndef _INTERFACE_RENDER_HEADER_
#define _INTERFACE_RENDER_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Constants.hpp>
#include <TinyEngine/Data/Singleton.hpp>

#include <string>
#include <list>
#include <map>
#include <memory>
#include <functional>

namespace TinyEngine
{
	struct RenderWindowSettings
	{
		RenderType renderType;
		std::string title;
		int width;
		int height;
		int maxFramerate;
	};

	struct Point
	{
		int x, y;
	};

	struct PointF
	{
		float x, y;
	};

	struct Rect
	{
		int x, y, w, h;
	};

	struct RectF
	{
		float x, y, w, h;
	};

	struct Texture
	{
		void* data;	
	};

	class IRenderObject
	{
	public:
		IRenderObject() = default;
		virtual ~IRenderObject() = default;

	public:
		virtual void SetPosition(const PointF& position) = 0;
		virtual PointF GetPosition() const = 0;

		virtual void SetScale(const PointF& factors) = 0;
		virtual PointF GetScale() const = 0;

		virtual void SetRotation(float rotation) = 0;
		virtual float GetRotation() const = 0;

		virtual void SetTexture(std::string_view assetId) = 0;
		virtual void SetTextureRect(const Rect& rectangle) = 0;

		virtual bool IsPointIntersects(const PointF& point) const = 0;
		virtual bool IsRectIntersects(const RectF& rectangle) const = 0;

	public:
		virtual void Update(float deltaTime) = 0;
	};

	class IRenderWindow
	{
	public:
		using EventReceivedCallback = std::function<void()>;

	public:
		IRenderWindow() = default;
		virtual ~IRenderWindow() = default;

	public:
		virtual void Create(const RenderWindowSettings& windowSettings) = 0;
		virtual GuiDelegateUniquePtr CreateDelegate() const = 0;
		virtual bool IsClosed() const = 0;
		virtual void Clear() = 0;
		virtual void ExtractEvents() = 0;
		virtual void Draw(IRenderObject* object) const = 0;
		virtual void Display() = 0;
		virtual void Close() = 0;

		virtual void ResetClock() = 0;
		virtual void UpdateClock() = 0;
		virtual float GetDeltaTime() const = 0;

	public:
		void SetOnEventReceived(const EventReceivedCallback& callback) { _onEventReceived = callback; }

	protected:
		void OnEventReceived() { if (_onEventReceived) _onEventReceived(); }

	private:
		EventReceivedCallback _onEventReceived;
	};

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

	class RenderLayers final
	{
	public:
		RenderLayers() = default;
		~RenderLayers() = default;

	public:
		void Update(float deltaTime);
		void Draw(IRenderWindowSharedPtr renderWindowPtr);

	public:
		void CreateLayer(int layerId);
		RenderLayerSharedPtr GetLayer(int layerId) const;
		RenderLayerSharedPtr GetOrCreateLayer(int layerId);
		void RemoveLayer(int layerId);
		bool HasLayer(int layerId) const;

	private:
		std::map<int, RenderLayerSharedPtr> _layers;
	};

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
