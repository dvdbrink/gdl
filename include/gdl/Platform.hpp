#ifndef GDL_PLATFORM_HPP
#define GDL_PLATFORM_HPP

#if defined(__linux__)
	#define GDL_PLATFORM_LINUX
#elif defined(_WIN32)
	#define GDL_PLATFORM_WINDOWS
    #ifndef WIN32_LEAN_AND_MEAN
        #define WIN32_LEAN_AND_MEAN
    #endif
    #ifndef NOMINMAX
        #define NOMINMAX
    #endif
#else
	#error "Unsupported platform."
#endif

#endif // GDL_PLATFORM_HPP
