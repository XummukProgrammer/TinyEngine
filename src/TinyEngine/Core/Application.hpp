#ifndef _APPLICATION_HEADER_
#define _APPLICATION_HEADER_

namespace TinyEngine::Core
{
	class ApplicationDelegate
	{
	public:
		ApplicationDelegate() = default;
		virtual ~ApplicationDelegate() = default;

	public:
		virtual void OnPreInit() {}
		virtual void OnInit() {}

		virtual void OnDeinit() {}
	};

	class Application final
	{
	public:
		Application(ApplicationDelegate& delegate);
		~Application() = default;

	public:
		void Start();

	private:
		void OnPreInit();
		void OnInit();

		void OnDeinit();

		void OnExecute();

	private:
		ApplicationDelegate& _delegate;
	};
}

#endif // _APPLICATION_HEADER_
