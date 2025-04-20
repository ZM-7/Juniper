#pragma once

#ifdef JP_PLATFORM_WINDOWS

extern Juniper::Application* Juniper::CreateApplication();

int main(int argc, char** argv)
{
	/* temp */
	Juniper::Log::Init();
	JP_CORE_WARN("Hello Log!");
	int a = 5;
	JP_CORE_INFO("Hello! Var={0}", a);


	auto app = Juniper::CreateApplication();
	app->Run();
	delete app;
}

#endif