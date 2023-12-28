#pragma once

#include "Core.h"

namespace TBRNK {

	class TBRNK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
