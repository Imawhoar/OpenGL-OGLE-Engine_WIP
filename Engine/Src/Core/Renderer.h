#pragma once

#include <vector>

#include "Camera2D.h"
#include "Sprite.h"

namespace OGLE
{
	class Renderer {

	private:
		Camera2D* m_activeCamera = nullptr;
		std::vector<Sprite*> m_spriteList{};
	public:
		Renderer();
		explicit Renderer(Camera2D* camera);

	public:
		void SetActiveCamera(Camera2D* camera);

		void RemoveRenderTarget(Sprite* sprite);
		void AddRenderTarget(Sprite* sprite);

		void Render();
	};
}
