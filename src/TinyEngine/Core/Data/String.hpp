#ifndef _STRING_HEADER_
#define _STRING_HEADER_

#include <fmt/format.h>

#include <string>

namespace TinyEngine
{
	class String final
	{
	public:
		String() = default;
		String(std::string_view string);
		~String() = default;

	public:
		void Set(std::string_view string);
		const std::string& Get() const;
		std::string& GetRef();
		const char* GetCChar() const;

		String& Replace(std::string_view target, std::string_view replacement);

		template<typename ... Args>
		String& Params(Args&& ... args);

	private:
		std::string _string;
	};

	template<typename ... Args>
	String& String::Params(Args&& ... args)
	{
		_string = fmt::format(_string, std::forward<Args>(args)...);
		return *this;
	}
}

#endif // _STRING_HEADER_
