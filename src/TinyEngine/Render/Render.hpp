#ifndef _INTERFACE_RENDER_HEADER_
#define _INTERFACE_RENDER_HEADER_

#include <string>
#include <memory>
#include <functional>

namespace TinyEngine
{
	class IRenderWindow;
	class SfmlRenderWindow;
	class IRenderObject;

	using IRenderObjectPtr = std::shared_ptr<IRenderObject>;

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
		virtual void Update(float deltaTime) = 0;
	};

	class IRenderObjectBuilder
	{
	public:
		IRenderObjectBuilder() = default;
		~IRenderObjectBuilder() = default;

	public:
		virtual IRenderObjectBuilder& SetTexture(std::string_view filePath) = 0;
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
		virtual void Update(float deltaTime) = 0;
		virtual IRenderObjectPtr AddRenderObject(const IRenderObjectBuilder& builder) = 0;
		virtual void RemoveRenderObject(IRenderObjectPtr object) = 0;
		virtual bool HasRenderObject(IRenderObjectPtr object) const = 0;
		virtual void Draw(IRenderObject* object) const = 0;
		virtual void Display() = 0;
	};

	class Render final
	{
	public:
		using IRenderWindowPtr = std::shared_ptr<IRenderWindow>;
		using InitSfmlWindowCallback = std::function<void(SfmlRenderWindow*)>;

	public:
		Render() = default;
		~Render() = default;

	public:
		Render& CreateSfmlWindow(const RenderWindowSettings& windowSettings, InitSfmlWindowCallback initCallback = {});

		Render& Execute();
		Render& Destroy();

	private:
		void CreateWindow(IRenderWindowPtr window, const RenderWindowSettings& windowSettings);

	private:
		IRenderWindowPtr _renderWindowPtr;
	};

	extern Render render;
};

#endif // _INTERFACE_RENDER_HEADER_
