prog: tst_rast.o raster.o 
	cc68x -g tst_rast.o raster.o -o prog

tst_rast.o: tst_rast.c 
	cc68x -g -c tst_rast.c

raster.o: raster.c raster.h
	cc68x -g -c raster.c

font.o: font.c font.h
	cc68x -g -c font.c 



