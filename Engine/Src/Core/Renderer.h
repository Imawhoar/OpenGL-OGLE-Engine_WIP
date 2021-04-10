#pragma once

#include <vector>

#include "Camera2D.h"
#include "Sprite.h"
#include "../Utils/Math.h"

namespace OGLE
{
	class Renderer {

	private:
		Camera2D* m_activeCamera = nullptr;
		std::vector<Sprite*> m_spriteList{};
	public:
		Renderer() {
			m_activeCamera = nullptr;
			m_spriteList = {};
		}
		explicit Renderer(Camera2D* camera) {
			m_activeCamera = camera;
			m_spriteList = {};
		}


	public:
		void SetActiveCamera(Camera2D* camera) {
			m_activeCamera = camera;
		}

		void RemoveRenderTarget(Sprite* sprite) {
			m_spriteList.erase(std::remove(m_spriteList.begin(), m_spriteList.end(), sprite), m_spriteList.end());
		}
		void AddRenderTarget(Sprite* sprite) {
			m_spriteList.push_back(sprite);

		}

		void Render() {

			const auto viewMat = m_activeCamera->GetViewMatrix();
			const auto projMat = m_activeCamera->GetProjectionMatrix();

			//auto projMat = glm::perspective(50.0f, 16.0f/9, 0.01f, 100.0f);

			for (auto* target : m_spriteList)
			{
				target->GetShader()->Bind();
				target->Bind();
				Matrix4 modelMatrix(1);

				modelMatrix = Math::Matrix::Translate(modelMatrix, target->GetTransform().GetPosition());

				modelMatrix = Math::Matrix::Rotate(modelMatrix, target->GetTransform().GetRotation().x, Vector3(1, 0, 0));
				modelMatrix = Math::Matrix::Rotate(modelMatrix, target->GetTransform().GetRotation().y, Vector3(0, 1, 0));
				modelMatrix = Math::Matrix::Rotate(modelMatrix, target->GetTransform().GetRotation().y, Vector3(0, 0, 1));

				modelMatrix = Math::Matrix::Scale(modelMatrix, target->GetTransform().GetScale());

				target->GetShader()->SetMat4("modelMatrix", modelMatrix);
				target->GetShader()->SetMat4("viewMatrix", viewMat);
				target->GetShader()->SetMat4("projectionMatrix", projMat);

				target->Draw();
			}

		}
	};
}
