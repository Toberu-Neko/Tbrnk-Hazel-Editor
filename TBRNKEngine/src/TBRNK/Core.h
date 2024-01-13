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

#ifdef TBRNK_ENABLE_ASSERTS
	#define TBRNK_ASSERT(x, ...) { if(!(x)) { TBRNK_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define TBRNK_CORE_ASSERT(x, ...) { if(!(x)) { TBRNK_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define TBRNK_ASSERT(x, ...)
	#define TBRNK_CORE_ASSERT(x, ...)
#endif // TBRNK_ENABLE_ASSERTS

#define BIT(x) (1 << x)