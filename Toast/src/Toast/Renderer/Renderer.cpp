#include "tpch.h"
#include "Renderer.h"

#include "Platform/DirectX/DirectXShader.h"

namespace Toast {

	Renderer::SceneData* Renderer::mSceneData = new Renderer::SceneData;

	void Renderer::Init()
	{
		RenderCommand::Init();
	}

	void Renderer::OnWindowResize(uint32_t width, uint32_t height)
	{
		RenderCommand::SetViewport(0, 0, width, height);
	}

	void Renderer::BeginScene(OrthographicCamera& camera)
	{
		mSceneData->viewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::EndScene()
	{

	}

	void Renderer::Submit(const Ref<IndexBuffer>& indexBuffer, const Ref<Shader> shader, const Ref<BufferLayout> bufferLayout, const Ref<VertexBuffer> vertexBuffer, const DirectX::XMMATRIX& transform)
	{
		bufferLayout->Bind();
		vertexBuffer->Bind();
		indexBuffer->Bind();
		shader->Bind();
		std::static_pointer_cast<DirectXShader>(shader)->UploadSceneDataVSCBuffer(mSceneData->viewProjectionMatrix);
		std::static_pointer_cast<DirectXShader>(shader)->UploadObjectDataVSCBuffer(transform);

		RenderCommand::DrawIndexed(indexBuffer);
	}
}