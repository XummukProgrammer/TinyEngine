#ifndef _CONTEXT_HEADER_
#define _CONTEXT_HEADER_

#include <functional>
#include <memory>

namespace TinyEngine::Core
{
	class FileSystem;

	class Context final : public std::enable_shared_from_this<Context>
	{
	public:
		using Ptr = std::shared_ptr<Context>;
		using FileSystemPtr = std::shared_ptr<FileSystem>;
		using PreInitCallback = std::function<void(Ptr)>;
		using InitCallback = std::function<void(Ptr)>;
		using DeinitCallback = std::function<void(Ptr)>;
		using UpdateCallback = std::function<void(Ptr)>;
		using DrawCallback = std::function<void(Ptr)>;
		using EventCallback = std::function<void(Ptr)>;

	public:
		Context();
		~Context() = default;

	public:
		void SetOnPreInitCallback(const PreInitCallback& callback) { _onPreInitCallback = callback; }
		void OnPreInit();

		void SetOnInitCallback(const PreInitCallback& callback) { _onInitCallback = callback; }
		void OnInit();

		void SetOnDeinitCallback(const PreInitCallback& callback) { _onDeinitCallback = callback; }
		void OnDeinit();

		void SetOnUpdateCallback(const PreInitCallback& callback) { _onUpdateCallback = callback; }
		void OnUpdate();

		void SetOnDrawCallback(const PreInitCallback& callback) { _onDrawCallback = callback; }
		void OnDraw();

		void SetOnEventCallback(const PreInitCallback& callback) { _onEventCallback = callback; }
		void OnEvent();

		FileSystemPtr GetFileSystem() const;

	private:
		FileSystemPtr _fileSystem;

		PreInitCallback _onPreInitCallback;
		InitCallback _onInitCallback;
		DeinitCallback _onDeinitCallback;
		UpdateCallback _onUpdateCallback;
		DrawCallback _onDrawCallback;
		EventCallback _onEventCallback;
	};
}

#endif // _CONTEXT_HEADER_
