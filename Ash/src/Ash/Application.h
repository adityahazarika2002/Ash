#pragma once

#include "Core.h"

namespace Ash {

	class ASH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}