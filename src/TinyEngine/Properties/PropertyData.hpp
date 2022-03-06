#ifndef _PROPERTY_DATA_HEADER_
#define _PROPERTY_DATA_HEADER_

#include <TinyEngine/Properties/IProperty.hpp>

namespace TinyEngine::Properties
{
	template<typename T>
	class PropertyData : public IProperty
	{
	public:
		PropertyData() = default;
		virtual ~PropertyData() = default;

	public:
		void SetData(T data) { _data = data; }
		const T& GetData() const { return _data; }

	private:
		T _data;
	};
}

#endif // _PROPERTY_DATA_HEADER_
