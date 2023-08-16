#pragma once

#ifdef AH_PLATFORM_WINDOWS
	#ifdef AH_BUILD_DLL
		#define ASH_API __declspec(dllexport)
	#else
		#define ASH_API __declspec(dllimport)
	#endif
#else
	#error Ash only supports Windows!
#endif
	
#define BIT(x) (1 << x)