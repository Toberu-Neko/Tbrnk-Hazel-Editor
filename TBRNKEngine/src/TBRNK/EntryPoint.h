#pragma once

#ifdef TBRNK_PLATFORM_WINDOWS

extern TBRNK::Application* TBRNK::CreateApplication();

int main(int argc, char** argv) {

	auto app = TBRNK::CreateApplication();
	app->Run();
	delete app;
}

#endif // TBRNK_PLATFORM_WINDOWS
