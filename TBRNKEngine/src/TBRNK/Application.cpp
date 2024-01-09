#include "Application.h"

#include "TBRNK/Events/ApplicationEvent.h"
#include "TBRNK/Log.h"

namespace TBRNK {

	Application::Application()
	{
		//ctor
	}

	Application::~Application()
	{
		//dtor
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		TBRNK_TRACE(e);

		while (true);
	}
}
