#pragma once
#include "Camera.h"
#include "Core/Transform.h"

namespace OGLE
{
	class EditorCamera : public Camera
	{
	private:
		PerspectiveSettings m_perspectiveSettings = {};
		OrthographicSettings m_orthographicSettings = {};
		CameraType m_cameraType = CameraType::ORTHOGRAPHIC;
		Matrix4 m_viewMatrix = {};
		Transform m_transform;

	private:
		void RecalibrateProjection();
		void RecalibrateView();
	public:
		EditorCamera() = default;
	public:
		[[nodiscard]] CameraType GetCameraType() const;
		[[nodiscard]] const Matrix4& GetViewMatrix() const;
		[[nodiscard]] const Transform& GetTransform() const;
		[[nodiscard]] Matrix4 GetViewProjection() const;

		void SetCameraType(CameraType type);
		void SetPosition(const Vector3& pos);
		void AddPosition(const Vector3& deltaPos);

		void SetPosition(float x, float y, float z);
		void AddPosition(float deltaX, float deltaY, float deltaZ);

		void SetRotation(const Quaternion& rot);
		void AddRotation(const Quaternion& deltaRot);
		void SetRotation(const Vector3& rot);
		void AddRotation(const Vector3& deltaRot);
		void SetRotation(float pitch, float yaw, float roll);
		void AddRotation(float deltaPitch, float deltaYaw, float deltaRoll);

		void SetPerspectiveFieldOfView(float fov);
		void SetPerspectiveWidth(float width);
		void SetPerspectiveHeight(float height);

		//Yes im creating a new object every time we set the values. Problem? :trollface:
		void SetOrthographicConstraints(float left, float right, float bottom, float top);
		void SetOrthographicSize(float size);


		void SetClipInterval(float nearClip, float farClip);
	};
}
