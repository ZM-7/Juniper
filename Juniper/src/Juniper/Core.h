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

#define BIT(x) (1 << x)