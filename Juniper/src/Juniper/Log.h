#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Juniper {
	class JUNIPER_API Log
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
#define JP_CORE_TRACE(...)		::Juniper::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define JP_CORE_INFO(...)		::Juniper::Log::GetCoreLogger()->info(__VA_ARGS__)
#define JP_CORE_WARN(...)		::Juniper::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define JP_CORE_ERROR(...)		::Juniper::Log::GetCoreLogger()->error(__VA_ARGS__)
#define JP_CORE_FATAL(...)		::Juniper::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define JP_TRACE(...)			::Juniper::Log::GetClientLogger()->trace(__VA_ARGS__)
#define JP_INFO(...)			::Juniper::Log::GetClientLogger()->info(__VA_ARGS__)
#define JP_WARN(...)			::Juniper::Log::GetClientLogger()->warn(__VA_ARGS__)
#define JP_ERROR(...)			::Juniper::Log::GetClientLogger()->error(__VA_ARGS__)
#define JP_FATAL(...)			::Juniper::Log::GetClientLogger()->fatal(__VA_ARGS__)