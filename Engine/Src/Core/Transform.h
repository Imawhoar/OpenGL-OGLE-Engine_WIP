#pragma once

#include <glm/vec3.hpp>
namespace OGLE
{
	class Transform {
		glm::vec3 m_position{};
		glm::vec3 m_scale{};
		glm::vec3 m_rotation{};

	public:
		Transform();

	public:
		const glm::vec3& GetPosition() const;
		void SetPosition(const glm::vec3& pos);
		void AddPosition(const glm::vec3& deltaPos);

		const glm::vec3& GetScale() const;
		void SetScale(const glm::vec3& scale);
		void AddScale(const glm::vec3& deltaScale);

		const glm::vec3& GetRotation() const;
		void SetRotation(const glm::vec3& rot);
		void AddRotation(const glm::vec3& deltaRot);

		glm::vec3 GetForwardVector() const;
		glm::vec3 GetRightVector() const;
		glm::vec3 GetUpVector() const;
	};
}