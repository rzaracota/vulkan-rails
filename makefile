cpp_flags = -g
c++ = g++

ld_flags = -lglfw -lvulkan

all: driver shaders

driver: main.cpp filemap.h vulkanapp.h terrain.h
	$(c++) $(cpp_flags) $(ld_flags) $< -o driver
shaders:
	make -C shaders
test:
	./driver

.PHONY: shaders all test
