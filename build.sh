#!/bin/bash

# Remove the existing build directories
rm -rf build
mkdir -p build/linux build/windows

# Build the project for Linux
g++ ./main.cpp -o build/linux/RegFast
chmod +x build/linux/RegFast

# Build the project for Windows
# install mingw-w64!
x86_64-w64-mingw32-g++ ./main.cpp -o build/windows/RegFast-wd.exe

echo "Build completed for Linux, Windows."