prog: spaceinv.o raster.o model.o render.o events.o font.o  clear.o
	cc68x -g spaceinv.o raster.o model.o render.o events.o font.o  clear.o -o prog

spaceinv.o: spaceinv.c spaceinv.h
	cc68x -g -c spaceinv.c

raster.o: raster.c raster.h
	cc68x -g -c raster.c

render.o: render.c render.h
	cc68x -g -c render.c

model.o: model.c model.h 
	cc68x -g -c model.c

events.o: events.c events.h
	cc68x -g -c events.c

font.o: font.c font.h
	cc68x -g -c font.c 

clear.o: clear.s clear.h
	gen -D -L2 clear.s 

