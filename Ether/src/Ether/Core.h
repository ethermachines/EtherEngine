#pragma once

#ifdef ET_PLATFORM_WINDOWS
	#ifdef ET_BUILD_DLL
		#define ETHER_API __declspec(dllexport)
	#else
		#define ETHER_API __declspec(dllimport)
	#endif
#else
	#error Ether only supports Windows
#endif