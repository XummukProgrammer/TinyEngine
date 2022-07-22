#ifndef _INTERFACE_RENDER_HEADER_
#define _INTERFACE_RENDER_HEADER_

#include <string>
#include <memory>

namespace TinyEngine
{
	class IRenderWindow;

	struct RenderWindowSettings
	{
		std::string title;
		int width;
		int height;
		int maxFramerate;
	};

	class IRenderObject
	{
	public:
		IRenderObject() = default;
		virtual ~IRenderObject() = default;

	public:
		virtual void Update(float deltaTime) = 0;
		virtual void Draw(const IRenderWindow* window) const = 0;
	};

	class IRenderWindow
	{
	public:
		using IRenderObjectPtr = std::shared_ptr<IRenderObject>;

	public:
		IRenderWindow() = default;
		virtual ~IRenderWindow() = default;

	public:
		virtual void Create(const RenderWindowSettings& windowSettings) = 0;
		virtual bool IsClosed() const = 0;
		virtual void Clear() = 0;
		virtual void ExtractEvents() = 0;
		virtual void Update() = 0;
		virtual void AddRenderObject(IRenderObjectPtr object) = 0;
		virtual void RemoveRenderObject(IRenderObjectPtr object) = 0;
		virtual bool HasRenderObject(IRenderObjectPtr object) = 0;
		virtual void Draw(IRenderObject* object) const = 0;
		virtual void Display() = 0;
	};

	class Render final
	{
	public:
		using IRenderWindowPtr = std::shared_ptr<IRenderWindow>;

	public:
		Render() = default;
		~Render() = default;

	public:
		Render& CreateSfmlWindow(const RenderWindowSettings& windowSettings);

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
