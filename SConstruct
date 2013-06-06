import os
import platform

# Initialize environment
if platform.system() == 'Linux':
    env = Environment()
elif platform.system() == 'Windows':
    env = Environment(ENV = os.environ, tools = ['mingw'])
else:
    print('Error: Unsupported platform (' + platform.system() + ')')
    Exit(1)

env.Append(
    BINDIR = '#build/bin',
    LIBDIR = '#build/bin',
    OBJDIR = '#build/obj',
    CPPPATH = [
        Glob('include'),
        Glob('external/include')
    ],
    CPPFLAGS = [
        '-g',
		'-std=c++11',
		'-Wall',
        '-Wextra'
    ]
)

# Build projects
projects = [
    'source/gdl/oal',
    'source/gdl/ces',
    'source/gdl/ogl',
    #'source/gdl/net',
    'source/gdl/sys',
    'source/gdl/gui'
]

if ARGUMENTS.get('examples', 0):
    projects.append('example')

for project in projects:
    SConscript(os.path.join(project, 'SConscript'), exports = ['env'])
