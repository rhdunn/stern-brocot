all:	stern_brocot \
	stern_brocot_distribution.dvi \
	stern_brocot_distribution.ps  \
	stern_brocot_distribution.pdf

%.o: %.cpp
	${CC} -c --std=c++11 $< -o $@

%.dvi: %.tex
	latex $<

%.ps: %.dvi
	dvips -Ppdf -G0 $<

%.pdf: %.ps
	ps2pdf $<

stern_brocot: stern_brocot.o
	${CC} --std=c++11 -lstdc++ $< -o $@
