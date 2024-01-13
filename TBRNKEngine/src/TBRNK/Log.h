#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace TBRNK {

	class TBRNK_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;


	};

}

// Core log macros
#define TBRNK_CORE_TRACE(...) ::TBRNK::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TBRNK_CORE_INFO(...) ::TBRNK::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TBRNK_CORE_WARN(...) ::TBRNK::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TBRNK_CORE_ERROR(...) ::TBRNK::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TBRNK_CORE_FATAL(...) ::TBRNK::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define TBRNK_TRACE(...) ::TBRNK::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TBRNK_INFO(...) ::TBRNK::Log::GetClientLogger()->info(__VA_ARGS__)
#define TBRNK_WARN(...) ::TBRNK::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TBRNK_ERROR(...) ::TBRNK::Log::GetClientLogger()->error(__VA_ARGS__)
#define TBRNK_FATAL(...) ::TBRNK::Log::GetClientLogger()->fatal(__VA_ARGS__)
