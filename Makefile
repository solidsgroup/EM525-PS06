#
# This is a Makefile. It provides instructions for compiling the code.
#
CC  = g++
HDR = $(shell find ./src/ -name "*.H")
SRC = $(shell find ./src/ -name "*.cpp")

#
# Entry point 1: This runs if you type
# >  make
# and produces
#    bin/main
# the optimized version of the code.
#
default: bin/main
	@echo "Done"

#
# Entry point 2: This runs if you type
# >  make debug
# and produces
#    bin/main-debug
# the debug version of the code
#
debug: bin/main-debug
	@echo "Done"

#
# Entry point 3: This downloads and renames the eigen library
# so that you don't have to install it manually
#
eigen: 
	git clone https://gitlab.com/libeigen/eigen.git
	mv eigen src/eigen3

bin/%: src/%.cpp $(HDR)
	mkdir -p bin
	$(CC) -std=c++17 $< -o $@ -I ./src -g -Wall -Wno-sign-compare -Wfatal-errors -lstdc++fs
 
