#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Juniper/Events/ApplicationEvent.h"
#include "Juniper/Events/KeyEvent.h"


#include "Window.h"

namespace Juniper {

	class JUNIPER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		bool OnKeyPress(KeyPressedEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// to be defined in CLIENT
	Application* CreateApplication();
}
