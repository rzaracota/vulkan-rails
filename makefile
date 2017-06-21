cpp_flags = -g
c++ = g++

ld_flags = -lglfw -lvulkan

all: driver shaders

driver: main.cpp vulkanapp.h
	$(c++) $(cpp_flags) $(ld_flags) $< -o driver
shaders:
	make -C shaders
.PHONY: shaders all
