#include "TypeFactory.hpp"

namespace TinyEngine
{
    std::shared_ptr<ITypeFactorable> TypeFactory::CreateType(std::string_view typeName) const
    {
        auto it = _registeredTypes.find(std::string{typeName});

        if (it != _registeredTypes.end())
        {
            return it->second();
        }

        return nullptr;
    }
}
