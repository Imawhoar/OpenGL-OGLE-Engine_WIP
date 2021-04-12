#pragma once
#include "../Tools/Input/InputManager.h"
namespace OGLE
{
	class PlayerObject : public ActorObject
	{
	public:
		PlayerObject(Sprite* sprite) : ActorObject(sprite){ }
		void BeginActor() override
		{
			
		}
		void TickActor(float deltaTime) override
		{
			
		}

		void InputSetup(Input::InputManager* manager) override
		{
			
			manager->Bind("walkForward", this, &PlayerObject::test);
		}
		void test(float x)
		{
			
		}
	};
}
