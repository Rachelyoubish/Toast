#pragma once

#include "tpch.h"

#include "Toast/Core.h"
#include "Toast/Events/Event.h"

#include "Toast/Renderer/GraphicsContext.h"

namespace Toast
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Toast Engine",
					unsigned int width = 1280,
					unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	//Interface for a windows window
	class TOAST_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void Start() = 0;
		virtual void End() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());

		virtual void OnResize(UINT width, UINT height) const = 0;

		virtual HWND GetNativeWindow() const = 0;
		virtual GraphicsContext* GetGraphicsContext() const = 0;
	};
}