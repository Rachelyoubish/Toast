#pragma once

#include "Buffer.h"

namespace Toast {

	class RendererAPI 
	{
	public:
		enum class API
		{
			None = 0, DirectX = 1
		};
	
	public:
		virtual void Clear(const float clearColor[4]) = 0;
		virtual void SetRenderTargets() = 0;
		virtual void DrawIndexed(const std::shared_ptr<IndexBuffer>& indexBuffer) = 0;

		inline static API GetAPI() { return sAPI; }
	private:
		static API sAPI;
	};
}