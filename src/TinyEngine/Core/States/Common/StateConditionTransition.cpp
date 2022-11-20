#include "StateConditionTransition.hpp"

namespace TinyEngine
{
    void StateConditionTransition::OnInit()
    {
        if (_condition)
        {
            _condition->OnInit();
        }
    }

    bool StateConditionTransition::CanChangeState() const
    {
        if (_condition)
        {
            return _condition->IsResult();
        }
        return false;
    }
}
