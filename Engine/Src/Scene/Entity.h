#pragma once
#include "entt/entt.hpp"
#include "Scene.h"

namespace OGLE
{
	class Entity
	{
		
	public:
		bool operator==(const Entity& other) const { return m_entity == other.m_entity && m_scene == other.m_scene; }
		bool operator!=(const Entity& other) const { return !(*this == other); }
		operator bool() const { return m_entity != entt::null; }
		operator entt::entity() const { return m_entity; }
		operator uint32_t() const { return static_cast<uint32_t>(m_entity); }
	
	private:
		Scene* m_scene = nullptr;
		entt::entity m_entity{ entt::null };
	};
}