#ifndef _CORE_HEADER_
#define _CORE_HEADER_

#include "Application.hpp"

namespace TinyEngine
{
	class Core final
	{
	public:
		Core() = default;
		~Core() = default;

	public:
		static Application& GetApplication() { return s_application; }

	public:
		// Запустить игровой движок.
		void Exec();

	private:
		static Application s_application;
	};
}

#endif // _CORE_HEADER_
