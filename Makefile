all: stern_brocot

%.o: %.cpp
	${CC} -c --std=c++11 $< -o $@

stern_brocot: stern_brocot.o
	${CC} --std=c++11 -lstdc++ $< -o $@
