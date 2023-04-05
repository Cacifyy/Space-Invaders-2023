/*    
Group Student Name: Jason Szeto, Ben Cacic
Student Email: jszet006@mtroyal.ca, bcaci729@mtroyal.ca
File Name: Raster.H
Instructor: Paul Pospisil
Assignment: Space Invaders - Stage 2
Recent Update: February 15th, 2023
*/

#ifndef RASTER_H
#define RASTER_H

#include "types.h"
#include "font.h"
#include "bitmap.h"



/* 
Function name: plot_pixel
Input: UINT8 *base
       int x
       int y
Output: A pixel based on X, Y coordinates
Function details: Draws a single pixel to the screen using coordinates given.
*/

void plot_pixel(UINT8 *base, int x, int y);

/* 
Function name: plot_vert_line
Input: UINT8 *base
       int x
       int y0
       int y1
Output: A line based on two points of y coordinates and x coordinates
Function details: Draws a vertical line to the screen using the coordinates given.
*/

void plot_vert_line(UINT8 *base, int x, int y0, int y1);

/* 
Function name: plot_horiz_line
Input: UINT8 *base
       int x0
       int x1
       int y
Output: A line based on two points of x coordinates and y coordinates
Function details: Draws a horizontal line to the screen using the coordinates given.
*/

void plot_horiz_line(UINT8 *base, int x0, int x1, int y);

/* 
Function name: plot_horiz_line
Input: UINT8 *base
       int x0
       int x1
       int y0
       int y1
Output: A line based on starting and end positions of the X and Y coordinates
Function details: Draws a line in any direction to the screen using the coordinates given.
*/ 

void plot_line(UINT8 *base, int x0, int x1, int y0, int y1);

/* 
Function name: draw_cannon_word
Input: UINT16 *base
       int x
       int y
      
Output: Cannon bitmap to the screen
Function details: Draws a word-aligned cannon bitmap to the screen based on the x and y coordinates given for its starting position.
*/ 

void draw_cannon_word(UINT16 *base, int x, int y);

/* 
Function name: draw_alien_begin_word
Input: UINT16 *base
       int x
       int y
      
Output: Alien bitmap to the screen
Function details: Draws a word-aligned alien bitmap to the screen based on the x and y coordinates given for its starting position.
The alien bitmap in question will be used for the 1st two rows of the armada.
*/ 

void draw_alien_begin_word(UINT16 *base, int x, int y);

/* 
Function name: draw_alien_middle_word
Input: UINT16 *base
       int x
       int y
      
Output: Alien bitmap to the screen
Function details: Draws a word-aligned alien bitmap to the screen based on the x and y coordinates given for its starting position.
The alien bitmap in question will be used for the middle two rows of the armada.
*/ 

void draw_alien_middle_word(UINT16 *base, int x, int y);

/* 
Function name: draw_alien_end_word
Input: UINT16 *base
       int x
       int y
      
Output: Alien bitmap to the screen
Function details: Draws a word-aligned alien bitmap to the screen based on the x and y coordinates given for its starting position.
The alien bitmap in question will be used for the last row of the armada.
*/ 

void draw_alien_end_word(UINT16 *base, int x, int y);

/* 
Function name:draw_laser_word
Input: UINT16 *base
       int x
       int y
      
Output: laser bitmap to the screen
Function details: Draws a word-aligned laser bitmap to the screen based on the x and y coordinates given for its starting position.
*/ 

void draw_laser_word(UINT16 *base, int x, int y);

/* 
Function name:draw_word
Input: UINT16 *base
       int x
       int y
       UINT16 ch
      
Output: 
Function details:
*/ 

void draw_word(UINT16 *base, int x, int y, UINT16 ch);

/* 
Function name: clear
Input: none
      
Output: none
Function details: helper function to clear the screen
*/ 
void clear();

/* 
Function name: disable_cursor
Input: none
      
Output: none
Function details: helper function to disable the cursor
*/ 

void disable_cursor();

#endif
