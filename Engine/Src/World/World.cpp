#include "World.h"
#include "Scene/Scene.h"
#include "World/WorldManager.h"
#include "World/DefaultWorldManager.h"
#include "type_traits"
namespace OGLE
{
	class DefaultWorldManager;

	WorldManager* World::GetMode() const
	{
		return m_worldManager;
	}

	const WorldState& World::GetState() const
	{
		return m_state;
	}

	const World::ActorList& World::GetActorList() const
	{
		return m_actorList;
	}

	Scene* World::GetScene()
	{
		return &m_scene;
	}

	const Time& World::GetWorldTime() const
	{
		return m_worldTime;
	}

	bool World::Initialize()
	{
		m_config.maxActorCapacity = -1;
		m_config.name = "Default World";

		m_worldTime = {};
		m_state = {};

		return true;
	}

	void World::Tick()
	{
		m_worldTime.Update();
		auto dt = static_cast<float>(m_worldTime.GetDeltaTime());
		//m_worldManager->Tick(dt);
	}

	void World::Begin()
	{
		if (!m_worldManager)
			SetWorldMode<DefaultWorldManager>();
		//Do some typical setup.
		m_worldManager->Begin();
	}

	void World::End() {
		//Do some typical destruction.
		m_worldManager->End();
	}


	template <typename TState>
	TState* World::GetState()
	{
		static_assert(std::is_base_of_v<WorldState, TState>);
		return static_cast<TState*>(m_state);
	}

	template <typename TWorldMode>
	void World::SetWorldMode()
	{
		static_assert(std::is_base_of_v<WorldManager, TWorldMode>);
		m_worldManager->End();

		WorldManager* mode = new TWorldMode();

		mode->Begin();
		m_worldManager = mode;
	}

	template <typename TWorldState>
	void World::SetWorldState()
	{
		if (m_worldManager) {
			m_worldManager->End();
			delete(m_worldManager);
		}
		m_worldManager = new TWorldState();
	}
}
