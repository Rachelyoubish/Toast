#include "tpch.h"
#include "Toast/Renderer/Texture.h"

#include "Toast/Renderer/Renderer.h"
#include "Platform/DirectX/DirectXTexture.h"

namespace Toast {

	Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height, uint32_t id)
	{
		switch (RendererAPI::GetAPI())
		{
			case RendererAPI::API::None:			TOAST_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::DirectX:			return CreateRef<DirectXTexture2D>(width, height, id);
		}

		TOAST_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<Texture2D> Texture2D::Create(const std::string& path, uint32_t id)
	{
		switch (RendererAPI::GetAPI())
		{
			case RendererAPI::API::None:			TOAST_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::DirectX:			return CreateRef<DirectXTexture2D>(path, id);
		}

		TOAST_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}