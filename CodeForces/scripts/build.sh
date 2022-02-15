#!/usr/bin/env bash

g++ -Wall -Wextra -Wconversion -static -DONLINE_JUDGE -Wl,-z,stack-size=268435456 -O2 -std=c++20 $1.cpp -o $1
