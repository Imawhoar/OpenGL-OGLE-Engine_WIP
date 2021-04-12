#pragma once

#include <vector>

#include "../Actors/ActorObject.h"
#include "../Utils/Math.h"

namespace OGLE
{
	class Renderer {

	private:
		Camera2D* m_activeCamera = nullptr;
		std::vector<ActorObject*> m_spriteList{};
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

		void RemoveRenderTarget(ActorObject* actor) {
			m_spriteList.erase(std::remove(m_spriteList.begin(), m_spriteList.end(), actor), m_spriteList.end());
		}
		void AddRenderTarget(ActorObject* actor) {
			m_spriteList.push_back(actor);

		}

		void BeginActors()
		{
			for (auto& actor : m_spriteList)
			{
				actor->BeginActor();
			}
		}
		
		void TickActors(float deltaTime)
		{
			for (auto& actor: m_spriteList)
			{
				actor->TickActor(deltaTime);
			}
		}
		void Render() {

			const auto viewMat = m_activeCamera->GetViewMatrix();
			const auto projMat = m_activeCamera->GetProjectionMatrix();

			//auto projMat = glm::perspective(50.0f, 16.0f/9, 0.01f, 100.0f);

			for (auto* target : m_spriteList)
			{
				target->m_sprite->GetShader()->Bind();
				target->m_sprite->Bind();
				Matrix4 modelMatrix(1);

				modelMatrix = Math::Matrix::Translate(modelMatrix, target->GetTransform().GetPosition());

				modelMatrix = Math::Matrix::Rotate(modelMatrix, target->GetTransform().GetRotation().x, Vector3(1, 0, 0));
				modelMatrix = Math::Matrix::Rotate(modelMatrix, target->GetTransform().GetRotation().y, Vector3(0, 1, 0));
				modelMatrix = Math::Matrix::Rotate(modelMatrix, target->GetTransform().GetRotation().y, Vector3(0, 0, 1));

				modelMatrix = Math::Matrix::Scale(modelMatrix, target->GetTransform().GetScale());

				target->m_sprite->GetShader()->SetMat4("modelMatrix", modelMatrix);
				target->m_sprite->GetShader()->SetMat4("viewMatrix", viewMat);
				target->m_sprite->GetShader()->SetMat4("projectionMatrix", projMat);

				target->m_sprite->Draw();
			}

		}
	};
}
