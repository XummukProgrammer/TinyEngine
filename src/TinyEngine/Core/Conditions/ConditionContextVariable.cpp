#include "ConditionVariable.hpp"

#include <TinyEngine/Core/Application.hpp>

namespace TinyEngine
{
    IConditionVariableSharedPtr ConditionContextVariable::GetVariable() const
    {
        if (!_cashedContextVariable)
        {
            if (_isGlobalContext)
            {
                const auto& globalContext = Application::GetInstance()->GetConstGlobalContext();
                _cashedContextVariable = globalContext.GetVariable(_contextVariableId);
            }
            else
            {
                // TODO: На текущий момент идёт поддержка только GlobalContext, необходимо ещё сделать локальный.
            }
        }
        return _cashedContextVariable;
    }

    bool ConditionContextVariable::IsEqual(IConditionVariable* variable) const
    {
        if (auto contextVariable = GetVariable())
        {
            return contextVariable->IsEqual(variable);
        }
        return false;
    }

    bool ConditionContextVariable::IsLess(IConditionVariable* variable) const
    {
        if (auto contextVariable = GetVariable())
        {
            return contextVariable->IsLess(variable);
        }
        return false;
    }

    bool ConditionContextVariable::IsLessOrEqual(IConditionVariable* variable) const
    {
        if (auto contextVariable = GetVariable())
        {
            return contextVariable->IsLessOrEqual(variable);
        }
        return false;
    }

    bool ConditionContextVariable::IsMore(IConditionVariable* variable) const
    {
        if (auto contextVariable = GetVariable())
        {
            return contextVariable->IsMore(variable);
        }
        return false;
    }

    bool ConditionContextVariable::IsMoreOrEqual(IConditionVariable* variable) const
    {
        if (auto contextVariable = GetVariable())
        {
            return contextVariable->IsMoreOrEqual(variable);
        }
        return false;
    }

    bool ConditionContextVariable::IsUnifiedType(IConditionVariable* variable) const
    {
        if (auto contextVariable = GetVariable())
        {
            return contextVariable->IsUnifiedType(variable);
        }
        return false;
    }
}
