#!/bin/bash

# Remove the existing build
rm -rf RegFast

# Build the project
g++ ./main.cpp -o RegFast

# Make the project executable
chmod +x RegFast