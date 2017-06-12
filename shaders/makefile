tool = glslangValidator
toolOptions = -V

all: vertex.spv fragment.spv

vertex.spv: vertex.vert
	$(tool) $(toolOptions) $<
fragment.spv: fragment.frag
	$(tool) $(toolOptions) $<

