This is just a small prototype to try out module stuff in C.

# Requirements

You only need cmake.

# Build

> mkdir build
> cd build
> cmake ..

should be enough. Then you should be able to build with either Visual Studio if you are on windows, on make if you are on linux.

# Comments

This stemmed out of a discussion about what a good "module" system should look like with nowadays C/C++ tools (given that C++ modules are not available yet).
The main ideas are :

* there is an engine module and a gameplay module
* both should be as easily redistributable as possible
* engine module should not know about gameplay module
* gameplay module should be able to use some engine functionnality

Here how it plays out in this repo :

* engine module is compiled in an executable
* gameplay module is compiled into a static library
* gameplay module has access to header files in the engine module
* engine module does NOT have access to header files in the gameplay module
* gameplay module implements the entry point defined in interface.h
* engine module give a function pointer table to the function the gameplay is allowed to use
* gameplay module does NOT have access to other functions in the engine compilation unit. This means that functions in the engine compilation unit MUST be static or should NOT be in the interface header.
