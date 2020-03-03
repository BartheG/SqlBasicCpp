#!/bin/bash

mkdir build
cd build
cmake ..
cmake --build .
mv interactiveshell ..
cd ..
rm -rf ./build