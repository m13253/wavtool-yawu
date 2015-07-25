wavtool-yawu
============

Yet Another Wavtool UTAU

This is a drop-in replacement for the component `wavtool.exe` of [UTAU song synthesizer](http://utau2008.web.fc2.com/).

## Building

Install [CMake](http://www.cmake.org/), at least version 3.0.

Install [MSYS2](https://msys2.github.io) on Windows or [MinGW-w64](http://mingw-w64.org/) toolchain on Linux.

Switch to the directory of `wavtool-yawu`, type:

```bash
./configure -DCMAKE_TOOLCHAIN_FILE=tools/toolchain-i686-w64-mingw32.cmake -DCMAKE_EXE_LINKER_FLAGS=-static
make
```

The resulting executable file is in `build/wavtool-yawu.exe`.

## Usage

Open your project in UTAU, Select "Project" -> "Project Property" -> "Tool 1 (append)". Choose `wavtool-yawu.exe`.

You can also use `wavtool-yawu` with [Cadencii](http://osdn.jp/projects/cadencii/) or [jCadencii](https://packages.debian.org/sid/main/jcadencii).

