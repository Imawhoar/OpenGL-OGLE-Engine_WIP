#pragma once
#include "Core/Sprite.h"
namespace OGLE
{
	namespace Input {
		class InputManager;
	}

	class ActorObject
	{
		friend class Renderer;
	
	protected:
		Sprite* m_sprite;
		Transform m_transform;
		virtual ~ActorObject() = default;

	
	public:
		ActorObject() : m_sprite(nullptr) {};
		ActorObject(Sprite* sprite) : m_sprite(sprite){}
	public:
		[[nodiscard]] const auto& GetTransform() const { return m_transform; }

		virtual void BeginActor() = 0;
		virtual void TickActor(float deltaTime) = 0;
		virtual void InputSetupActor(OGLE::Input::InputManager* manager) = 0;
	};
}
