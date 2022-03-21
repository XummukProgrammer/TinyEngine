#ifndef _APPLICATION_HEADER_
#define _APPLICATION_HEADER_

#include <string>

namespace TinyEngine
{
	class Application final
	{
	public:
		Application() = default;
		~Application() = default;

	public:
		// Был совершён вход в приложение.
		void OnEntry();
		// Был совершён выход из приложения.
		void OnQuit();

	public:
		void SetName(std::string_view name) { _name = name; }
		const std::string& GetName() const { return _name; }

		void SetVersion(std::string_view version) { _version = version; }
		const std::string& GetVersion() const { return _version; }

	private:
		// Название приложения.
		std::string _name;
		// Версия приложения.
		std::string _version;
	};
}

#endif // _APPLICATION_HEADER_
