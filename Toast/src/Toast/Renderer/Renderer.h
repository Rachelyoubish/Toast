#pragma once

#include "Toast/Renderer/RenderCommand.h"

#include "Toast/Renderer/OrthographicCamera.h"
#include "Toast/Renderer/Camera.h"

namespace Toast {

	class Renderer 
	{
	public:
		static void Init();
		static void Shutdown();

		static void OnWindowResize(uint32_t width, uint32_t height);

		static void BeginScene(const Camera& camera, const DirectX::XMMATRIX& transform);
		static void EndScene();

		static void Submit(const Ref<IndexBuffer>& indexBuffer, const Ref<Shader> shader, const Ref<BufferLayout> bufferLayout, const Ref<VertexBuffer> vertexBuffer, const DirectX::XMMATRIX& transform);
		static void SubmitQuad(const DirectX::XMMATRIX& transform);

		static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

		//Stats
		struct Statistics
		{
			uint32_t DrawCalls = 0;
			uint32_t QuadCount = 0;

			uint32_t GetTotalVertexCount() { return QuadCount * 4; }
			uint32_t GetTotalIndexCount() { return QuadCount * 6; }
		};

		static Statistics GetStats();
		static void ResetStats();
	private:
		struct SceneData 
		{
			DirectX::XMMATRIX viewMatrix, projectionMatrix;
			float farClip, nearClip, gradient;
			DirectX::XMMATRIX inverseViewMatrix, inverseProjectionMatrix;
		};

		static Scope<SceneData> mSceneData;
	};
}