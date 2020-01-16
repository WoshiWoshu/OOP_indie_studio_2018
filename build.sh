#!/usr/bin/env bash

rm bomberman 
rm unit-tests
cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" . -B ./cmake-build-debug
cmake --build ./cmake-build-debug --target all -- -j2
