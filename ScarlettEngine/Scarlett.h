#pragma once

#ifdef _DEBUG
	#define SLT_ASSERT(x, ...) {if(!(x)) { std::cout << "Assertion Failed: " << __VA_ARGS__ << std::endl; __debugbreak(); } }
#else
	#define SLT_ASSERT(x, ...)
#endif

// Macros.
#ifdef _DEBUG
	#define DLOG(x) Log::DebugLog(x)
#else
	#define DLOG(x)
#endif

// 1 if Engine is using SDL and 0 if Engine is not.
#define SDL_API 1