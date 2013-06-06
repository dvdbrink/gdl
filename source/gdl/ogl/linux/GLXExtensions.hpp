#ifndef POINTER_CPP_GENERATED_HEADERGLXWIN_HPP
#define POINTER_CPP_GENERATED_HEADERGLXWIN_HPP

#ifdef __glxext_h_
#error Attempt to include glx_exts after including glxext.h
#endif

#define __glxext_h_

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <GL/glx.h>
#ifdef CODEGEN_FUNCPTR
#undef CODEGEN_FUNCPTR
#endif /*CODEGEN_FUNCPTR*/
#define CODEGEN_FUNCPTR


#ifndef GL_LOAD_GEN_BASIC_OPENGL_TYPEDEFS
#define GL_LOAD_GEN_BASIC_OPENGL_TYPEDEFS

	typedef unsigned int GLenum;
	typedef unsigned char GLboolean;
	typedef unsigned int GLbitfield;
	typedef signed char GLbyte;
	typedef short GLshort;
	typedef int GLint;
	typedef int GLsizei;
	typedef unsigned char GLubyte;
	typedef unsigned short GLushort;
	typedef unsigned int GLuint;
	typedef float GLfloat;
	typedef float GLclampf;
	typedef double GLdouble;
	typedef double GLclampd;
	#define GLvoid void

#endif /*GL_LOAD_GEN_BASIC_OPENGL_TYPEDEFS*/

#ifndef GLX_ARB_get_proc_address
	typedef void (*__GLXextFuncPtr)(void);
#endif
#ifndef GLX_SGIX_video_source
	typedef XID GLXVideoSourceSGIX;
#endif
#ifndef GLX_SGIX_fbconfig
	typedef XID GLXFBConfigIDSGIX;
	typedef struct __GLXFBConfigRec *GLXFBConfigSGIX;
#endif
#ifndef GLX_SGIX_pbuffer
	typedef XID GLXPbufferSGIX;
	typedef struct {
	    int type;
	    unsigned long serial;	  /* # of last request processed by server */
	    Bool send_event;		  /* true if this came for SendEvent request */
	    Display *display;		  /* display the event was read from */
	    GLXDrawable drawable;	  /* i.d. of Drawable */
	    int event_type;		  /* GLX_DAMAGED_SGIX or GLX_SAVED_SGIX */
	    int draw_type;		  /* GLX_WINDOW_SGIX or GLX_PBUFFER_SGIX */
	    unsigned int mask;	  /* mask indicating which buffers are affected*/
	    int x, y;
	    int width, height;
	    int count;		  /* if nonzero, at least this many more */
	} GLXBufferClobberEventSGIX;
#endif
#ifndef GLX_NV_video_output
	typedef unsigned int GLXVideoDeviceNV;
#endif
#ifndef GLX_NV_video_capture
	typedef XID GLXVideoCaptureDeviceNV;
#endif
#ifndef GLEXT_64_TYPES_DEFINED
    /* This code block is duplicated in glext.h, so must be protected */
	#define GLEXT_64_TYPES_DEFINED
	/* Define int32_t, int64_t, and uint64_t types for UST/MSC */
	/* (as used in the GLX_OML_sync_control extension). */
	#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
        #include <inttypes.h>
	#elif defined(__sun__) || defined(__digital__)
        #include <inttypes.h>
		#if defined(__STDC__)
			#if defined(__arch64__) || defined(_LP64)
				typedef long int int64_t;
				typedef unsigned long int uint64_t;
				#else
				typedef long long int int64_t;
				typedef unsigned long long int uint64_t;
			#endif /* __arch64__ */
		#endif /* __STDC__ */
	#elif defined( __VMS ) || defined(__sgi)
        #include <inttypes.h>
	#elif defined(__SCO__) || defined(__USLC__)
        #include <stdint.h>
	#elif defined(__UNIXOS2__) || defined(__SOL64__)
		typedef long int int32_t;
		typedef long long int int64_t;
		typedef unsigned long long int uint64_t;
	#elif defined(_WIN32) && defined(__GNUC__)
        #include <stdint.h>
	#elif defined(_WIN32)
		typedef __int32 int32_t;
		typedef __int64 int64_t;
		typedef unsigned __int64 uint64_t;
		#else
        #include <inttypes.h>     /* Fallback option */
	#endif
#endif

namespace gdl
{
namespace glX
{
	namespace exts
	{
		class LoadTest
		{
		private:
			//Safe bool idiom. Joy!
			typedef void (LoadTest::*bool_type)() const;
			void big_long_name_that_really_doesnt_matter() const {}
			
		public:
			operator bool_type() const
			{
				return m_isLoaded ? &LoadTest::big_long_name_that_really_doesnt_matter : 0;
			}
			
			int GetNumMissing() const {return m_numMissing;}
			
			LoadTest() : m_isLoaded(false), m_numMissing(0) {}
			LoadTest(bool isLoaded, int numMissing) : m_isLoaded(isLoaded), m_numMissing(numMissing) {}
		private:
			bool m_isLoaded;
			int m_numMissing;
		};
		
		extern LoadTest var_ARB_create_context;
		extern LoadTest var_ARB_create_context_profile;
		extern LoadTest var_ARB_create_context_robustness;
		extern LoadTest var_ARB_fbconfig_float;
		extern LoadTest var_ARB_framebuffer_sRGB;
		extern LoadTest var_ARB_multisample;
		extern LoadTest var_EXT_create_context_es2_profile;
		extern LoadTest var_EXT_fbconfig_packed_float;
		extern LoadTest var_EXT_framebuffer_sRGB;
		extern LoadTest var_EXT_import_context;
		extern LoadTest var_EXT_swap_control;
		extern LoadTest var_EXT_swap_control_tear;
		
	} //namespace exts
	enum
	{
		CONTEXT_DEBUG_BIT_ARB            = 0x00000001,
		CONTEXT_FORWARD_COMPATIBLE_BIT_ARB = 0x00000002,
		CONTEXT_MAJOR_VERSION_ARB        = 0x2091,
		CONTEXT_MINOR_VERSION_ARB        = 0x2092,
		CONTEXT_FLAGS_ARB                = 0x2094,
		
		CONTEXT_CORE_PROFILE_BIT_ARB     = 0x00000001,
		CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB = 0x00000002,
		CONTEXT_PROFILE_MASK_ARB         = 0x9126,
		
		CONTEXT_ROBUST_ACCESS_BIT_ARB    = 0x00000004,
		LOSE_CONTEXT_ON_RESET_ARB        = 0x8252,
		CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB = 0x8256,
		NO_RESET_NOTIFICATION_ARB        = 0x8261,
		
		RGBA_FLOAT_TYPE_ARB              = 0x20B9,
		RGBA_FLOAT_BIT_ARB               = 0x00000004,
		
		FRAMEBUFFER_SRGB_CAPABLE_ARB     = 0x20B2,
		
		SAMPLE_BUFFERS_ARB               = 100000,
		SAMPLES_ARB                      = 100001,
		
		CONTEXT_ES2_PROFILE_BIT_EXT      = 0x00000004,
		
		RGBA_UNSIGNED_FLOAT_TYPE_EXT     = 0x20B1,
		RGBA_UNSIGNED_FLOAT_BIT_EXT      = 0x00000008,
		
		FRAMEBUFFER_SRGB_CAPABLE_EXT     = 0x20B2,
		
		SHARE_CONTEXT_EXT                = 0x800A,
		VISUAL_ID_EXT                    = 0x800B,
		SCREEN_EXT                       = 0x800C,
		
		SWAP_INTERVAL_EXT                = 0x20F1,
		MAX_SWAP_INTERVAL_EXT            = 0x20F2,
		
		LATE_SWAPS_TEAR_EXT              = 0x20F3,
		
	};
	extern GLXContext (CODEGEN_FUNCPTR *CreateContextAttribsARB)(Display *dpy, GLXFBConfig config, GLXContext share_context, Bool direct, const int *attrib_list);
	
	
	
	
	
	
	
	
	
	extern Display * (CODEGEN_FUNCPTR *GetCurrentDisplayEXT)();
	extern int (CODEGEN_FUNCPTR *QueryContextInfoEXT)(Display *dpy, GLXContext context, int attribute, int *value);
	extern GLXContextID (CODEGEN_FUNCPTR *GetContextIDEXT)(const GLXContext context);
	extern GLXContext (CODEGEN_FUNCPTR *ImportContextEXT)(Display *dpy, GLXContextID contextID);
	extern void (CODEGEN_FUNCPTR *FreeContextEXT)(Display *dpy, GLXContext context);
	
	extern void (CODEGEN_FUNCPTR *SwapIntervalEXT)(Display *dpy, GLXDrawable drawable, int interval);
	
	
	namespace sys
	{
		
		exts::LoadTest LoadFunctions(Display *display, int screen);
		
		int GetMinorVersion();
		int GetMajorVersion();
		bool IsVersionGEQ(int majorVersion, int minorVersion);
		
	} //namespace sys
} //namespace glX
}
#endif //POINTER_CPP_GENERATED_HEADERGLXWIN_HPP
