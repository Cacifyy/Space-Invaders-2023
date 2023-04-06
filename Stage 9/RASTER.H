#ifndef RASTER_H
#define RASTER_H

#include <osbind.h>

#include "types.h"
#include "font.h"
#include "splash.h"
#include "stdio.h"
#include "def.h"

void plot_pixel(UINT8 *base, int x, int y);
void plot_vert_line(UINT8 *base, int x, int y0, int y1);
void plot_horiz_line(UINT8 *base, int x0, int x1, int y);
void plot_line(UINT8 *base, int x0, int x1, int y0, int y1);
void draw_cannon_word(UINT16 *base, int x, int y);
void draw_alien_begin_word(UINT16 *base, int x, int y);
void draw_alien_middle_word(UINT16 *base, int x, int y);
void draw_alien_end_word(UINT16 *base, int x, int y);
void draw_laser_word(UINT16 *base, int x, int y);
void draw_word(UINT16 *base, int x, int y, UINT16 ch);
void draw_splash(UINT32 *base);
void clear();
void disable_cursor();

#endif
