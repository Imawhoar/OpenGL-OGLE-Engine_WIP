#pragma once
#include "Tools/Input/InputManager.h"
namespace OGLE
{
	class PlayerObject : public ActorObject
	{
	public:
		PlayerObject(Sprite* sprite) : ActorObject(sprite) { }
	public:
		void BeginActor() override
		{
			
		}
		void TickActor(float deltaTime) override
		{
			
		}

		void InputSetupActor(Input::InputManager* manager) override
		{
			manager->Bind("walkForward", [&](float value){});
			manager->Bind("walkRightward", [&](float value){});
		}
	private:
		float m_moveSpeed;
		
	};
}
