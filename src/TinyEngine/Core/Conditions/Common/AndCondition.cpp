#include "AndCondition.hpp"

namespace TinyEngine
{
    bool AndCondition::IsResult() const
    {
        for (const auto& condition : _conditions)
        {
            if (!condition->IsResult())
            {
                return false;
            }
        }
        return true;
    }
}
