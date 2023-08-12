#include <Ash.h>

class Sandbox : public Ash::Application
{
public:
	Sandbox()
	{


	}

	~Sandbox()
	{


	}
};

Ash::Application* Ash::CreateApplication()
{
	return new Sandbox();
}