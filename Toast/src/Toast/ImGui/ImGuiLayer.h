#pragma once

#include "Toast/Core/Layer.h"

#include "Toast/Events/ApplicationEvent.h"
#include "Toast/Events/KeyEvent.h"
#include "Toast/Events/MouseEvent.h"

namespace Toast 
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void Begin();
		void End();
	};
}