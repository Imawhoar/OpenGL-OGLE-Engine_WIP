#pragma once
#include "OEPCH.h"
namespace OGLE::Template {

	template < typename T >
	class TPureSingleton {
	public:
		static T& Instance() {
			static const URefPtr<T> instance{ new T };
			return *instance;
		}

		TPureSingleton(const TPureSingleton&) = delete;
		TPureSingleton& operator= (const TPureSingleton) = delete;

	protected:
		TPureSingleton() = default;
		virtual ~TPureSingleton() = default;
	};


}