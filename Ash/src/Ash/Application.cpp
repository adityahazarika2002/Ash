#include "ahpch.h"
#include "Application.h"

#include "Ash/Events/ApplicationEvent.h"
#include "Ash/Log.h"

namespace Ash {

	Application::Application()
	{

	}


	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			AH_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			AH_TRACE(e);
		}

		while (true);
	}
}