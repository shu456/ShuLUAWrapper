# ShuLUAWrapper
Another friendly LUA API wrapper for c++

## Requirement
- LUA 5.3.4
- C++11 Compliant Compiler

## Current Feature
- Basic Functionality for lua.
- Call LUA functions in .lua files from .cpp files

## Usage

```c++
#include "../include/ShuLUAWrapper.hpp"
```

## Current Test Cases

FunctionCallingTest.cpp

Compiled with cygwin64

g++ FunctionCallingTest.cpp -std=c++11 -L./ lua53.dll