#include "EditorCamera.h"
#include "Utils/Utils.h"

namespace OGLE
{
	void EditorCamera::RecalibrateProjection()
	{
		switch (m_cameraType) {
		case CameraType::PERSPECTIVE:
			m_projectionMatrix = glm::perspective(
				m_perspectiveSettings.fieldOfView,
				m_perspectiveSettings.width / m_perspectiveSettings.height,
				m_nearClip,
				m_farClip);
			break;

		case CameraType::ORTHOGRAPHIC:
			m_projectionMatrix = glm::ortho(
				m_orthographicSettings.left,
				m_orthographicSettings.right,
				m_orthographicSettings.bottom,
				m_orthographicSettings.top,
				m_nearClip,
				m_farClip);
			break;

		default: return;
		}
	}

	void EditorCamera::RecalibrateView()
	{
		m_viewMatrix = LookAt(m_transform.GetPosition(), m_transform.GetPosition() + m_transform.GetFront(), m_transform.GetUp());
	}

	CameraType EditorCamera::GetCameraType() const
	{
		return m_cameraType;
	}

	const Matrix4& EditorCamera::GetViewMatrix() const
	{
		return m_viewMatrix;
	}

	const Transform& EditorCamera::GetTransform() const
	{
		return m_transform;
	}

	Matrix4 EditorCamera::GetViewProjection() const
	{
		return m_viewMatrix * m_projectionMatrix;
	}

	void EditorCamera::SetCameraType(CameraType type)
	{
		m_cameraType = type;
	}

	void EditorCamera::SetPosition(const Vector3& pos)
	{
		m_transform.SetPosition(pos);
	}

	void EditorCamera::AddPosition(const Vector3& deltaPos)
	{
		m_transform.AddPosition(deltaPos);
	}

	void EditorCamera::SetPosition(float x, float y, float z)
	{
		m_transform.SetPosition(Vector3(x, y, z));
	}

	void EditorCamera::AddPosition(float deltaX, float deltaY, float deltaZ)
	{
		m_transform.AddPosition(Vector3(deltaX, deltaY, deltaZ));
	}

	void EditorCamera::SetRotation(const Quaternion& rot)
	{
		m_transform.SetRotation(rot);
	}

	void EditorCamera::AddRotation(const Quaternion& deltaRot)
	{
		m_transform.AddRotation(deltaRot);
	}

	void EditorCamera::SetRotation(const Vector3& rot)
	{
		m_transform.SetRotation(rot);
	}

	void EditorCamera::AddRotation(const Vector3& deltaRot)
	{
		m_transform.AddRotation(deltaRot);
	}

	void EditorCamera::SetRotation(float pitch, float yaw, float roll)
	{
		m_transform.SetRotation(Vector3(pitch, yaw, roll));
	}

	void EditorCamera::AddRotation(float deltaPitch, float deltaYaw, float deltaRoll)
	{
		m_transform.AddRotation(Vector3(deltaPitch, deltaYaw, deltaRoll));
	}

	void EditorCamera::SetPerspectiveFieldOfView(float fov)
	{
		m_perspectiveSettings.fieldOfView = fov;
	}

	void EditorCamera::SetPerspectiveWidth(float width)
	{
		m_perspectiveSettings.width = width;
	}

	void EditorCamera::SetPerspectiveHeight(float height)
	{
		m_perspectiveSettings.height = height;
	}

	void EditorCamera::SetOrthographicConstraints(float left, float right, float bottom, float top)
	{
		m_orthographicSettings = OrthographicSettings(
			left,
			right,
			bottom,
			top,
			m_orthographicSettings.size);
	}

	void EditorCamera::SetOrthographicSize(float size)
	{
		m_orthographicSettings.size = size;
	}

	void EditorCamera::SetClipInterval(float nearClip, float farClip)
	{
		nearClip = nearClip == 0 ? 0.01f : nearClip;
		m_nearClip = Math::Min(nearClip, farClip);
		m_farClip = Math::Max(nearClip, farClip);
	}


}
