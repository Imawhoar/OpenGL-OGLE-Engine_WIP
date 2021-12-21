#pragma once

#include <vector>
#include "oepch.h"
#include "WorldState.h"
#include "Core/Time.h"
#include "Scene/Scene.h"


namespace OGLE {

	class ActorBase;
	class WorldManager;
	class WorldState;
	class Scene;

	struct WorldConfig {
		std::string name;
		uint32 maxActorCapacity = 10000;
		bool isPhysicsEnabled = false;
		uint32 maxPhysicsActors = 100;
	};

	class World {

		using ActorList = std::vector<RefPtr<ActorBase>>;

	private:
		WorldManager* m_worldManager = nullptr;
		WorldState m_state;
		WorldConfig m_config;
		ActorList m_actorList;

		Scene m_scene;
		Time m_worldTime;

	public:
		[[nodiscard]] WorldManager* GetMode() const;
		[[nodiscard]] const WorldState& GetState() const;
		[[nodiscard]] const ActorList& GetActorList() const;
		[[nodiscard]] Scene* GetScene();
		[[nodiscard]] const Time& GetWorldTime() const;

		bool Initialize();

		void Tick();
		void Begin();
		void End();


		//TODO: This is prone to errors.
		//Should not have to specify what state sub-class I should get.
		template <typename TState>
		TState* GetState();

		template<typename TActor>
		RefPtr<TActor> CreateActor();

		template<typename TWorldMode>
		void SetWorldMode();

		template<typename TWorldState>
		void SetWorldState();
	};


}
