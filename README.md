# GameDev Library (GDL)

Note: This project is not suitable for production quality software in any way whatsoever.

## Goals

* Exercise in the C++ programming language (mainly C++11)
* Learning environment for low-level game development related systems
* To provide open source code as a reference for other beginning game developers

## Features

* Linux and Windows support
* Window and OpenGL Context creation
* OpenGL wrapper including automatic reference counting for OpenGL resources
* OpenAL wrapper
* Basic JSON parser
* Basic component-entity-system implementation
* 3D math implementations
* Basic logging solution

## Todo

* BSD/Windows sockets wrapper
* GUI system

## Installation

###### Dependencies

* OpenGL 3.3+ graphics card
* OpenGL libraries and headers
* (Linux only) OpenAL libraries

###### Compilation

Pull the code from GitHub using your favourite terminal:

    git clone https://github.com/dvdbrink/gdl.git

Build the project using the [SCons](http://scons.org) build tool:

    scons             # Build all libraries
    scons examples=1  # Build all libraries and examples
    scons -c          # Clean build files

###### Compilation has been tested with the following compilers:

* GCC 4.8.1
* MinGW 4.8.1

Note: Clang 3.2+ and GCC/MinGW 4.7.x should also work

###### Running examples

Note: (Windows only) For now you should manually copy the 'example/resource' folder into the 'build/bin' folder.

The binaries can be found in the 'build/bin' folder and should run out of the box assuming all dependencies are met.

## License

The project is licensed under the [zlib license](http://zlib.net/zlib_license.html):

```
Copyright (c) 2013 Daniel van den Brink

This software is provided 'as-is', without any express or implied warranty.  In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any source distribution.
```

## Third party libraries

[OpenAL Soft](http://kcat.strangesoft.net/openal.html), an LGPL-licensed, cross-platform, software implementation of the OpenAL 3D audio API.

[Sean Barrett's](http://nothings.org/) public domain image loading, ogg vorbis decoding and truetype rasterization libraries.
