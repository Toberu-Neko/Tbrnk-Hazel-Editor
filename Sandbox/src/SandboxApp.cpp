#include <TBRNK.h>

class Sandbox : public TBRNK::Application 
{
public:
	Sandbox() {

	}

	~Sandbox() {

	}

};

int main() {

	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}