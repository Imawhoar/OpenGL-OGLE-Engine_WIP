#pragma once

#include "Utils/Vector.h"
namespace OGLE
{
	class Transform {
		Vector3 m_position{};
		Vector3 m_scale{};
		Vector3 m_rotation{};

	public:
		Transform() {
			m_position = {};
			m_rotation = {};
			m_scale = Vector3(1);
		}


	public:
		[[nodiscard]] const auto& GetPosition() const { return m_position; }
		void SetPosition(const Vector3& pos) { m_position = pos; }
		void AddPosition(const Vector3& deltaPos) { m_position += deltaPos; }

		[[nodiscard]] const auto& GetScale() const { return m_scale; }
		void SetScale(const Vector3& scale) { m_scale = scale; }
		void AddScale(const Vector3& deltaScale) { m_scale += deltaScale; }

		[[nodiscard]] const auto& GetRotation() const { return m_rotation; }
		void SetRotation(const Vector3& rot) { m_rotation = rot; }
		void AddRotation(const Vector3& deltaRot) { m_rotation += deltaRot; }

		//TODO: Should probably not be static since we actually want per instance. Leave as if for now.
		[[nodiscard]] static auto GetForwardVector() { return Vector3(0, 0, 1); }
		[[nodiscard]] static auto GetRightVector(){ return Vector3(1, 0, 0); }
		[[nodiscard]] static auto GetUpVector() { return Vector3(0, 1, 0); }
	};
}