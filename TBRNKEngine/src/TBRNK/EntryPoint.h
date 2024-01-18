#pragma once

#ifdef TBRNK_PLATFORM_WINDOWS

extern TBRNK::Application* TBRNK::CreateApplication();

int main(int argc, char** argv) {

	TBRNK::Log::Init();
	TBRNK_CORE_WARN("Initialized Log!, this log is coming from EntryPoint.h, int main().");

	auto app = TBRNK::CreateApplication();
	app->Run();
	delete app;
}

#endif // TBRNK_PLATFORM_WINDOWS
