#include "OrCondition.hpp"

namespace TinyEngine
{
    bool OrCondition::IsResult() const
    {
        for (const auto& condition : _conditions)
        {
            if (condition->IsResult())
            {
                return true;
            }
        }
        return false;
    }
}
