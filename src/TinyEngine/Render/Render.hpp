#ifndef _INTERFACE_RENDER_HEADER_
#define _INTERFACE_RENDER_HEADER_

#include <TinyEngine/Gui/Gui.hpp>
#include <TinyEngine/Data/Singleton.hpp>

#include <string>
#include <list>
#include <map>
#include <memory>
#include <functional>

namespace TinyEngine
{
	class IRenderWindow;
	class SfmlRenderWindow;
	class IRenderObject;
	class RenderLayer;

	using IRenderObjectPtr = std::shared_ptr<IRenderObject>;
	using IRenderWindowPtr = std::shared_ptr<IRenderWindow>;
	using RenderLayerPtr = std::shared_ptr<RenderLayer>;

	struct RenderWindowSettings
	{
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

	class RenderObjectBuilder
	{
	public:
		RenderObjectBuilder() = default;
		~RenderObjectBuilder() = default;

	public:
		RenderObjectBuilder& SetTexture(std::string_view assetId);
		RenderObjectBuilder& SetTextureRect(const Rect& rectangle);
		RenderObjectBuilder& SetPosition(const PointF& position);
		RenderObjectBuilder& SetScale(const PointF& factors);
		RenderObjectBuilder& SetRotation(float rotation);
		virtual RenderObjectBuilder& Create() = 0;
		virtual IRenderObjectPtr GetPtr() const = 0;
		RenderObjectBuilder& SetToLayer(int layerId);

	protected:
		std::string _textureAssetId;
		Rect _rectangle { 0, 0, 32, 32 };
		PointF _position { 0, 0 };
		PointF _factors { 1.f, 1.f };
		float _rotation = 0;
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
		virtual GuiDelegatePtr CreateDelegate() const = 0;
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
		using ObjectsList = std::list<IRenderObjectPtr>;

	public:
		RenderLayer() = default;
		~RenderLayer() = default;

	public:
		void Update(float deltaTime);
		void Draw(IRenderWindowPtr renderWindowPtr);

	public:
		void AddRenderObject(IRenderObjectPtr object);
		void RemoveRenderObject(IRenderObjectPtr object);
		bool HasRenderObject(IRenderObjectPtr object) const;

	private:
		ObjectsList::const_iterator GetConstObjectIterator(IRenderObjectPtr object) const;

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
		void Draw(IRenderWindowPtr renderWindowPtr);

	public:
		void CreateLayer(int layerId);
		RenderLayerPtr GetLayer(int layerId) const;
		RenderLayerPtr GetOrCreateLayer(int layerId);
		void RemoveLayer(int layerId);
		bool HasLayer(int layerId) const;

	private:
		std::map<int, RenderLayerPtr> _layers;
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
		void Draw(IRenderWindowPtr window);

		void OnEventReceived();

		void CreateWindow(IRenderWindowPtr window, const RenderWindowSettings& windowSettings);

	private:
		IRenderWindowPtr _renderWindowPtr;
		RenderLayers _renderLayers;
	};
};

#endif // _INTERFACE_RENDER_HEADER_
