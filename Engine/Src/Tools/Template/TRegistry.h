#pragma once
#include <unordered_map>
#include "TPureSingleton.h"
namespace OGLE::Template
{
	// TODO: Decide whether registry should be a singleton or instanced
	template<typename K, typename V>
	class TRegistry final : public TPureSingleton<TRegistry<K, V>>
	{
	public:

		static V& Get(const K& key) { return TRegistry::Instance().INTERAL_Get(key); }
		static bool Exists(const K& key) { return TRegistry::Instance().INTERAL_Exists(key); }
		static void Register(const K& key, const V& val) { TRegistry::Instance().INTERNAL_Register(key, val); }

		~TRegistry() override { m_registry.erase(m_registry.begin(), m_registry.end()); }


	private:
		//Internals
		[[nodiscard]] V& INTERAL_Get(const K& key) { return m_registry[key]; }
		[[nodiscard]] bool  INTERAL_Exists(const K& key) { return m_registry.find(key); }
		void INTERNAL_Register(const K& key, const V& val) { m_registry[key] = val; }
		std::unordered_map<K, V> m_registry;
	};
}
namespace OGLE::Registry
{
	template<typename T>
	using AssetRegistry = Template::TRegistry<std::string, T*>;
}