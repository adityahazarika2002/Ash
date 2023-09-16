#include <Ash.h>

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
		PushOverlay(new Ash::ImGuiLayer());
	}

	~Sandbox()
	{


	}
};

Ash::Application* Ash::CreateApplication()
{
	return new Sandbox();
}