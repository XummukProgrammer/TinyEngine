#ifndef _TIME_HEADER_
#define _TIME_HEADER_

#include <ctime>
#include <string>

namespace TinyEngine
{
	class Time final
	{
	public:
		Time() = default;
		~Time() = default;

	public:
		time_t GetNowTime() const;
		std::string GetNowTimeString() const;
	};
}

#endif // _TIME_HEADER_
