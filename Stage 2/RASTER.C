/*    
Group Student Name: Jason Szeto, Ben Cacic
Student Email: jszet006@mtroyal.ca, bcaci729@mtroyal.ca
File Name: Raster.C
Instructor: Paul Pospisil
Assignment: Space Invaders - Stage 2
Recent Update: February 15th, 2023
*/

#include "raster.h"
#include "stdio.h"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#define BLACK 0xFF


/* Function to plot a single pixel to the frame buffer, code was taken from lecture*/
void plot_pixel(UINT8 *base, int x, int y) 
{
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
				*(base + y * 80 + (x >> 3)) |= 1 << 7 - (x & 7);
	}
}

/* Function to plot a vertical line of pixels to the frame buffer*/
void plot_vert_line(UINT8 *base, int x, int y1, int y2) 
{

	int temp;
	UINT8 move_bit;
	UINT8 *move_byte;
	move_bit = 1 << (7 - (x & 7)); /* & is more efficient then % */
	move_byte = base + y1 * 80 + (x >> 3); /* shifting is move efficient then dividing */

	if (x >= 0 && x < 640)			/* Used Tut 04 solution */
	{
		if (y1 > y2){
			temp = y1;
			y1 = y2;
			y2 = temp;
		}

		if (y1 < 0 ){	 /* Handles wrapping */		
			y1 = 0;
		}
		if (y2 > 399){
			y2 = 399;
		}

		
		for (y1 = 0; y1 <= y2; y1++)
		{
			*move_byte = move_bit;
			move_byte = move_byte + 80;
		}
	}
	return;
}
/*Function to plot a horizontal line of pixels to the frame buffer */
void plot_horiz_line(UINT8 *base, int x1, int x2, int y) 
{
	int x1_byte_start = x1 >> 3;							/* Referenced tut 04 solution */
	int x2_byte_start = x2 >> 3;
	int bit_shift_start = x1 & (7);
	int bit_shift_end = 7 - (x2 & 8);
	int i;

	
	UINT8 byte_write_start;
	UINT8 byte_write_end;
	UINT8 *move_byte;

	byte_write_start = 0xFF >> bit_shift_start;
	byte_write_end = 0xFF << bit_shift_end;
	move_byte = base + y * 80;
	


	if (x1_byte_start == x2_byte_start){
		*(move_byte + x1_byte_start) = byte_write_start & byte_write_end;
	}
	else {
		*(move_byte + x1_byte_start) = byte_write_start;
		for (i = x1_byte_start; i < x2_byte_start; i++){
			*(move_byte + i ) = 0xFF;
		}
		*(move_byte + x2_byte_start) = byte_write_end;
	}
	return;

}

/* Function to draw a general shape of pixels  to the frame buffer*/
void plot_line(UINT8 *base, int x0, int x1, int y0, int y1) /*can plot a curved/general line */ 
{
	int x, y, dx, dy, d;
	dy = y1 - y0;
	dx = x1 - x0;
	x = x0;
	y = y0;
	d = (2*dy) - dx;
	
	if(x0 < 0){
		x0 = 0;
	}
	if(x1 > 639){
		x1 = 639;
	}
	if(y0 < 0){
		y0 = 0;
	}
	if(y1 > 399){
		y1 = 399;
	}

	
	if(dx != 0){
		for (x; x <= x1; x++)
		{
			plot_pixel( base, x, y);
			
				
			if (d > 0) {
				y++;
				d = d - (2*dx);
			}
		
			d = d + (2*dy);

	
		}
	}	
		
}
/* Draws the bitmap that was created from joel's converter to the screen, 
the bitmap image that is created from the function is mentioned in the function name and the size of the bitmap as well.*/

void draw_cannon_word(UINT16 *base, int x, int y)
{
	int i;
	for (i = 0; i < 16; i++) {
		*(base + x + (y + i) * 40) = Cannon_Word[i];
	}
}

/* Draws the bitmap that was created from joel's converter to the screen, 
the bitmap image that is created from the function is mentioned in the function name and the size of the bitmap as well.*/

void draw_alien_begin_word(UINT16 *base, int x, int y)
{
	int i;
	for (i = 0; i < 16; i++) {
		*(base + x + (y + i) * 40) = Alien_Begin_Word[i];
	}
}

/* Draws the bitmap that was created from joel's converter to the screen, 
the bitmap image that is created from the function is mentioned in the function name and the size of the bitmap as well.*/

void draw_alien_middle_word(UINT16 *base, int x, int y)
{
	int i;
	for (i = 0; i < 16; i++) {
		*(base + x + (y + i) * 40) = Alien_Middle_Word[i];
	}
}


/* Draws the bitmap that was created from joel's converter to the screen, 
the bitmap image that is created from the function is mentioned in the function name and the size of the bitmap as well.*/

void draw_alien_end_word(UINT16 *base, int x, int y)
{
	int i;
	for (i = 0; i < 16; i++) {
		*(base + x + (y + i) * 40) = Alien_End_Word[i];
	}
}

/* Draws the bitmap that was created from joel's converter to the screen, 
the bitmap image that is created from the function is mentioned in the function name and the size of the bitmap as well.*/

void draw_laser_word(UINT16 *base, int x, int y)
{
	int i;
	for (i = 0; i < 16; i++){
		*(base + x + (y + i) * 40) = laser_word[i];
	}
}

void draw_word(UINT16 *base, int x, int y, UINT16 ch) 
{
	int i;
	for (i = 0; i < 16; i++) {
		*(base + x + (y + i) * 40) = font[ch + i];
	}
}

void clear()
{
	printf("\033E\033f\n");		/*clears screen, hides cursor*/
}

void disable_cursor()
{
	printf("\033f");
	fflush(stdout);
}