#!/usr/bin/env bash

g++ -std=c++20 -Wshadow -Wextra -Wall -Wl,-ld_classic -Wconversion $1.cpp -o $1