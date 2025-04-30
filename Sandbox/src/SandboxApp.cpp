#include "Juniper.h"

class ExampleLayer : public Juniper::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		JP_INFO("ExampleLayer::Update");
	}

	void OnEvent(Juniper::Event& event) override
	{
		JP_TRACE(event.ToString());
	}
};

class Sandbox : public Juniper::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushLayer(new Juniper::ImGuiLayer());
	}

	~Sandbox()
	{

	}


};

Juniper::Application* Juniper::CreateApplication()
{
	return new Sandbox();
}