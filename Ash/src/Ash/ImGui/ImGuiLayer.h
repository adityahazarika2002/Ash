#pragma once

#include "Ash/Layer.h"

#include "Ash/Events/KeyEvent.h"
#include "Ash/Events/MouseEvent.h"
#include "Ash/Events/ApplicationEvent.h"



namespace Ash {

	class ASH_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
		
	private:
		float m_Time = 0.0f;

	};

}