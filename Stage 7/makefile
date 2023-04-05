prog: test.o music.o psg.o effects.o
	cc68x -g test.o music.o psg.o effects.o -o prog

test.o: test.c test.h
	cc68x -g -c test.c

music.o: music.c music.h
	cc68x -g -c music.c

psg.o: psg.c psg.h
	cc68x -g -c psg.c

effects.o: effects.c effects.h
	cc68x -g -c effects.c




