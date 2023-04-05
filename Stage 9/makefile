prog: raster.o model.o render.o events.o font.o splash.o music.o effects.o psg.o isr.o clear.o base.o vbl.o spaceinv.o
	cc68x -g  raster.o model.o render.o events.o font.o splash.o music.o effects.o psg.o isr.o clear.o base.o vbl.o spaceinv.o -o prog



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

splash.o: splash.c splash.h
	cc68x -g -c splash.c

music.o: music.c music.h
	cc68x -g -c music.c

psg.o: psg.c psg.h
	cc68x -g -c psg.c

effects.o:	effects.c effects.h
	cc68x -g -c effects.c 

isr.o: isr.c isr.h
	cc68x -g -c isr.c

clear.o: clear.s clear.h
	gen -D -L2 clear.s 

base.o: base.s base.h
	gen -D -L2 base.s

vbl.o: vbl.s vbl.h
	gen -D -L2 vbl.s

spaceinv.o: spaceinv.c spaceinv.h
	cc68x -g -c spaceinv.c

