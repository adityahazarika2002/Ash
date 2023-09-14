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
	
#ifdef AH_ENABLE_ASSERTS 
	#define AH_ASSERT(x, ...) { if(!(x)) { AH_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define AH_CORE_ASSERT(x, ...) { if(!(x)) { AH_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define AH_ASSERT(x, ...)
	#define AH_CORE_ASSERT(x, ...)
#endif
 
#define BIT(x) (1 << x)

#define AH_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)