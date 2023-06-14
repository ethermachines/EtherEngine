#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Ether
{
	class ETHER_API Log
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

#define ET_CORE_TRACE(...)        Ether::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ET_CORE_INFO(...)         Ether::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ET_CORE_WARN(...)         Ether::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ET_CORE_ERROR(...)        Ether::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ET_CORE_CRITICAL(...)     Ether::Log::GetCoreLogger()->criticla(__VA_ARGS__)

#define ET_CLIENT_TRACE(...)      Ether::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ET_CLIENT_INFO(...)       Ether::Log::GetClientLogger()->info(__VA_ARGS__)
#define ET_CLIENT_WARN(...)       Ether::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ET_CLIENT_ERROR(...)      Ether::Log::GetClientLogger()->error(__VA_ARGS__)
#define ET_CLIENT_CRITICAL(...)   Ether::Log::GetClientLogger()->criticla(__VA_ARGS__)
