#!/bin/bash

if test -d "./build/"; then
	rm -r ./build
fi

mkdir build
c++ main.cpp -o build/cpp-mock
