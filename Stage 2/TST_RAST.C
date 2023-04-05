/*    
Group Student Name: Jason Szeto, Ben Cacic
Student Email: jszet006@mtroyal.ca, bcaci729@mtroyal.ca
File Name: TST_RAST.C
Instructor: Paul Pospisil
Assignment: Space Invaders - Stage 2
Recent Update: February 15th, 2023
*/


#include <osbind.h>
#include "raster.h"
#include <linea.h>
#include <stdio.h>


/* 
Function name: main
Input: none
Output: various bitmaps that were declared
Function details: test function to see if the bitmaps output with hardcoded values as a placeholder.
*/

int main()
{
	void *base = Physbase();

	printf("\033E\033f\n");     /* blank the screen */
	linea0();

	/*plot_pixel(base, 320,300);*/
	plot_vert_line(base, 300, 100, 250);			/* works fine, wont work when trying to call another function */
	plot_horiz_line(base, 100, 300, 100 ); 		/* cannot have wrapping implementation, won't work when another function is called */
	draw_cannon_word(base, 300, 336);
	draw_alien_begin_word(base, 300, 100);
	draw_alien_middle_word(base, 300,80);
	draw_alien_end_word(base, 300, 60);
	draw_laser_word(base, 300, 128);
	
	plot_line(base,  200,  500,  100, 300);		
		
	Cnecin();	
	return 0;
}

