#pragma once

#ifdef AH_PLATFORM_WINDOWS

extern Ash::Application* Ash::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Ash::CreateApplication();
	app->Run();
	delete app;
}

#endif