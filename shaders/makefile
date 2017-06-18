tool = glslangValidator
toolOptions = -V

all: vert.spv frag.spv

vert.spv: vertex.vert
	$(tool) $(toolOptions) $<
frag.spv: fragment.frag
	$(tool) $(toolOptions) $<
.PHONY: all
