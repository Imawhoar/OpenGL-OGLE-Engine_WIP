#pragma once
#include <string>

#include "entt/entt.hpp"
#include "Entity.h"
namespace OGLE
{

	
	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = std::string())
		{
			Entity entity = { m_Registry.create(), this };
			entity.AddComponent<TransformComponent>();
			auto& tag = entity.AddComponent<TagComponent>();
			tag.Tag = name.empty() ? "Entity" : name;
			return entity;
		}
		void DestroyEntity(Entity entity)
		{
			m_Registry.destroy(entity);
		}


	private:
		entt::registry m_Registry;
		uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;

		friend class Entity;
	};
}
