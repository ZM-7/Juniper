#include "Juniper.h"

class Sandbox : public Juniper::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}


};

Juniper::Application* Juniper::CreateApplication()
{
	return new Sandbox();
}