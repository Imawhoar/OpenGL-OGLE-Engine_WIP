#pragma once

#include "Utils/Utils.h"

namespace OGLE
{
	class Transform {
		Vector3 m_position{};
		Vector3 m_scale{};
		Vector3 m_eulerRotation{};
		Quaternion m_quaternion{};

	public:


		Transform();

	public:
		void SetPosition(const Vector3& position);
		void AddPosition(const Vector3& delta);

		void SetScale(const Vector3& size);
		void AddScale(const Vector3& delta);


		void SetRotation(const Vector3& eulerRotation);
		void SetRotation(const Quaternion& rotation);

		void AddRotation(const Vector3& deltaEuler);
		void AddRotation(const Quaternion& delta);

		[[nodiscard]] const Vector3& GetPosition() const;
		[[nodiscard]] const Vector3& GetScale() const;
		[[nodiscard]] const Vector3& GetEuler() const;
		[[nodiscard]] const Quaternion& GetQuaternion() const;

		//TODO: Should probably not be static since we actually want per instance. Leave as if for now.
		static Vector3 GetRight();
		static Vector3 GetUp();
		static Vector3 GetFront();
	};
}