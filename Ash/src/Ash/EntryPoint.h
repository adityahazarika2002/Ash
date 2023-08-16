#pragma once

#ifdef AH_PLATFORM_WINDOWS

extern Ash::Application* Ash::CreateApplication();

int main(int argc, char** argv)
{
	Ash::Log::Init();
	AH_CORE_WARN("Initialized Log!");
	int a = 5;
	AH_INFO("Hello! Var={0}", a);

	auto app = Ash::CreateApplication();
	app->Run();
	delete app;
}

#endif