#include "ConditionVariable.hpp"

#include <TinyEngine/Core/Application.hpp>

namespace TinyEngine
{
    BaseConditionVariableSharedPtr ConditionContextVariable::GetVariable() const
    {
        if (!_cashedContextVariable)
        {
            ConditionContextPtr context = nullptr;

            if (_isGlobalContext)
            {
                context = &Application::GetInstance()->GetGlobalContext();
            }
            else
            {
                context = GetLocalContext();
            }

            if (context)
            {
                _cashedContextVariable = context->GetVariable(_contextVariableId);
            }
        }
        return _cashedContextVariable;
    }

    bool ConditionContextVariable::IsEqual(BaseConditionVariable* variable) const
    {
        if (auto contextVariable = GetVariable())
        {
            return contextVariable->IsEqual(variable);
        }
        return false;
    }

    bool ConditionContextVariable::IsLess(BaseConditionVariable* variable) const
    {
        if (auto contextVariable = GetVariable())
        {
            return contextVariable->IsLess(variable);
        }
        return false;
    }

    bool ConditionContextVariable::IsLessOrEqual(BaseConditionVariable* variable) const
    {
        if (auto contextVariable = GetVariable())
        {
            return contextVariable->IsLessOrEqual(variable);
        }
        return false;
    }

    bool ConditionContextVariable::IsMore(BaseConditionVariable* variable) const
    {
        if (auto contextVariable = GetVariable())
        {
            return contextVariable->IsMore(variable);
        }
        return false;
    }

    bool ConditionContextVariable::IsMoreOrEqual(BaseConditionVariable* variable) const
    {
        if (auto contextVariable = GetVariable())
        {
            return contextVariable->IsMoreOrEqual(variable);
        }
        return false;
    }

    bool ConditionContextVariable::IsUnifiedType(BaseConditionVariable* variable) const
    {
        if (auto contextVariable = GetVariable())
        {
            return contextVariable->IsUnifiedType(variable);
        }
        return false;
    }
}
