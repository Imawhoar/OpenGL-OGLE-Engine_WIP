#pragma once
#include <unordered_map>
#include "TPureSingleton.h"

namespace OGLE::Template
{
	template<typename K, typename V>
	class TRegistry final : public TPureSingleton<TRegistry<K, V>>
	{
	public:

		static V&   Get    (const K& key)			    { return TRegistry::Instance()._Get(key); }
		static bool Exists (const K& key)			    { return TRegistry::Instance()._Exists(key); }
		static void Insert (const K& key, const V& val) {	     TRegistry::Instance()._Insert(key, val); }

		~TRegistry() override { m_registry.erase(m_registry.begin(), m_registry.end()); }
	protected:
		static std::unordered_map<K, V> m_registry;

	protected:
		//Internals
		V&	 _Get   (const K& key)				 { return m_registry[key]; }
		bool _Exists(const K& key)				 { return m_registry.find(key); }
		void _Insert(const K& key, const V& val) { m_registry[key] = val; }

		
	};

}