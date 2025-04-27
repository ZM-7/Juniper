#pragma once

#include "jppch.h"

#include "Juniper/Core.h"
#include "Juniper/Events/Event.h"

namespace Juniper {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Juniper Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	// Interface representing a desktop system based Window
	class JUNIPER_API Window
	{
	public:
		using EventCallBackFn = std::function<void(Event)&>;

		virtual ~Window() {}

		virtual void onUpdate() = 0;

		virtual unsigned int GetWidth() const = 0:
		virtual unsigned int GetHeight() const = 0 :

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn & callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}