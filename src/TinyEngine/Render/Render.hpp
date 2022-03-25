#ifndef _RENDER_HEADER_
#define _RENDER_HEADER_

namespace TinyEngine
{
	class Render final
	{
	public:
		Render() = default;
		~Render() = default;

	public:
		void OnAppEntry();
		void OnAppQuit();

		void OnWindowUpdated();
		void OnWindowDrawed();
	};
}

#endif // _RENDER_HEADER_
