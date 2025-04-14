#pragma once

#ifdef JP_PLATFORM_WINDOWS

extern Juniper::Application* Juniper::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Juniper::CreateApplication();
	app->Run();
	delete app;
}

#endif