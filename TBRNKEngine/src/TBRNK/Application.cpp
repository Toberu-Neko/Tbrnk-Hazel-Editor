#include "tbrnkpch.h"
#include "Application.h"

#include "TBRNK/Events/ApplicationEvent.h"
#include "TBRNK/Log.h"

namespace TBRNK {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
		//dtor
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}
