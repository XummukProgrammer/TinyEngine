#include "CompareCondition.hpp"

namespace TinyEngine
{
    void CompareCondition::OnInit()
    {
        auto localContext = &GetLocalContext();

        if (_leftVariable)
        {
            _leftVariable->SetLocalContext(localContext);
        }

        if (_rightVariable)
        {
            _rightVariable->SetLocalContext(localContext);
        }
    }

    bool CompareCondition::IsResult() const
    {
        if (_leftVariable && _rightVariable)
        {
            switch (_operation)
            {
            case CompareConditionOperation::Equal:
                return _leftVariable->IsEqual(_rightVariable.get());

            case CompareConditionOperation::Less:
                return _leftVariable->IsLess(_rightVariable.get());

            case CompareConditionOperation::LessOrEqual:
                return _leftVariable->IsLessOrEqual(_rightVariable.get());

            case CompareConditionOperation::More:
                return _leftVariable->IsMore(_rightVariable.get());

            case CompareConditionOperation::MoreOrEqual:
                return _leftVariable->IsMoreOrEqual(_rightVariable.get());
            }
        }
        return false;
    }
}
