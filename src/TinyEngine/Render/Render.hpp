﻿#ifndef _INTERFACE_RENDER_HEADER_
#define _INTERFACE_RENDER_HEADER_

#include <string>
#include <list>
#include <map>
#include <memory>

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

	class IRenderObjectBuilder
	{
	public:
		IRenderObjectBuilder() = default;
		~IRenderObjectBuilder() = default;

	public:
		virtual IRenderObjectBuilder& SetTexture(std::string_view assetId) = 0;
		virtual IRenderObjectBuilder& SetTextureRect(const Rect& rectangle) = 0;
		virtual IRenderObjectBuilder& SetPosition(const PointF& position) = 0;
		virtual IRenderObjectBuilder& SetScale(const PointF& factors) = 0;
		virtual IRenderObjectBuilder& SetRotation(float rotation) = 0;
		virtual IRenderObjectBuilder& Create() = 0;
		virtual IRenderObjectPtr GetPtr() const = 0;
	};

	class IRenderWindow
	{
	public:
		IRenderWindow() = default;
		virtual ~IRenderWindow() = default;

	public:
		virtual void Create(const RenderWindowSettings& windowSettings) = 0;
		virtual bool IsClosed() const = 0;
		virtual void Clear() = 0;
		virtual void ExtractEvents() = 0;
		virtual void Draw(IRenderObject* object) const = 0;
		virtual void Display() = 0;
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
		IRenderObjectPtr AddRenderObject(const IRenderObjectBuilder& builder);
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

	class Render final
	{
	public:
		Render() = default;
		~Render() = default;

	public:
		Render& CreateSfmlWindow(const RenderWindowSettings& windowSettings);

		Render& Execute();
		Render& Destroy();
		RenderLayers& GetLayers() { return _renderLayers; }

	private:
		void UpdateObjects(float deltaTime);
		void DrawObjects();

		void CreateWindow(IRenderWindowPtr window, const RenderWindowSettings& windowSettings);

	private:
		IRenderWindowPtr _renderWindowPtr;
		RenderLayers _renderLayers;
	};

	extern Render render;
};

#endif // _INTERFACE_RENDER_HEADER_
