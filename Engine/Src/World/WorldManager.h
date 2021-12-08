#pragma once
#include "World.h"
#include "Actors/ActorBase.h"
namespace OGLE
{

	class WorldManager {

	private:
		RefPtr<World> m_world = nullptr;
		std::vector<ActorBase*> m_actorList = {};

	public:
		virtual ~WorldManager() = default;

		virtual void Begin() = 0;
		virtual void End() = 0;
		virtual void Tick(float delta) = 0;

		[[nodiscard]] RefPtr<World> GetWorld() const { return m_world; }
	};
}
