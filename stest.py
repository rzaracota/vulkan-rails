# a hypothetical pairing for scons to test a built program
from subprocess import run
from subprocess import PIPE

run(["./driver"], stdout=PIPE)
