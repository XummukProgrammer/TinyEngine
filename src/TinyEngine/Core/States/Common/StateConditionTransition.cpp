#include "StateConditionTransition.hpp"

namespace TinyEngine
{
    bool StateConditionTransition::CanChangeState() const
    {
        if (_condition)
        {
            return _condition->IsResult();
        }
        return false;
    }
}
