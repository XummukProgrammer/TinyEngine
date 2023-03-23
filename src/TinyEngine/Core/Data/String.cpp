#include "String.hpp"

namespace TinyEngine
{
    String::String(std::string_view string)
    {
        Set(string);
    }

    void String::Set(std::string_view string)
    {
        _string = string;
    }

    const std::string& String::Get() const
    {
        return _string;
    }

    std::string& String::GetRef()
    {
        return _string;
    }

    const char* String::GetCChar() const
    {
        return _string.c_str();
    }

    String& String::Replace(std::string_view target, std::string_view replacement)
    {
        std::string buf;
        std::size_t pos = 0;
        std::size_t prevPos;

        buf.reserve(_string.size());

        while (true) 
        {
            prevPos = pos;
            pos = _string.find(target, pos);

            if (pos == std::string::npos)
            {
                break;
            }

            buf.append(_string, prevPos, pos - prevPos);
            buf += replacement;
            pos += target.size();
        }

        buf.append(_string, prevPos, _string.size() - prevPos);
        _string.swap(buf);

        return *this;
    }
}
