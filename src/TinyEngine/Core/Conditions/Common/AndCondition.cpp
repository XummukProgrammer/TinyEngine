#include "AndCondition.hpp"

namespace TinyEngine
{
    void AndCondition::OnInit()
    {
        for (const auto& condition : _conditions)
        {
            condition->OnInit();
        }
    }

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
