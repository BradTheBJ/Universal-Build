# Universal Build
<h>
This is a hobby project I'm working on, so don't expect it to work for your use case.
<div align="left">
  <img src="https://img.shields.io/github/stars/BradTheBJ/Universal-Build?style=flat-square&color=blue&label=Stars" alt="Stars">
  <img src="https://img.shields.io/github/commit-activity/t/BradTheBJ/Universal-Build?style=flat-square&color=blue&label=Total%20Commits" alt="Commits">
  <img src="https://img.shields.io/badge/license-Apache%202.0-blue?style=flat-square" alt="License: Apache 2.0">
</div>

## About
Universal Build (ub for short) is a lightweight, language-agnostic build system designed to simplify compiling, running, and automating tasks in projects of any language.  
Using a simple text-based configuration (`build.ub`), you can define commands, flags, and compilers or interpreters without being tied to a specific programming language.  

## Setup
Ub can be used for anything from small hobby projects to larger codebases. Current support is minimal, focusing on Windows, and Linux/Mac support is planned but untested.  
Additional features are planned, including improved cross-platform compatibility, more flexible command handling, and workflow automation.

## Example
Here is a very minimal example (**the current version**):

```ub
setCompiler(clang) # Set the compiler to clang
addFlags(-o -Wall example example.cpp) # Add flags to the compiler of choice
exec() # Executes <compiler> <flags>
```
To use it, install the latest interpreter from [RELEASES] and add it to your environment path.

Alternatively, you can build from source using CMake.