#include "jppch.h"
#include "Application.h"

#include "Juniper/Events/ApplicationEvent.h"
#include "Juniper/Log.h"

#include <GLFW/glfw3.h>

namespace Juniper {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}
