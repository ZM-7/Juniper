#include "jppch.h"
#include "Application.h"

#include "Juniper/Events/ApplicationEvent.h"
#include "Juniper/Log.h"

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
