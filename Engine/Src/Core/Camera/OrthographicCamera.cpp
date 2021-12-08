#include "OrthographicCamera.h"

namespace OGLE
{
	void OrthographicCamera::RecalibrateProjection()
	{
		m_projectionMatrix = glm::ortho(
			m_settings.left * m_settings.size,
			m_settings.right * m_settings.size,
			m_settings.bottom * m_settings.size,
			m_settings.top * m_settings.size,
			m_nearClip, m_farClip);
	}

	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top, float nearClip,
		float farClip)
	{
		m_nearClip = nearClip;
		m_farClip = farClip;
		SetClipInterval(nearClip, farClip);
		m_settings = OrthographicSettings(left, right, bottom, top, 5);
		RecalibrateProjection();
	}

	OrthographicCamera::OrthographicCamera(float nearClip, float farClip)
	{
		SetClipInterval(nearClip, farClip);
		m_settings = OrthographicSettings(-1, 1, -1, 1, 5);
		RecalibrateProjection();
	}

	OrthographicCamera::OrthographicCamera()
	{
		SetClipInterval(0.0001f, 1000.0f);
		m_settings = OrthographicSettings(-1, 1, -1, 1, 5);
		RecalibrateProjection();
	}

	void OrthographicCamera::SetOrthographicSize(float left, float right, float bottom, float top)
	{

		m_settings.left = left;
		m_settings.right = right;
		m_settings.bottom = bottom;
		m_settings.top = top;
	}

	void OrthographicCamera::SetClipInterval(float nearClip, float farClip)
	{
		m_nearClip = nearClip;
		m_farClip = farClip;
	}

	void OrthographicCamera::SetSize(float size)
	{
		m_settings.size = size;
	}
}
