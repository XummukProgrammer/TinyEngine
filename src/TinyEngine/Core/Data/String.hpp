#ifndef _STRING_HEADER_
#define _STRING_HEADER_

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

		void Replace(std::string_view target, std::string_view replacement);

	private:
		std::string _string;
	};
}

#endif // _STRING_HEADER_
