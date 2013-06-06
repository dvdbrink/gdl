#ifndef POINTER_CPP_GENERATED_HEADERWINDOWSGL_HPP
#define POINTER_CPP_GENERATED_HEADERWINDOWSGL_HPP

#ifdef __wglext_h_
#error Attempt to include auto-generated WGL header after wglext.h
#endif

#define __wglext_h_

#ifndef WIN32_LEAN_AND_MEAN
	#define WIN32_LEAN_AND_MEAN 1
#endif
#ifndef NOMINMAX
	#define NOMINMAX
#endif
#include <windows.h>

#ifdef CODEGEN_FUNCPTR
#undef CODEGEN_FUNCPTR
#endif /*CODEGEN_FUNCPTR*/
#define CODEGEN_FUNCPTR WINAPI


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

#ifndef WGL_ARB_pbuffer
	DECLARE_HANDLE(HPBUFFERARB);
#endif
#ifndef WGL_EXT_pbuffer
	DECLARE_HANDLE(HPBUFFEREXT);
#endif
#ifndef WGL_NV_present_video
	DECLARE_HANDLE(HVIDEOOUTPUTDEVICENV);
#endif
#ifndef WGL_NV_video_output
	DECLARE_HANDLE(HPVIDEODEV);
#endif
#ifndef WGL_NV_gpu_affinity
	DECLARE_HANDLE(HPGPUNV);
	DECLARE_HANDLE(HGPUNV);
	typedef struct _GPU_DEVICE {
	    DWORD  cb;
	    CHAR   DeviceName[32];
	    CHAR   DeviceString[128];
	    DWORD  Flags;
	    RECT   rcVirtualScreen;
	} GPU_DEVICE, *PGPU_DEVICE;
#endif
#ifndef WGL_NV_video_capture
	DECLARE_HANDLE(HVIDEOINPUTDEVICENV);
#endif

namespace gdl
{
namespace wgl
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
		
		extern LoadTest var_ARB_multisample;
		extern LoadTest var_ARB_extensions_string;
		extern LoadTest var_ARB_pixel_format;
		extern LoadTest var_ARB_pixel_format_float;
		extern LoadTest var_ARB_framebuffer_sRGB;
		extern LoadTest var_ARB_create_context;
		extern LoadTest var_ARB_create_context_profile;
		extern LoadTest var_ARB_create_context_robustness;
		extern LoadTest var_EXT_swap_control;
		extern LoadTest var_EXT_pixel_format_packed_float;
		extern LoadTest var_EXT_create_context_es2_profile;
		extern LoadTest var_EXT_swap_control_tear;
		extern LoadTest var_NV_swap_group;
		
	} //namespace exts
	enum
	{
		SAMPLE_BUFFERS_ARB               = 0x2041,
		SAMPLES_ARB                      = 0x2042,
		
		NUMBER_PIXEL_FORMATS_ARB         = 0x2000,
		DRAW_TO_WINDOW_ARB               = 0x2001,
		DRAW_TO_BITMAP_ARB               = 0x2002,
		ACCELERATION_ARB                 = 0x2003,
		NEED_PALETTE_ARB                 = 0x2004,
		NEED_SYSTEM_PALETTE_ARB          = 0x2005,
		SWAP_LAYER_BUFFERS_ARB           = 0x2006,
		SWAP_METHOD_ARB                  = 0x2007,
		NUMBER_OVERLAYS_ARB              = 0x2008,
		NUMBER_UNDERLAYS_ARB             = 0x2009,
		TRANSPARENT_ARB                  = 0x200A,
		TRANSPARENT_RED_VALUE_ARB        = 0x2037,
		TRANSPARENT_GREEN_VALUE_ARB      = 0x2038,
		TRANSPARENT_BLUE_VALUE_ARB       = 0x2039,
		TRANSPARENT_ALPHA_VALUE_ARB      = 0x203A,
		TRANSPARENT_INDEX_VALUE_ARB      = 0x203B,
		SHARE_DEPTH_ARB                  = 0x200C,
		SHARE_STENCIL_ARB                = 0x200D,
		SHARE_ACCUM_ARB                  = 0x200E,
		SUPPORT_GDI_ARB                  = 0x200F,
		SUPPORT_OPENGL_ARB               = 0x2010,
		DOUBLE_BUFFER_ARB                = 0x2011,
		STEREO_ARB                       = 0x2012,
		PIXEL_TYPE_ARB                   = 0x2013,
		COLOR_BITS_ARB                   = 0x2014,
		RED_BITS_ARB                     = 0x2015,
		RED_SHIFT_ARB                    = 0x2016,
		GREEN_BITS_ARB                   = 0x2017,
		GREEN_SHIFT_ARB                  = 0x2018,
		BLUE_BITS_ARB                    = 0x2019,
		BLUE_SHIFT_ARB                   = 0x201A,
		ALPHA_BITS_ARB                   = 0x201B,
		ALPHA_SHIFT_ARB                  = 0x201C,
		ACCUM_BITS_ARB                   = 0x201D,
		ACCUM_RED_BITS_ARB               = 0x201E,
		ACCUM_GREEN_BITS_ARB             = 0x201F,
		ACCUM_BLUE_BITS_ARB              = 0x2020,
		ACCUM_ALPHA_BITS_ARB             = 0x2021,
		DEPTH_BITS_ARB                   = 0x2022,
		STENCIL_BITS_ARB                 = 0x2023,
		AUX_BUFFERS_ARB                  = 0x2024,
		NO_ACCELERATION_ARB              = 0x2025,
		GENERIC_ACCELERATION_ARB         = 0x2026,
		FULL_ACCELERATION_ARB            = 0x2027,
		SWAP_EXCHANGE_ARB                = 0x2028,
		SWAP_COPY_ARB                    = 0x2029,
		SWAP_UNDEFINED_ARB               = 0x202A,
		TYPE_RGBA_ARB                    = 0x202B,
		TYPE_COLORINDEX_ARB              = 0x202C,
		
		TYPE_RGBA_FLOAT_ARB              = 0x21A0,
		
		FRAMEBUFFER_SRGB_CAPABLE_ARB     = 0x20A9,
		
		CONTEXT_DEBUG_BIT_ARB            = 0x00000001,
		CONTEXT_FORWARD_COMPATIBLE_BIT_ARB = 0x00000002,
		CONTEXT_MAJOR_VERSION_ARB        = 0x2091,
		CONTEXT_MINOR_VERSION_ARB        = 0x2092,
		CONTEXT_LAYER_PLANE_ARB          = 0x2093,
		CONTEXT_FLAGS_ARB                = 0x2094,
		ERROR_INVALID_VERSION_ARB        = 0x2095,
		
		CONTEXT_PROFILE_MASK_ARB         = 0x9126,
		CONTEXT_CORE_PROFILE_BIT_ARB     = 0x00000001,
		CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB = 0x00000002,
		ERROR_INVALID_PROFILE_ARB        = 0x2096,
		
		CONTEXT_ROBUST_ACCESS_BIT_ARB    = 0x00000004,
		LOSE_CONTEXT_ON_RESET_ARB        = 0x8252,
		CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB = 0x8256,
		NO_RESET_NOTIFICATION_ARB        = 0x8261,
		
		TYPE_RGBA_UNSIGNED_FLOAT_EXT     = 0x20A8,
		
		CONTEXT_ES2_PROFILE_BIT_EXT      = 0x00000004,
		
	};
	
	extern const char * (CODEGEN_FUNCPTR *GetExtensionsStringARB)(HDC hdc);
	
	extern BOOL (CODEGEN_FUNCPTR *GetPixelFormatAttribivARB)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues);
	extern BOOL (CODEGEN_FUNCPTR *GetPixelFormatAttribfvARB)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, FLOAT *pfValues);
	extern BOOL (CODEGEN_FUNCPTR *ChoosePixelFormatARB)(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
	
	
	
	extern HGLRC (CODEGEN_FUNCPTR *CreateContextAttribsARB)(HDC hDC, HGLRC hShareContext, const int *attribList);
	
	
	
	extern BOOL (CODEGEN_FUNCPTR *SwapIntervalEXT)(int interval);
	extern int (CODEGEN_FUNCPTR *GetSwapIntervalEXT)();
	
	
	
	
	extern BOOL (CODEGEN_FUNCPTR *JoinSwapGroupNV)(HDC hDC, GLuint group);
	extern BOOL (CODEGEN_FUNCPTR *BindSwapBarrierNV)(GLuint group, GLuint barrier);
	extern BOOL (CODEGEN_FUNCPTR *QuerySwapGroupNV)(HDC hDC, GLuint *group, GLuint *barrier);
	extern BOOL (CODEGEN_FUNCPTR *QueryMaxSwapGroupsNV)(HDC hDC, GLuint *maxGroups, GLuint *maxBarriers);
	extern BOOL (CODEGEN_FUNCPTR *QueryFrameCountNV)(HDC hDC, GLuint *count);
	extern BOOL (CODEGEN_FUNCPTR *ResetFrameCountNV)(HDC hDC);
	
	namespace sys
	{
		
		exts::LoadTest LoadFunctions(HDC hdc);
		
		int GetMinorVersion();
		int GetMajorVersion();
		bool IsVersionGEQ(int majorVersion, int minorVersion);
		
	} //namespace sys
} //namespace wgl
}
#endif //POINTER_CPP_GENERATED_HEADERWINDOWSGL_HPP
