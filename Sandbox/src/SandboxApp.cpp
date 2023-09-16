#include <Ash.h>

#include "imgui/imgui.h"

class ExampleLayer : public Ash::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Ash::Input::IsKeyPressed(AH_KEY_TAB))
			AH_TRACE("Tab key is pressed (poll)!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Ash::Event& event) override
	{
		if (event.GetEventType() == Ash::EventType::KeyPressed)
		{
			Ash::KeyPressedEvent& e = (Ash::KeyPressedEvent&)event;
			if (e.GetKeyCode() == AH_KEY_TAB)
				AH_TRACE("Tab key is pressed (event)!");
			AH_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Ash::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{


	}
};

Ash::Application* Ash::CreateApplication()
{
	return new Sandbox();
}