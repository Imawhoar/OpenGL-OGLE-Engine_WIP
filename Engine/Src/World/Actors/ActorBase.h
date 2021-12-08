#pragma once
#include "World/Scene/Entity.h"
#include "Core/Transform.h"
#include "Utils/Utils.h"
#include "World/World.h"

namespace OGLE
{
	class ActorBase
	{

	private:
		struct TransformComponent* m_transformComponent;
		struct TagComponent* m_tagComponent;

	protected:
		class World* m_world;
		Entity m_entityHandle;

	public:
		ActorBase();
		ActorBase(World* world, const Entity& entityHandle);
		explicit ActorBase(World* world);
		virtual ~ActorBase() = default;

	public:
		virtual void BeginActor() = 0;
		virtual void TickActor(float deltaTime) = 0;

	public:

		[[nodiscard]] World* GetWorld() const;
		[[nodiscard]] Transform* GetTransform();
		[[nodiscard]] const Quaternion* GetRotation();
		[[nodiscard]] const Vector3* GetEulerRotation();
		[[nodiscard]] const Vector3* GetPosition();
		[[nodiscard]] const Vector3* GetScale();
		[[nodiscard]] std::string GetActorName();
		[[nodiscard]] float GetWorldSeconds() const;
		[[nodiscard]] float GetDeltaTime() const;

		template<typename T, typename ... Args>
		T* CreateComponent(Args ...);
		template<typename T>
		bool ComponentExists();
		template<typename T>
		void RemoveComponent();
		template<typename T>
		T* GetComponent();

		void SetRotation(const Quaternion& rot);
		void SetRotation(const Vector3& rot);
		void SetRotation(float pitch, float yaw, float roll);
		void SetRotation(float w, float x, float y, float z);

		void SetPosition(const Vector3& position);
		void SetPosition(float x, float y, float z);

		void SetScale(const Vector3& scale);
		void SetScale(float x, float y, float z);

		void AddRotation(const Quaternion& delta);
		void AddRotation(const Vector3& deltaEuler);
		void AddRotation(float deltaPitch, float deltaYaw, float deltaRoll);
		void AddRotation(float deltaW, float deltaX, float deltaY, float deltaZ);

		void AddPosition(const Vector3& position);
		void AddPosition(float x, float y, float z);

		void AddScale(const Vector3& delta);
		void AddScale(float x, float y, float z);

	};

	template <typename T, typename ... Args>
	T* ActorBase::CreateComponent(Args... args) {
		return &m_entityHandle.AddComponent<T>(std::forward<Args>(args)...);
	}
	template <typename T>
	T* ActorBase::GetComponent() {
		return &m_entityHandle.GetComponent<T>();
	}
	template <typename T>
	void ActorBase::RemoveComponent() {
		if (ComponentExists<T>())
			m_entityHandle.RemoveComponent<T>();
	}
	template <typename T>
	bool ActorBase::ComponentExists() {
		return m_entityHandle.HasComponent<T>();
	}
}
