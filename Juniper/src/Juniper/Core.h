#pragma once

#ifdef JP_PLATFORM_WINDOWS
	#ifdef JP_BUILD_DLL
		#define JUNIPER_API __declspec(dllexport)	
	#else
		#define JUNIPER_API __declspec(dllimport)
	#endif
#else
#error Juniper only support Windows!
#endif

#ifdef JP_ENABLED_ASSERTS
	#define JP_ASSERT(x, ...) { if(!(x)) { JP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define JP_ASSERT(x, ...) { if(!(x)) { JP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define JP_ASSERT(x, ...)
	#define JP_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define JP_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)