#pragma once

#include "Toast/Renderer/RendererAPI.h"

namespace Toast {

	class RenderCommand 
	{
	public:
		inline static void Init()
		{
			sRendererAPI->Init();
		}

		inline static void Clear(const float clearColor[4])
		{
			sRendererAPI->Clear(clearColor);
		}

		inline static void SetRenderTargets() 
		{
			sRendererAPI->SetRenderTargets();
		}

		inline static void DrawIndexed(const Ref<IndexBuffer>& indexBuffer, uint32_t count = 0)
		{
			sRendererAPI->DrawIndexed(indexBuffer, count);
		}

		inline static void SwapBuffers()
		{
			sRendererAPI->SwapBuffers();
		}

		inline static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
		{
			sRendererAPI->SetViewport(x, y, width, height);
		}

		inline static void CleanUp()
		{
			sRendererAPI->CleanUp();
		}

	public:
		static Scope<RendererAPI> sRendererAPI;
	};
}