#include "CompareCondition.hpp"

namespace TinyEngine
{
    bool CompareCondition::IsResult() const
    {
        if (_leftVariable && _rightVariable)
        {
            switch (_type)
            {
            case CompareConditionType::Equal:
                return _leftVariable->IsEqual(_rightVariable.get());

            case CompareConditionType::Less:
                return _leftVariable->IsLess(_rightVariable.get());

            case CompareConditionType::LessOrEqual:
                return _leftVariable->IsLessOrEqual(_rightVariable.get());

            case CompareConditionType::More:
                return _leftVariable->IsMore(_rightVariable.get());

            case CompareConditionType::MoreOrEqual:
                return _leftVariable->IsMoreOrEqual(_rightVariable.get());
            }
        }
        return false;
    }
}
