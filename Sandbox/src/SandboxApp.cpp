#include <TBRNK.h>

class Sandbox : public TBRNK::Application 
{
public:
	Sandbox() {

	}

	~Sandbox() {

	}

};

TBRNK::Application* TBRNK::CreateApplication() {
	return new Sandbox();
}