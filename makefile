cpp_flags = -g
c++ = g++

ld_flags = -lglfw -lvulkan

all: base_code.cpp
	$(c++) $(cpp_flags) $(ld_flags) $< -o driver
