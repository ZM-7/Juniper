#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Juniper {

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
			JP_TRACE("{}",e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			JP_TRACE("{}", e.ToString());
		}

		while (true);
	}
}
