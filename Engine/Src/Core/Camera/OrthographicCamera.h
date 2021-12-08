#pragma once
#include "Camera.h"

namespace OGLE
{
	class OrthographicCamera : public Camera
	{
		OrthographicSettings m_settings;

	private:
		void RecalibrateProjection();

	public:
		OrthographicCamera(float left, float right, float bottom, float top, float nearClip, float farClip);
		OrthographicCamera(float nearClip, float farClip);
		OrthographicCamera();

		void SetOrthographicSize(float left, float right, float bottom, float top);
		void SetClipInterval(float nearClip, float farClip);
		void SetSize(float size);
	};
}
