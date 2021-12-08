#include "Renderer.h"
#include "World/Scene/Scene.h"

namespace OGLE
{
	void Renderer::Render() const
	{
		//for (auto* target : actors)
		//{
		//	target->GetRect()->Bind();


		//	Matrix4 modelMatrix;

		//	auto translation = Matrix::Translate(Matrix4(1), target->GetTransform().GetPosition());
		//	auto rotation = target->GetTransform().GetQuaternion().ToMat4();
		//	auto scale = Matrix::Scale(Matrix4(1), target->GetTransform().GetScale());

		//	modelMatrix = translation * rotation * scale;

		//	/*shader.SetMat4("modelMatrix", modelMatrix);
		//	shader.SetMat4("viewMatrix", viewMat);
		//	shader.SetMat4("projectionMatrix", projMat);*/

		//	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		//}

	}

}
