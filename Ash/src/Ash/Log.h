#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Ash {

	class ASH_API Log
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
#define AH_CORE_TRACE(...)     ::Ash::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AH_CORE_INFO(...)      ::Ash::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AH_CORE_WARN(...)      ::Ash::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AH_CORE_ERROR(...)     ::Ash::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AH_CORE_Critical(...)  ::Ash::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define AH_TRACE(...)          ::Ash::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AH_INFO(...)           ::Ash::Log::GetClientLogger()->info(__VA_ARGS__)
#define AH_WARN(...)           ::Ash::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AH_ERROR(...)          ::Ash::Log::GetClientLogger()->error(__VA_ARGS__)
#define AH_Critical(...)       ::Ash::Log::GetClientLogger()->critical(__VA_ARGS__)