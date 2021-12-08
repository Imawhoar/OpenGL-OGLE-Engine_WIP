#include "ActorBase.h"

#include "World/World.h"
#include "World/Scene/Components.h"


namespace OGLE
{
	ActorBase::ActorBase() : m_world(nullptr) {
	}

	ActorBase::ActorBase(World* world, const Entity& entityHandle) : m_world(world), m_entityHandle(entityHandle)
	{
	}

	ActorBase::ActorBase(World* world) : m_world(world) {
		m_entityHandle = world->GetScene()->CreateEntity();
	}

	World* ActorBase::GetWorld() const {
		return m_world;
	}

	Transform* ActorBase::GetTransform() {
		if (!m_transformComponent)
			m_transformComponent = CreateComponent<TransformComponent>();
		return &m_transformComponent->m_transform;
	}
	const Quaternion* ActorBase::GetRotation() {
		return &GetTransform()->GetQuaternion();
	}
	const Vector3* ActorBase::GetEulerRotation() {
		return &GetTransform()->GetEuler();
	}
	const Vector3* ActorBase::GetPosition() {
		return &GetTransform()->GetPosition();
	}
	const Vector3* ActorBase::GetScale() {
		return &GetTransform()->GetScale();
	}

	std::string ActorBase::GetActorName() {
		const auto& component = m_entityHandle.GetComponent<TagComponent>();
		return component.tag;
	}

	float ActorBase::GetWorldSeconds() const {
		return GetWorld()->GetWorldTime().GetTime();
	}
	float ActorBase::GetDeltaTime() const {
		return GetWorld()->GetWorldTime().GetDeltaTime();
	}

	void ActorBase::SetRotation(const Quaternion& rot) {
		GetTransform()->SetRotation(rot);
	}

	void ActorBase::SetRotation(const Vector3& rot) {
		GetTransform()->SetRotation(rot);
	}

	void ActorBase::SetRotation(float pitch, float yaw, float roll) {
		GetTransform()->SetRotation(Vector3(pitch, yaw, roll));
	}

	void ActorBase::SetRotation(float w, float x, float y, float z) {
		GetTransform()->SetRotation(Quaternion(w, x, y, z));
	}

	void ActorBase::SetPosition(const Vector3& position) {
		GetTransform()->SetPosition(position);
	}

	void ActorBase::SetPosition(float x, float y, float z) {
		GetTransform()->SetPosition(Vector3(x, y, z));
	}

	void ActorBase::SetScale(const Vector3& scale) {
		GetTransform()->SetScale(scale);
	}

	void ActorBase::SetScale(float x, float y, float z) {
		GetTransform()->SetScale(Vector3(x, y, z));
	}

	void ActorBase::AddRotation(const Quaternion& delta) {
		GetTransform()->AddRotation(delta);
	}

	void ActorBase::AddRotation(const Vector3& deltaEuler) {
		GetTransform()->AddRotation(deltaEuler);
	}

	void ActorBase::AddRotation(float deltaPitch, float deltaYaw, float deltaRoll) {
		GetTransform()->AddRotation(Vector3(deltaPitch, deltaYaw, deltaRoll));
	}

	void ActorBase::AddRotation(float deltaW, float deltaX, float deltaY, float deltaZ) {
		GetTransform()->AddRotation(Quaternion(deltaW, deltaX, deltaY, deltaZ));
	}

	void ActorBase::AddPosition(const Vector3& position) {
		GetTransform()->AddPosition(position);
	}

	void ActorBase::AddPosition(float x, float y, float z)
	{
		GetTransform()->AddPosition(Vector3(x, y, z));
	}

	void ActorBase::AddScale(const Vector3& delta)
	{
		GetTransform()->AddScale(delta);
	}

	void ActorBase::AddScale(float x, float y, float z)
	{
		GetTransform()->AddScale(Vector3(x, y, z));
	}
}
