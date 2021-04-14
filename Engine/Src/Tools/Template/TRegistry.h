#pragma once
#include <unordered_map>
#include "TPureSingleton.h"



namespace OGLE::Template
{
	// TODO: Devide whether registry should be a singleton or instanced
	template<typename K, typename V>
	class TRegistry final : public TPureSingleton<TRegistry<K, V>>
	{
	public:

		static V& Get(const K& key) { return TRegistry::Instance().INTERAL_Get(key); }
		static bool Exists(const K& key) { return TRegistry::Instance().INTERAL_Exists(key); }
		static void Insert(const K& key, const V& val) { TRegistry::Instance().INTERAL_Insert(key, val); }

		~TRegistry() override { m_registry.erase(m_registry.begin(), m_registry.end()); }


	private:
		//Internals
		[[nodiscard]] auto& INTERAL_Get(const K& key) { return m_registry[key]; }
		[[nodiscard]] auto  INTERAL_Exists(const K& key) { return m_registry.find(key); }
					  void  INTERAL_Insert(const K& key, const V& val) { m_registry[key] = val; }
	public:
		std::unordered_map<K, V> m_registry;

	};
}
namespace OGLE::Registry
{
	template<typename T>
	using AssetRegistry = Template::TRegistry<std::string, T*>;
}