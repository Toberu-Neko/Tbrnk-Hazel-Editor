#pragma once

#ifdef TBRNK_PLATFORM_WINDOWS
	#ifdef TBRNK_BUILD_DLL
		#define TBRNK_API __declspec(dllexport)
	#else
		#define TBRNK_API __declspec(dllimport)
	#endif // TBRNK_BUILD_DLL
#else
	#error TBRNK only supports Windows!
#endif // TBRNK_PLATFORM_WINDOWS

#define BIT(x) (1 << x)