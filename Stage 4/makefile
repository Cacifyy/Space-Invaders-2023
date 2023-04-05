prog: tst_rend.o raster.o render.o font.o 
	cc68x -g tst_rend.o raster.o render.o font.o -o prog

tst_rend.o: tst_rend.c 
	cc68x -g -c tst_rend.c

raster.o: raster.c raster.h
	cc68x -g -c raster.c

render.o: render.c render.h
	cc68x -g -c render.c

font.o: font.c font.h
	cc68x -g -c font.c 


