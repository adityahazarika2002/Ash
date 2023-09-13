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
		AH_INFO("ExampleLayer::Update");
	}

	void OnEvent(Ash::Event& event) override
	{
		AH_TRACE("{0}", event);
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