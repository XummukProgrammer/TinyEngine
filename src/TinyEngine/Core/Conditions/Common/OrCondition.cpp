#include "OrCondition.hpp"

namespace TinyEngine
{
    void OrCondition::OnInit()
    {
        for (const auto& condition : _conditions)
        {
            condition->OnInit();
        }
    }

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
