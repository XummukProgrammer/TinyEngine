#include "Time.hpp"

#include <chrono>
#include <ctime>

namespace TinyEngine
{
    time_t Time::GetNowTime() const
    {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);
        return time;
    }

    std::string Time::GetNowTimeString() const
    {
        auto time = GetNowTime();
        auto strTime = std::ctime(&time);
        return strTime;
    }
}
